use std::collections::HashMap;
use std::net::{TcpListener, TcpStream};
use std::sync::{Mutex, Arc};

use std::error::Error;
use std::default::Default;

#[derive(Default, Debug)]
pub struct Users(HashMap<String, String>);

fn main() -> Result<(), Box<dyn Error>> {
    let listener = TcpListener::bind("127.0.0.1:7878").unwrap();
    let users: Arc<Mutex<Users>> = Arc::default();
    // Thread will block until new connection is incoming
    for stream in listener.incoming() {
        let users_ref = Arc::clone(&users);
        match stream {
            Ok(mut stream) => {
                std::thread::spawn(move || { handle_client(users_ref, &mut stream); });
            },
            Err(e) => {
                eprintln!("Unable to connect: {}", e);
            }
        }
    }
    Ok(())
}

fn handle_client(users_ref: Arc<Mutex<Users>>, stream: &mut TcpStream) {
    println!("{:?}", users_ref.lock().unwrap().0);
    stream.write_timeout().unwrap();
}