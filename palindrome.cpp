// Nick Braun
// 9/23/2023
// Palindrome - checks if users input is a palindrome or not, up to 80 characters.

// Sources:
// https://cplusplus.com/reference/cctype/isalnum/
// https://cplusplus.com/reference/cstring/

#include <iostream>
#include <cstring>
#include <cctype>

// Function to remove spaces and punctuation from a cstring
void removeSpacesAndPunctuation(char* str) {
    int len = std::strlen(str);
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (std::isalnum(str[i])) { // https://cplusplus.com/reference/cctype/isalnum/
            str[j++] = std::tolower(str[i]); // Convert to lowercase and store
        }
    }
    str[j] = '\0'; // Null-terminate the modified string
}

// Function to check if a cstring is a palindrome

bool isPalindrome(const char* str) {
    int len = std::strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    const int maxLength = 80;
    char input[maxLength + 1]; // Character array to store input with a maximum length of 80 characters

    std::cout << "Enter a series of characters (up to 80 characters): ";
    std::cin.getline(input, maxLength + 1); // Read input

    // Remove spaces and punctuation from the input
    removeSpacesAndPunctuation(input);

    // Check if it's a palindrome and print the result
    if (isPalindrome(input)) {
        std::cout << "Palindrome." << std::endl;
    } else {
        std::cout << "Not a palindrome." << std::endl;
    }

    return 0;
}
