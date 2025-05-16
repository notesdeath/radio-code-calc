#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <limits>
#include <iomanip>

// Radio Code Calculator for multiple car brands
// Based on the original algorithms from Delphi source code

// Utility functions for validation
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isAlpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isAlphaNumeric(char c) {
    return isDigit(c) || isAlpha(c);
}

// Clear input buffer
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Wait for key press
void waitForKeyPress() {
    std::cout << "\nPress Enter to continue...";
    clearInputBuffer();
    std::cin.get();
}

//------------------------------------------------------------------------------
// RENAULT/DACIA CALCULATOR
//------------------------------------------------------------------------------
namespace RenaultCalculator {
    bool validateInput(const std::string& input, std::string& errorMessage) {
        // Check if the input is 4 characters long
        if (input.length() != 4) {
            errorMessage = "Input must be 4 characters long!";
            return false;
        }

        // Check if the first character is a letter
        if (!isAlpha(input[0])) {
            errorMessage = "First character must be a letter!";
            return false;
        }

        // Check if the remaining characters are digits
        for (int i = 1; i < 4; ++i) {
            if (!isDigit(input[i])) {
                errorMessage = "Characters 2-4 must be digits!";
                return false;
            }
        }

        // Check if the input starts with A0
        if (std::toupper(input[0]) == 'A' && input[1] == '0') {
            errorMessage = "Input cannot start with A0!";
            return false;
        }

        return true;
    }

    int getFirstByte(int input) {
        if (input > 10) return 0;

        switch (input) {
        case 6:
        case 7:
        case 8:
            return 0;
        case 9:
            return 1;
        default:
            return input;
        }
    }

    int getSecondByte(int input) {
        if (input > 10) return 0;

        switch (input) {
        case 6:
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 1;
        default:
            return input;
        }
    }

    int getThirdByte(int input) {
        if (input > 10) return 0;

        switch (input) {
        case 6:
        case 7:
            return 2;
        case 8:
            return 0;
        case 9:
            return 1;
        default:
            return input;
        }
    }

    int getFourthByte(int input) {
        if (input > 10) return 0;

        switch (input) {
        case 6:
        case 7:
            return 3;
        case 8:
            return 0;
        case 9:
            return 1;
        default:
            return input;
        }
    }

    std::string calculateRadioCode(const std::string& precode) {
        // Convert to uppercase
        std::string input = precode;
        input[0] = std::toupper(input[0]);

        // Get character codes
        int c1 = static_cast<int>(input[0]);
        int c2 = static_cast<int>(input[1]);
        int c3 = static_cast<int>(input[2]);
        int c4 = static_cast<int>(input[3]);

        // Calculate according to algorithm
        int X = c2 + (c1 * 10) - 698;
        int Y = c4 + (c3 * 10) + X - 528;
        int Z = (Y * 7) % 100;

        int floor = static_cast<int>(Z / 10);
        int mod = (Z % 10) * 10;
        int remainder = (259 % X) % 100;
        int hundred = remainder * 100;
        int C = floor + mod + hundred;

        // Format result to 4 digits with leading zeros if needed
        std::string result = std::to_string(C);
        while (result.length() < 4) {
            result = "0" + result;
        }

        return result;
    }

    void run() {
        std::cout << "==============================================" << std::endl;
        std::cout << "        Renault/Dacia Radio Code Calculator" << std::endl;
        std::cout << "==============================================" << std::endl;
        std::cout << std::endl;
        std::cout << " Enter your 4-character precode" << std::endl;
        std::cout << std::endl;

        std::string precode;
        std::cout << "Code: ";
        std::cin >> precode;

        std::string errorMessage;
        if (!validateInput(precode, errorMessage)) {
            std::cout << "Error: " << errorMessage << std::endl;
        }
        else {
            std::string radioCode = calculateRadioCode(precode);

            std::cout << std::endl;
            std::cout << "==============================================" << std::endl;
            std::cout << " Precode: " << precode << std::endl;
            std::cout << " Radio Code: " << radioCode << std::endl;
            std::cout << "==============================================" << std::endl;
        }
    }
}

//------------------------------------------------------------------------------
// PEUGEOT CALCULATOR
//------------------------------------------------------------------------------
namespace PeugeotCalculator {
    bool validateInput(const std::string& input, std::string& errorMessage) {
        // Check if the input is 4 characters long
        if (input.length() != 4) {
            errorMessage = "Input must be 4 characters long!";
            return false;
        }

        // Check if all characters are digits
        for (int i = 0; i < 4; ++i) {
            if (!isDigit(input[i])) {
                errorMessage = "All characters must be digits!";
                return false;
            }
        }

        return true;
    }

