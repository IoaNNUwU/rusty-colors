// Complex JavaScript snippet
const fibonacci = (n) => {
  if (n <= 0) {
    return [];
  } else if (n === 1) {
    return [0];
  } else {
    let fib = [0, 1];
    for (let i = 2; i < n; i++) {
      fib.push(fib[i - 1] + fib[i - 2]);
    }
    return fib;
  }
}

const maxSum = (arr) => {
  let max = -Infinity;
  let currentSum = 0;
  let maxIndex = 0;
  for (let i = 0; i < arr.length; i++) {
    currentSum += arr[i];
    if (currentSum > max) {
      max = currentSum;
      maxIndex = i;
    }
    if (currentSum < 0) {
      currentSum = 0;
    }
  }
  return arr.slice(maxIndex - max + 1, maxIndex + 1);
}

// Class example
class Person {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }

  sayHello() {
    console.log(`Hello, my name is ${this.name} and I'm ${this.age} years old.`);
  }
}

const person = new Person("John", 25);
person.sayHello();

// Class example with inheritance
class Animal {
  constructor(name) {
    this.name = name;
  }

  sayHello() {
    console.log(`Hello, my name is ${this.name}.`);
  }
}

class Dog extends Animal {
  bark() {
    console.log(`${this.name} barks!`);
  }
}

const dog = new Dog("Rex");
dog.sayHello();
dog.bark();

// Svelte example
const App = () => {
  let name = "world";

  return (
    <main>
      <h1>Hello {name}!</h1>
      <input type="text" bind:value={name} />
    </main>
  );
};

new App({ target: document.body });

const Counter = () => {
  let count = 0;

  const increment = () => {
    count += 1;
  };

  const decrement = () => {
    count -= 1;
  };

  return (
    <main>
      <h1>Count: {count}</h1>
      <button on:click={increment}>+</button>
      <button on:click={decrement}>-</button>
    </main>
  );
};

new Counter({ target: document.body });
