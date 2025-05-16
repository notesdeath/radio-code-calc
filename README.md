# Multi-Brand Radio Code Calculator

A C++ application for calculating radio unlock codes for various car brands including Renault/Dacia, Peugeot, Fiat/Lancia, and more. This tool helps retrieve radio security codes using the serial number or barcode information found on the radio unit.

## Features

- **Multiple brand support**:
  - Renault/Dacia radio codes
  - Peugeot radio codes (barcode based)
  - Fiat/Lancia Daiichi Mopar radio codes
  - Fiat Continental VP1/VP2 radio codes
- **User-friendly interface** with menu-based navigation
- **Comprehensive input validation** to prevent errors
- **Detailed calculation steps** for troubleshooting
- **Cross-platform compatibility** (Windows, Linux, macOS)

## Installation

### Prerequisites

- C++ compiler with C++11 support (GCC, Clang, MSVC, etc.)
- Basic build tools for your platform

### Compilation

#### Windows (Visual Studio)

```
cl /EHsc /std:c++11 main.cpp /Fe:RadioCodeCalculator.exe
```

#### Windows (MinGW)

```
g++ -std=c++11 -o RadioCodeCalculator.exe main.cpp
```

#### Linux/macOS

```
g++ -std=c++11 -o RadioCodeCalculator main.cpp
```

## Usage

Run the compiled executable and follow the on-screen menu to select the appropriate calculator for your radio model.

1. Launch the application
2. Select the calculator type based on your radio model
3. Enter the required input (serial number, barcode, etc.)
4. The program will display the calculated radio code
5. Press any key to return to the main menu
6. Select option 0 to exit the program

## Calculator Types and Input Formats

### 1. Renault/Dacia Calculator
- **Input format**: 4 characters (letter followed by 3 digits)
- **Example**: A111
- **Note**: First character must be a letter, and it cannot start with A0

### 2. Peugeot Calculator
- **Input format**: 4 digits
- **Example**: 1234
- **Note**: These are the last 4 digits of the barcode which usually starts with C7

### 3. Fiat/Lancia Daiichi Mopar Calculator
- **Input format**: 5 characters (first can be alphanumeric, followed by 4 digits) or 4 digits
- **Example**: A1234 or 1234
- **Note**: If using 5 characters, the first character can be a letter or number

### 4. Fiat Continental VP1/VP2 Calculator
- **Input format**: 4 digits
- **Example**: 1234
- **Note**: These are the last 4 digits of the serial number

## Examples

### Renault/Dacia Example:
Input: A111
Output: 0048

### Peugeot Example:
Input: 1234
Output: 2456

## Safety and Legal Notice

This program is provided for educational and legitimate recovery purposes only. It should only be used to recover radio codes for devices you legally own. The author does not condone or support any illegal activities or theft.

## Contributing

Contributions, bug reports, and feature requests are welcome! Feel free to submit a pull request or open an issue.

## License

This project is open source, released under the MIT License.
