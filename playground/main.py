

class ComplexGenerator:
    def __init__(self, start, end):
        self.start = start
        self.end = end
        self.current = self.start

    def __iter__(self):
        return self

    def __next__(self):
        if self.current > self.end:
            raise StopIteration
        result = self.current
        self.current += 1
        return result
    
    def print_start_and_end(self):
        print(f"Start: {self.start}, End: {self.end}")


def main():
    my_generator = ComplexGenerator(1, 10)

    # For loop
    for num in my_generator:
        print(num)

    # While loop
    another_generator = ComplexGenerator(11, 20)
    current_number = next(another_generator)
    while current_number <= 20:
        print(current_number)
        current_number = next(another_generator)

    # Class example
    class ComplexClass:
        def __init__(self, num1, num2):
            self.num1 = num1
            self.num2 = num2

        def add(self):
            return self.num1 + self.num2

        def subtract(self):
            return self.num1 - self.num2

    obj1 = ComplexClass(5, 3)
    obj2 = ComplexClass(10, 7)

    print(obj1.add())
    print(obj2.subtract())


if __name__ == '__main__':
    main()


async def async_example():
    print("Starting async function")
    await asyncio.sleep(1)
    print("Async function is done")

loop = asyncio.get_event_loop()
loop.run_until_complete(async_example())