    std::string calculateRadioCode(const std::string& barcode) {
        int d1 = barcode[0] - '0';
        int d2 = barcode[1] - '0';
        int d3 = barcode[2] - '0';
        int d4 = barcode[3] - '0';

        // Perform calculations
        int snArr[4];
        snArr[0] = (d1 + 1) % 10;
        snArr[1] = (d2 + 2) % 10;
        snArr[2] = (d3 + 3) % 10;
        snArr[3] = (d4 + 4) % 10;

        // Apply correction
        for (int i = 0; i < 4; ++i) {
            if (snArr[i] > 6) snArr[i] -= 6;
        }

        // Format the result
        std::string result;
        for (int i = 0; i < 4; ++i) {
            result += std::to_string(snArr[i]);
        }

        return result;
    }

    void run() {
        std::cout << "==============================================" << std::endl;
        std::cout << "      Peugeot Radio Code Calculator" << std::endl;
        std::cout << "==============================================" << std::endl;
        std::cout << std::endl;
        std::cout << " Enter the last 4 digits of the barcode" << std::endl;
        std::cout << " (the barcode starts with C7)" << std::endl;
        std::cout << std::endl;

        std::string barcode;
        std::cout << "Barcode: ";
        std::cin >> barcode;

        std::string errorMessage;
        if (!validateInput(barcode, errorMessage)) {
            std::cout << "Error: " << errorMessage << std::endl;
        }
        else {
            std::string radioCode = calculateRadioCode(barcode);

            std::cout << std::endl;
            std::cout << "==============================================" << std::endl;
            std::cout << " Barcode: " << barcode << std::endl;
            std::cout << " Radio Code: " << radioCode << std::endl;
            std::cout << "==============================================" << std::endl;
        }
    }
}

//------------------------------------------------------------------------------
// FIAT/LANCIA DAIICHI MOPAR CALCULATOR
//------------------------------------------------------------------------------
namespace FiatDaiichiCalculator {
    bool validateInput(const std::string& input, std::string& errorMessage) {
        // Check if the input is 4 or 5 characters long
        if (input.length() != 4 && input.length() != 5) {
            errorMessage = "Input must be 4 or 5 characters long!";
            return false;
        }

        if (input.length() == 5) {
            // First character can be alphanumeric
            if (!isAlphaNumeric(input[0])) {
                errorMessage = "First character must be alphanumeric!";
                return false;
            }

            // Remaining characters must be digits
            for (int i = 1; i < 5; ++i) {
                if (!isDigit(input[i])) {
                    errorMessage = "Characters 2-5 must be digits!";
                    return false;
                }
            }
        }
        else { // 4 characters
            // All characters must be digits
            for (int i = 0; i < 4; ++i) {
                if (!isDigit(input[i])) {
                    errorMessage = "All characters must be digits!";
                    return false;
                }
            }
        }

        return true;
    }

    std::string calculateRadioCode(const std::string& serialNumber) {
        std::string input = serialNumber;

        // Trim the first character if needed
        if (input.length() == 5) {
            input = input.substr(1, 4);
        }

        int snArr[4] = { 0, 0, 0, 0 };

        // Calculate according to algorithm
        snArr[3] = 10 - (input[0] - '0');
        snArr[2] = 9 - (input[1] - '0');
        snArr[1] = 9 - (input[2] - '0');
        snArr[0] = 9 - (input[3] - '0');

        // Format the result
        std::string result;
        for (int i = 0; i < 4; ++i) {
            result += std::to_string(snArr[i]);
        }

        return result;
    }

    void run() {
        std::cout << "==============================================" << std::endl;
        std::cout << "  Fiat/Lancia Daiichi Mopar Radio Code Calculator" << std::endl;
        std::cout << "==============================================" << std::endl;
        std::cout << std::endl;
        std::cout << " Enter the 5 characters of the serial number" << std::endl;
        std::cout << " (or 4 digits without the first character)" << std::endl;
        std::cout << std::endl;

        std::string serialNumber;
        std::cout << "Serial Number: ";
        std::cin >> serialNumber;

        std::string errorMessage;
        if (!validateInput(serialNumber, errorMessage)) {
            std::cout << "Error: " << errorMessage << std::endl;
        }
        else {
            std::string radioCode = calculateRadioCode(serialNumber);

            std::cout << std::endl;
            std::cout << "==============================================" << std::endl;
            std::cout << " Serial Number: " << serialNumber << std::endl;
            std::cout << " Radio Code: " << radioCode << std::endl;
            std::cout << "==============================================" << std::endl;
        }
    }
}

