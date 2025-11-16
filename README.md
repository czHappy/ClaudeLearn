# Calculator Project

A simple C++ calculator library implementing basic arithmetic operations with comprehensive unit tests.

## Features

- **Addition**: Add two numbers
- **Subtraction**: Subtract two numbers
- **Multiplication**: Multiply two numbers
- **Division**: Divide two numbers (with zero-division error handling)

## Project Structure

```
.
├── CMakeLists.txt          # CMake build configuration
├── include/                # Header files
│   └── Calculator.h        # Calculator class declaration
├── src/                    # Source files
│   └── Calculator.cpp      # Calculator class implementation
└── tests/                  # Unit tests
    └── test_calculator.cpp # Test cases
```

## Requirements

- CMake 3.10 or higher
- C++11 compatible compiler
- Git

## Building the Project

```bash
# Create build directory
mkdir -p build && cd build

# Generate build files with CMake
cmake ..

# Build the project
make

# Run tests
./test_calculator
```

## Running Tests

The project includes comprehensive unit tests covering:
- Positive number operations
- Negative number operations
- Mixed positive/negative operations
- Zero handling
- Division by zero exception handling

```bash
cd build
./test_calculator
```

Expected output:
```
Running Calculator Unit Tests...
================================
✓ Addition tests passed
✓ Subtraction tests passed
✓ Multiplication tests passed
✓ Division tests passed
================================
All tests passed successfully!
```

## Usage Example

```cpp
#include "Calculator.h"

int main() {
    Calculator calc;

    double sum = calc.add(5.0, 3.0);        // 8.0
    double diff = calc.subtract(10.0, 3.0);  // 7.0
    double prod = calc.multiply(4.0, 5.0);   // 20.0
    double quot = calc.divide(10.0, 2.0);    // 5.0

    return 0;
}
```

## License

This project is open source and available for educational purposes.
