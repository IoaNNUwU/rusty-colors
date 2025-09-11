
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

interface Generic<T> {
  value: T;
}

const genericString: Generic<string> = { value: "Hello, world!" };
const genericNumber: Generic<number> = { value: 42 };



type ExtractType<T> = T extends infer U ? { [K in keyof U]: U[K] } : never;

type Simplify<T> = { [K in keyof T]: T[K] };

type SimplifyUnion<T> = T extends infer U ? Simplify<U> : never;

type UnionToIntersection<U> = (U extends any ? (k: U) => void : never) extends (k: infer I) => void ? I : never;

type UnionToTuple<T> = UnionToIntersection<T extends any ? (x: T) => T : never> extends (_: any) => infer W ? [...UnionToTuple<Exclude<T, W>>, W] : [];

type DeepMerge<T, U> = Simplify<UnionToIntersection<DeepMergeEachKey<T, U>>>;

type DeepMergeEachKey<T, U> = {
  [K in keyof T | keyof U]: K extends keyof T
    ? K extends keyof U
      ? [T[K], U[K]] extends [object, object]
        ? DeepMerge<T[K], U[K]>
        : U[K]
    : T[K]
    : K extends keyof U
    ? U[K]
    : never;
};

type DeepPartial<T> = Simplify<DeepPartialEachKey<T>>;

type DeepPartialEachKey<T> = {
  [K in keyof T]: T[K] extends object
    ? object extends T[K]
      ? T[K]
      : DeepPartial<T[K]>
    : T[K];
};

type DeepRequired<T> = Simplify<DeepRequiredEachKey<T>>;

type DeepRequiredEachKey<T> = {
  [K in keyof T]-?: T[K] extends object
    ? object extends T[K]
      ? T[K]
      : DeepRequired<T[K]>
    : T[K];
};

type SimplifyValues<T> = {
  [K in keyof T]: T[K] extends object
    ? SimplifyValues<T[K]>
    : T[K];
};

type SimplifyValuesEachKey<T> = Simplify<DeepMerge<{ [K in keyof T]: T[K] }, { [K in keyof T as K extends string ? K : never]: SimplifyValues<T[K]> }>>;

type SimplifyValues<T> = SimplifyValuesEachKey<T>;


type SimplifyValuesExample = SimplifyValues<{
  foo: string;
  bar: {
    baz: number;
    qux: string;
  };
}>;

type SimplifyValuesExampleResult = {
  foo: string;
  bar: {
    baz: number;
    qux: string;
  };
};

const cluster = require("cluster");
const numCPUs = require("os").cpus().length;
const http = require("http");

if (cluster.isMaster) {
  console.log(`Master ${process.pid} is running`);

  // Fork workers.
  for (let i = 0; i < numCPUs; i++) {
    cluster.fork();
  }

  cluster.on("exit", (worker, code, signal) => {
    console.log(`worker ${worker.process.pid} died`);
  });
} else {
  console.log(`Worker ${process.pid} started`);

  const server = http.createServer((request, response) => {
    response.writeHead(200, { "Content-Type": "text/html" });
    response.write("<h1>Hello, world!</h1>");
    response.end();
  });

  server.listen(3000, () => console.log("Server running on port 3000"));
}
