#include <iostream>

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


int example()
{
    double a = 3.0;
    double b = 2.0;
    double c = 1.0;

    double d = (a + b) * c;
    double e = a * (b + c);
    double f = (a + b) / c;
    double g = (a * b) + c;

    return 0;
}

// function to print out a vector
template<typename T>
void print(const std::vector<T>& v)
{
    for (const auto& x : v)
        std::cout << x << ' ';
    std::cout << '\n';
}

// function to print out a pair
template<typename T1, typename T2>
void print(const std::pair<T1,T2>& p)
{
    std::cout << p.first << ' ' << p.second << '\n';
}

// function to print out a map
template<typename K, typename V>
void print(const std::map<K,V>& m)
{
    for (const auto& x : m)
        print(x);
}

// function to print out a set
template<typename T>
void print(const std::set<T>& s)
{
    for (const auto& x : s)
        std::cout << x << ' ';
    std::cout << '\n';
}

// function to split a string
std::vector<std::string> split(const std::string& s, char delim)
{
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
        elems.push_back(item);
    return elems;
}

// function to trim a string
std::string trim(const std::string& s)
{
    auto wsfront = s.begin();
    while (wsfront != s.end() && std::isspace(*wsfront))
        ++wsfront;
    auto wsback = s.end();
    while (wsback != wsfront && std::isspace(*--wsback))
        ;
    return std::string(wsfront, wsback);
}

// function to lowercase a string
std::string tolower(const std::string& s)
{
    std::string result;
    for (const auto& c : s)
        result += std::tolower(c);
    return result;
}

// function to uppercase a string
std::string toupper(const std::string& s)
{
    std::string result;
    for (const auto& c : s)
        result += std::toupper(c);
    return result;
}


// class to print out a vector
template<typename T>
struct Printer
{
    void operator()(const std::vector<T>& v) const
    {
        for (const auto& x : v)
            std::cout << x << ' ';
        std::cout << '\n';
    }
};

// class to print out a pair
template<typename T1, typename T2>
struct PairPrinter
{
    void operator()(const std::pair<T1,T2>& p) const
    {
        std::cout << p.first << ' ' << p.second << '\n';
    }
};

// class to print out a map
template<typename K, typename V>
struct MapPrinter
{
    void operator()(const std::map<K,V>& m) const
    {
        for (const auto& x : m)
            PairPrinter<K,V>()(x);
    }
};

// class to print out a set
template<typename T>
struct SetPrinter
{
    void operator()(const std::set<T>& s) const
    {
        for (const auto& x : s)
            std::cout << x << ' ';
        std::cout << '\n';
    }
};

// Matrix class
template<typename T>
class Matrix
{
    size_t rows;
    size_t cols;
    std::vector<T> data;

public:
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows * cols)
    {
    }

    size_t getRows() const
    {
        return rows;
    }

    size_t getCols() const
    {
        return cols;
    }

    T& operator()(size_t row, size_t col)
    {
        return data[row * cols + col];
    }

    const T& operator()(size_t row, size_t col) const
    {
        return data[row * cols + col];
    }

    Matrix<T> operator+(const Matrix<T>& other) const
    {
        assert(rows == other.rows);
        assert(cols == other.cols);
        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result(i, j) = (*this)(i, j) + other(i, j);
        return result;
    }
};

int main()
{
    int a = 5;
    int b = 3;

    std::cout << "a & b = " << (a & b) << std::endl;
    std::cout << "a | b = " << (a | b) << std::endl;
    std::cout << "a ^ b = " << (a ^ b) << std::endl;
    std::cout << "~a = " << ~a << std::endl;
    std::cout << "a << b = " << (a << b) << std::endl;
    std::cout << "a >> b = " << (a >> b) << std::endl;
    return 0;
}


int main()
{
    std::string exampleString = "Hello, my name is John Doe and I am 30 years old.";
    std::cout << exampleString << std::endl;

    std::string name = "John Doe";
    std::string age = "30";
    std::string exampleString2 = "Hello, my name is " + name + " and I am " + age + " years old.";
    std::cout << exampleString2 << std::endl;
}
