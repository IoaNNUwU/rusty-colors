
const POINT_X = 3;
const POINT_Y = 4;

class Point {
  x: number;
  y: number;

  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }

  distance() {
    return Math.sqrt(this.x * this.x + this.y * this.y);
  }
}

const point = new Point(3, 4);
console.log(point.distance());

const rectangle = { width: 5, height: 7 };

console.log(rectangle.width * rectangle.height);

const dog = new Dog("Rex");
dog.makeSound();

const greeting = "Hello, world!";
const uppercaseGreeting = greeting.toUpperCase();
console.log(uppercaseGreeting);

const lowercaseGreeting = greeting.toLowerCase();
console.log(lowercaseGreeting);

const reversedGreeting = [...greeting].reverse().join("");
console.log(reversedGreeting);

const fullName = "John Doe";
const nameLength = fullName.length;
console.log(nameLength);

const firstChar = fullName.charAt(0);
console.log(firstChar);

const substring = fullName.substring(0, 3);
console.log(substring);

const includes = fullName.includes("ohn");
console.log(includes);

const index = fullName.indexOf("n");
console.log(index);

const replaced = fullName.replace("John", "Jane");
console.log(replaced);

const trimmed = "   Hello, world!   ".trim();
console.log(trimmed);

const splitted = fullName.split(" ");
console.log(splitted);


$(document).ready(() => {
  const element = $("#element");
  element.text("Hello, world!");
  element.css("color", "red");
  element.hide();
  element.show();
});


interface UserProps {
  name: string;
}

const User: React.FC<UserProps> = ({ name }) => {
  return <h1>Hello, {name}!</h1>;
}

const App = () => <User name="John" />;

ReactDOM.render(<App />, document.getElementById("root"));
