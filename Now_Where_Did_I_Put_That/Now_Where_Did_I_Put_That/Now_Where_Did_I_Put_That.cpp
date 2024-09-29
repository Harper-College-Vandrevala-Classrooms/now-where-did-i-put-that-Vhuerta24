//In this lab we have to create 2 functions, one that finds a specifc character in a given string and another that finds a substring in a given string. 
//The output should be the index of the where the character/substring is found or return -1 to show not found
#include <iostream>
#include <string>

using namespace std; 

//character 
int findThe(const string& str, char _char) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == _char) {
            return i; // Return the index of the first occurrence
        }
    }
    return -1; // Returns -1 if the character is not found
}

//substring 
int findThe(const string& str, const string& substr) {
    int strLen = str.length();
    int substrLen = substr.length();

    //Loops through the main string
    for (int i = 0; i <= strLen - substrLen; ++i) {
        int j;
        // Checks if the substring matches
        for (j = 0; j < substrLen; ++j) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        // If the inner loop completed, we found a match
        if (j == substrLen) {
            return i; // Return the starting index of the substring
        }
    }
    return -1; // Return -1 if the substring is not found
}



int main() {

    //test 1 

    string myString = "Hello, world!";
    char myChar = 'H';//index = 0
    string mySubstr = "H";//index = 0
    
    int CharIndex = findThe(myString, myChar);
    if (CharIndex != string::npos) {
        cout << "TEST 1" << endl;
        cout << "Character '" << myChar << "' found at index: " << CharIndex << endl;// Outputs where(index) the character is
    } 
    else {
        cout << "Character not found: -1" << endl; //If the character isnt found a -1 will be outputted to show that. 
    }

    int StrIndex = findThe(myString, mySubstr);
    if (StrIndex != -1) {
        cout << "Substring " << mySubstr << " found at index: " << StrIndex << endl;// Outputs where(index) the substring begins 
    }
    else {
        cout << "Substring not found: -1 " << endl;
    }



    //TEST 2 

    string String2 = "Hello, world!";
    char Char2 = ' ';// index = 6
    string Substr2 = "rld";//index = 9

    int Char2Index = findThe(String2, Char2);
    if (Char2Index != string::npos) {
        cout << "TEST 2" << endl;
        cout << "Character '" << Char2 << "' found at index: " << Char2Index << endl;// Outputs where(index) the character is
    }
    else {
        cout << "Character not found: -1" << endl; //If the character isnt found a -1 will be outputted to show that. 
    }

    int Str2Index = findThe(String2, Substr2);
    if (Str2Index != -1) {
        cout << "Substring " << Substr2 << " found at index: " << Str2Index << endl;// Outputs where(index) the substring begins 
    }
    else {
        cout << "Substring not found: -1 " << endl;
    }


    //TEST 3 

    string String3 = "Hello, world!";
    char Char3 = '!';// index = 12
    string Substr3 = "goodbye";//index = not found

    int Char3Index = findThe(String3, Char3);
    if (Char3Index != string::npos) {
        cout << "TEST 3" << endl;
        cout << "Character '" << Char3 << "' found at index: " << Char3Index << endl;// Outputs where(index) the character is
    }
    else {
        cout << "Character not found: -1" << endl; //If the character isnt found a -1 will be outputted to show that. 
    }

    int Str3Index = findThe(String3, Substr3);
    if (Str3Index != -1) {
        cout << "Substring " << Substr3 << " found at index: " << Str3Index << endl;// Outputs where(index) the substring begins 
    }
    else {
        cout << "Substring not found: -1 " << endl;
    }


    return 0;
}