//------------------------------------------------------------------------------
// FIAT CONTINENTAL VP1 AND VP2 CALCULATOR
//------------------------------------------------------------------------------
namespace FiatContinentalCalculator {
    bool validateInput(const std::string& input, std::string& errorMessage) {
        // Check if the input is 4 characters long
        if (input.length() != 4) {
            errorMessage = "Input must be 4 characters long!";
            return false;
        }

        // Check if all characters are digits
        for (int i = 0; i < 4; ++i) {
            if (!isDigit(input[i])) {
                errorMessage = "All characters must be digits!";
                return false;
            }
        }

        return true;
    }

    int getFirstByte(int input) {
        if (input > 10) return 0;

        switch (input) {
        case 6:
        case 7:
        case 8:
            return 0;
        case 9:
            return 1;
        default:
            return input;
        }
    }

    int getSecondByte(int input) {
        if (input > 10) return 0;

        switch (input) {
        case 6:
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 1;
        default:
            return input;
        }
    }

    int getThirdByte(int input) {
        if (input > 10) return 0;

        switch (input) {
        case 6:
        case 7:
            return 2;
        case 8:
            return 0;
        case 9:
            return 1;
        default:
            return input;
        }
    }

    int getFourthByte(int input) {
        if (input > 10) return 0;

        switch (input) {
        case 6:
        case 7:
            return 3;
        case 8:
            return 0;
        case 9:
            return 1;
        default:
            return input;
        }
    }

    std::string calculateRadioCode(const std::string& serialNumber) {
        // Convert to integer
        int inputCode = std::stoi(serialNumber);

        // Calculate the code
        int outputCode = 1111;

        int snArr[4];
        snArr[0] = (inputCode / 1000) & 0x0F;
        snArr[1] = (inputCode % 1000) / 100 & 0x0F;
        snArr[2] = (inputCode % 100) / 10 & 0x0F;
        snArr[3] = inputCode % 10 & 0x0F;

        outputCode += getThirdByte(snArr[3]) * 10;
        outputCode += getFirstByte(snArr[2]) * 1000;
        outputCode += getFourthByte(snArr[1]);
        outputCode += getSecondByte(snArr[0]) * 100;

        // Format result to 4 digits with leading zeros if needed
        std::string result = std::to_string(outputCode);
        while (result.length() < 4) {
            result = "0" + result;
        }

        return result;
    }

    void run() {
        std::cout << "==============================================" << std::endl;
        std::cout << "  Fiat Continental VP1/VP2 Radio Code Calculator" << std::endl;
        std::cout << "==============================================" << std::endl;
        std::cout << std::endl;
        std::cout << " Enter the last 4 digits of the serial number" << std::endl;
        std::cout << std::endl;

        std::string serialNumber;
        std::cout << "Serial Number: ";
        std::cin >> serialNumber;

        std::string errorMessage;
        if (!validateInput(serialNumber, errorMessage)) {
            std::cout << "Error: " << errorMessage << std::endl;
        }
        else {
            std::string radioCode = calculateRadioCode(serialNumber);

            std::cout << std::endl;
            std::cout << "==============================================" << std::endl;
            std::cout << " Serial Number: " << serialNumber << std::endl;
            std::cout << " Radio Code: " << radioCode << std::endl;
            std::cout << "==============================================" << std::endl;
        }
    }
}

//------------------------------------------------------------------------------
// MAIN PROGRAM
//------------------------------------------------------------------------------
void displayMenu() {
    std::cout << "==============================================" << std::endl;
    std::cout << "       Multi-Brand Radio Code Calculator" << std::endl;
    std::cout << "==============================================" << std::endl;
    std::cout << std::endl;
    std::cout << " 1. Renault/Dacia Calculator" << std::endl;
    std::cout << " 2. Peugeot Calculator" << std::endl;
    std::cout << " 3. Fiat/Lancia Daiichi Mopar Calculator" << std::endl;
    std::cout << " 4. Fiat Continental VP1/VP2 Calculator" << std::endl;
    std::cout << " 0. Exit" << std::endl;
    std::cout << std::endl;
    std::cout << " Select an option: ";
}

int main() {
    // Set console title (Windows-specific)
#ifdef _WIN32
    system("title Multi-Brand Radio Code Calculator");
#endif

    int choice = -1;

    do {
        system("cls");  // Windows-specific, use "clear" for Linux/Mac
        displayMenu();

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = -1;
        }

        system("cls");  // Windows-specific, use "clear" for Linux/Mac

        switch (choice) {
        case 1:
            RenaultCalculator::run();
            break;
        case 2:
            PeugeotCalculator::run();
            break;
        case 3:
            FiatDaiichiCalculator::run();
            break;
        case 4:
            FiatContinentalCalculator::run();
            break;
        case 0:
            std::cout << "Exiting program. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid option! Please try again." << std::endl;
            break;
        }

        if (choice != 0) {
            waitForKeyPress();
        }

    } while (choice != 0);

    return 0;
}