#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

using boost::asio::ip::tcp;

class http_connection
  : public boost::enable_shared_from_this<http_connection>
{
public:
  http_connection(boost::asio::io_service& io_service)
    : socket_(io_service)
  {
  }

  tcp::socket& socket()
  {
    return socket_;
  }

  void start()
  {
    message_ = "HTTP/1.0 200 OK\r\nContent-Length: 11\r\n\r\nHello World";

    boost::asio::async_write(socket_,
        boost::asio::buffer(message_),
        boost::bind(&http_connection::handle_write, shared_from_this(),
          boost::asio::placeholders::error));
  }

private:
  void handle_write(const boost::system::error_code& error)
  {
    socket_.close();
  }

  tcp::socket socket_;
  std::string message_;
};

typedef boost::shared_ptr<http_connection> http_connection_ptr;

class http_server
{
public:
  http_server(boost::asio::io_service& io_service)
    : io_service_(io_service),
      acceptor_(io_service, tcp::endpoint(tcp::v4(), 8080))
  {
    start_accept();
  }

private:
  void start_accept()
  {
    http_connection_ptr new_connection(new http_connection(io_service_));
    acceptor_.async_accept(new_connection->socket(),
        boost::bind(&http_server::handle_accept, this, new_connection,
          boost::asio::placeholders::error));
  }

  void handle_accept(http_connection_ptr connection,
      const boost::system::error_code& error)
  {
    if (!error)
      connection->start();

    start_accept();
  }

  boost::asio::io_service& io_service_;
  tcp::acceptor acceptor_;
};

int main()
{
  try
  {
    boost::asio::io_service io_service;
    http_server server(io_service);
    io_service.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
