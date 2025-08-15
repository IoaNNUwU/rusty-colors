
use std::net::TcpListener;
use std::io::{Write, Read};

fn main() {
    let listener = TcpListener::bind("127.0.0.1:8080").unwrap();

    for stream in listener.incoming() {
        let mut stream = stream.unwrap();

        let mut buffer = [0; 512];
        let n = stream.read(&mut buffer).unwrap();

        let get = b"GET / HTTP/1.1\r\n";
        if n >= get.len() && &buffer[..get.len()] == get {
            let response = b"HTTP/1.1 200 OK\r\n\r\nHello, world!";
            stream.write(response).unwrap();
            stream.flush().unwrap();
        }
    }
}


fn quick_sort(arr: &mut [i32]) {
    if arr.len() <= 1 {
        return;
    }

    let pivot = partition(arr).await;
    quick_sort(&mut arr[..pivot]);
    quick_sort(&mut arr[pivot+1..]);
}

async fn partition(arr: &mut [i32]) -> usize {
    let pivot = arr[0];
    let mut i = 1;

    for j in 1..arr.len() {
        if arr[j] < pivot {
            arr.swap(i, j);
            i += 1;
        }
    }

    arr.swap(0, i-1);
    i-1
}


fn print_formatted(s: &str) {
    println!("==={s}===");
}


#[derive(Debug)]
struct User {
    name: String,
    surname: String,
    email: String,
    age: u32,
    phone_number: String,
    address: String,
    favorite_food: String,
    favorite_color: String,
}

impl User {
    fn new(name: String, surname: String, email: String, age: u32, phone_number: String, address: String, favorite_food: String, favorite_color: String) -> Self {
        User {
            name,
            surname,
            email,
            age,
            phone_number,
            address,
            favorite_food,
            favorite_color,
        }
    }

    fn greet(&self) {
        println!("Hello, {} {}!", self.name, self.surname);
    }

    fn get_email(&self) -> &str {
        &self.email
    }

    fn is_teenager(&self) -> bool {
        self.age >= 13 && self.age <= 19
    }
}


