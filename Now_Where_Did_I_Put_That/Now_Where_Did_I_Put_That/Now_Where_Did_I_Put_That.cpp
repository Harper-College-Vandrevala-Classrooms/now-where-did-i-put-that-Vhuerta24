#include <iostream>
#include <string>
#include <cctype> // for tolower

using namespace std;

// Character search with case sensitivity and starting position options
int findThe(const string& str, char _char, bool caseSensitive = true, int startPos = 0) {
    if (startPos < 0 || startPos >= str.length()) {
        return -1; // Invalid starting position
    }

    for (int i = startPos; i < str.length(); ++i) {
        char currentChar = str[i];
        if (!caseSensitive) {
            currentChar = tolower(currentChar);
            _char = tolower(_char);
        }
        if (currentChar == _char) {
            return i; // Return the index of the first occurrence
        }
    }
    return -1; // Returns -1 if the character is not found
}

// Substring search with case sensitivity and starting position options
int findThe(const string& str, const string& substr, bool caseSensitive = true, int startPos = 0) {
    if (startPos < 0 || startPos >= str.length()) {
        return -1; // Invalid starting position
    }

    int strLen = str.length();
    int substrLen = substr.length();

    for (int i = startPos; i <= strLen - substrLen; ++i) {
        int j;
        for (j = 0; j < substrLen; ++j) {
            char currentChar = str[i + j];
            char substrChar = substr[j];

            if (!caseSensitive) {
                currentChar = tolower(currentChar);
                substrChar = tolower(substrChar);
            }

            if (currentChar != substrChar) {
                break;
            }
        }
        if (j == substrLen) {
            return i; // Return the starting index of the substring
        }
    }
    return -1; // Return -1 if the substring is not found
}

// Function to perform tests
void performTest(const string& str, char c, const string& substr, bool caseSensitive = true, int startPos = 0) {
    cout << "Testing on string: \"" << str << "\" from position " << startPos << endl;

    int charIndex = findThe(str, c, caseSensitive, startPos);
    if (charIndex != -1) {
        cout << "Character '" << c << "' found at index: " << charIndex << endl;
    }
    else {
        cout << "Character not found: -1" << endl;
    }

    int substrIndex = findThe(str, substr, caseSensitive, startPos);
    if (substrIndex != -1) {
        cout << "Substring \"" << substr << "\" found at index: " << substrIndex << endl;
    }
    else {
        cout << "Substring not found: -1" << endl;
    }

    cout << endl; 
}

int main() {
    // Test case-sensitive searches from different starting positions
    performTest("Hello, world!", 'H', "H");
    performTest("Hello, world!", 'h', "h"); // Should not find 'h' case-sensitity (upper/lower)
    performTest("Hello, world!", ' ', "rld");

    // Test case-insensitive searches from different starting positions
    performTest("Hello, world!", 'h', "h", false); // Case insensitive
    performTest("Hello, world!", 'H', "H", false); // Case insensitive
    performTest("Hello, world!", '!', "GOODBYE", false); // Should not find 'GOODBYE'
    performTest("Hello, world!", '!', "World", false); // Should find 'World'

    // Test with starting position
    performTest("Hello, world!", 'o', "rld", true, 5); // Start from index 5
    performTest("Hello, world!", 'o', "ld", true, 3); // Start from index 3
    performTest("Hello, world!", '!', "d", true, 9); // Start from index 5
    performTest("Hello, world!", ' ', " ", true, 2); // Start from index 5
    performTest("Hello, world!", 'o', "rld", false, 5); // Case insensitive, start from index 5

    return 0;
}
