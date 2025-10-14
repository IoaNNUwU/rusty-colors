// MARK: - Complex Swift Program

// MARK: - Enums

enum Color {
    case red
    case green
    case blue
}

enum Shape {
    case circle
    case square
    case triangle
}

// MARK: - Structs

struct Point {
    let x: Double
    let y: Double
}

struct Size {
    let width: Double
    let height: Double
}

// MARK: - Classes

class ShapeView {
    let shape: Shape
    let color: Color
    let size: Size
    
    init(shape: Shape, color: Color, size: Size) {
        self.shape = shape
        self.color = color
        self.size = size
    }
    
    func draw() {
        switch shape {
        case .circle:
            print("Drawing a circle")
        case .square:
            print("Drawing a square")
        case .triangle:
            print("Drawing a triangle")
        }
        
        switch color {
        case .red:
            print("with red color")
        case .green:
            print("with green color")
        case .blue:
            print("with blue color")
        }
    }
}

// MARK: - Functions

func calculateArea(of shape: ShapeView) -> Double {
    switch shape.shape {
    case .circle:
        let radius = shape.size.width / 2
        return Double.pi * pow(radius, 2)
    case .square:
        return shape.size.width * shape.size.height
    case .triangle:
        let base = shape.size.width
        let height = shape.size.height
        return (base * height) / 2
    }
}

func main() {
    let shapeView = ShapeView(shape: .circle, color: .red, size: Size(width: 100, height: 100))
    shapeView.draw()
    let area = calculateArea(of: shapeView)
    print("The area of the shape is \(area)")
}

// MARK: - Generic Vector

struct Vector<T> {
    private var elements: [T]
    
    init() {
        elements = []
    }
    
    mutating func push(_ element: T) {
        elements.append(element)
    }
    
    mutating func pop() -> T? {
        return elements.popLast()
    }
    
    func peek() -> T? {
        return elements.last
    }
    
    func isEmpty() -> Bool {
        return elements.isEmpty
    }
    
    func count() -> Int {
        return elements.count
    }
    
    func index(of element: T) -> Int? {
        return elements.firstIndex(of: element)
    }
    
    func contains(_ element: T) -> Bool {
        return elements.contains(element)
    }
    
    func remove(at index: Int) -> T {
        return elements.remove(at: index)
    }
    
    func removeAll(occurrencesOf element: T) {
        elements.removeAll(where: { $0 == element })
    }
    
    func removeFirstOccurrence(of element: T) {
        guard let index = elements.firstIndex(of: element) else { return }
        elements.remove(at: index)
    }
    
    func append<S>(_ other: S) where S: Sequence, S.Element == T {
        elements.append(contentsOf: other)
    }
    
    func insert(_ element: T, at index: Int) {
        elements.insert(element, at: index)
    }
    
    func replaceSubrange(_ bounds: Range<Int>, with elements: [T]) {
        elements.replaceSubrange(bounds, with: elements)
    }
    
    func sort() {
        elements.sort()
    }
    
    func sorted() -> Vector<T> {
        return Vector(elements.sorted())
    }
}
