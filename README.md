# Calculator Project

A simple C++ calculator library implementing basic arithmetic operations with comprehensive unit tests.

## Features

- **Addition**: Add two numbers
- **Subtraction**: Subtract two numbers
- **Multiplication**: Multiply two numbers
- **Division**: Divide two numbers (with zero-division error handling)
- **Natural Logarithm (ln)**: Calculate natural logarithm (base e)
- **Common Logarithm (log10)**: Calculate common logarithm (base 10)
- **Custom Base Logarithm (log)**: Calculate logarithm with any valid base

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
- Logarithm calculations (ln, log10, log with custom base)
- Invalid logarithm input handling (negative numbers, zero, invalid bases)

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
✓ Logarithm tests passed
================================
All tests passed successfully!
```

## Usage Example

```cpp
#include "Calculator.h"
#include <iostream>

int main() {
    Calculator calc;

    // Basic arithmetic operations
    double sum = calc.add(5.0, 3.0);        // 8.0
    double diff = calc.subtract(10.0, 3.0);  // 7.0
    double prod = calc.multiply(4.0, 5.0);   // 20.0
    double quot = calc.divide(10.0, 2.0);    // 5.0

    // Logarithm operations
    double naturalLog = calc.ln(2.718);      // ≈ 1.0 (ln(e))
    double commonLog = calc.log10(100.0);    // 2.0 (log₁₀(100))
    double customLog = calc.log(8.0, 2.0);   // 3.0 (log₂(8))

    return 0;
}
```

### Logarithm Functions

- **ln(x)**: Natural logarithm (base e)
  - Returns the natural logarithm of x
  - Throws `std::invalid_argument` if x ≤ 0

- **log10(x)**: Common logarithm (base 10)
  - Returns the base-10 logarithm of x
  - Throws `std::invalid_argument` if x ≤ 0

- **log(x, base)**: Logarithm with custom base
  - Returns the logarithm of x with the specified base
  - Throws `std::invalid_argument` if x ≤ 0
  - Throws `std::invalid_argument` if base ≤ 0 or base = 1

## License

This project is open source and available for educational purposes.
