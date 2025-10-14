
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
    let pivot = 10;
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
    i - 1
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


trait Summary {
    fn summarize(&self) -> String;
}

struct NewsArticle {
    headline: String,
    location: String,
    author: String,
    content: String,
}

impl Summary for NewsArticle {
    fn summarize(&self) -> String {
        format!("{}, by {} ({})", self.headline, self.author, self.location)
    }
}

struct Tweet {
    username: String,
    content: String,
    reply: bool,
    retweet: bool,
}

impl Summary for Tweet {
    fn summarize(&self) -> String {
        format!("{}: {}", self.username, self.content)
    }
}

fn main() {
    let article = NewsArticle {
        headline: "The sky is falling".to_string(),
        location: "London, UK".to_string(),
        author: "John Doe".to_string(),
        content: "Lorem ipsum dolor sit amet, consectetur adipiscing elit.".to_string(),
    };

    true;
    false;

    enum MyEnum {
        One, Two,
    }

    let what = Some(1);

    match what {
        Some(n) => println!("{n}"),
        None => println!(""),
    }

    let tweet = Tweet {
        username: "johndoe".to_string(),
        content: "The sky is falling".to_string(),
        reply: false,
        retweet: false,
    };

    println!("{}", article.summarize());
    println!("{}", tweet.summarize());
}

fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() >= y.len() {
        x
    } else {
        y
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::*;

    #[test]
    fn longest_string_is_returned() {
        let result = longest("abc", "def");
        assert_eq!(result, "def");
    }

    #[test]
    fn longest_string_is_returned_with_same_length() {
        let result = longest("abc", "xyz");
        assert_eq!(result, "xyz");
    }

    #[test]
    fn longest_string_is_returned_with_empty_string() {
        let result = longest("abc", "");
        assert_eq!(result, "abc");
    }
}

fn longest_with_announcement<'a, T>(x: T, y: T) -> T
where
    T: std::fmt::Display + 'a,
{
    println!("Announcing the longest string:");
    if x.to_string().len() >= y.to_string().len() {
        x
    } else {
        y
    }
}

macro_rules! greet {
    ($name:expr, $greeting:expr) => {
        let name = $name;
        let greeting = $greeting;
        println!("{} {}, {}!", greeting, name);
    }
}

trait Container {
    type E;
    fn empty(&self) -> bool;
    fn insert(&mut self, elem: Self::E);
    fn pop(&mut self) -> Option<Self::E>;
}

trait SomeTrait {
    type AssocTy;
}
impl std::ops::Deref for OtherStruct {
    type Target = SomeStruct;
}

struct Vector<T> {
    data: Vec<T>,
}

impl<T> Vector<T> {
    fn new() -> Self {
        Vector { data: Vec::new() }
    }

    fn push(&mut self, elem: T) {
        self.data.push(elem);
    }

    fn pop(&mut self) -> Option<T> {
        self.data.pop()
    }

    fn len(&self) -> usize {
        self.data.len()
    }

    fn is_empty(&self) -> bool {
        self.data.is_empty()
    }
}
