/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

class CaesarCipher {
private:
    int shiftValue;

public:
    CaesarCipher(int value) : shiftValue(value) {}

    string encode(const string& message) {
        string newMsg = "";
        for (char ch : message) {
            if (isalpha(ch)) {
                char base = isupper(ch) ? 'A' : 'a';
                newMsg += char((ch - base + shiftValue + 26) % 26 + base);
            } else {
                newMsg += ch;
            }
        }
        return newMsg;
    }

    string decode(const string& eMsg) {
        string dMsg = "";
        for (char ch : eMsg) {
            if (isalpha(ch)) {
                char base = isupper(ch) ? 'A' : 'a';
                dMsg += char((ch - base - shiftValue + 26) % 26 + base);
            } else {
                dMsg += ch;
            }
        }
        return dMsg;
    }
};

bool encodePrompt() {
    cout << "Do you want to encode a message? (yes/no): ";
    string response;
    cin >> response;
    return response == "yes";
}

bool decodePrompt() {
    cout << "Do you want to decode a message? (yes/no): ";
    string response;
    cin >> response;
    return response == "yes";
}

string runEncode() {
    cout << "Enter the message to be encoded: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string message;
    getline(cin, message);
    int value;
    cout << "Enter a shift value (1-13) to encode the message accordingly: ";
    cin >> value;
    CaesarCipher cipher(value);
    return cipher.encode(message);
}

string runDecode() {
    cout << "Enter the message to be decoded: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    string message;
    getline(cin, message);
    int value;
    cout << "Enter your guess for the shift value (1-13) to decode the message: ";
    cin >> value;
    CaesarCipher cipher(value);
    return cipher.decode(message);
}

int main() {
    cout << "~~~~~~~~~~ Welcome to the Cipher Program! ~~~~~~~~~~\n\n";
    string encodedMessage, decodedMessage;
    if (encodePrompt()) {
        encodedMessage = runEncode();
        cout << "Encoded message: " << encodedMessage << "\n";
    }
    if (decodePrompt()) {
        decodedMessage = runDecode();
        cout << "Decoded message: " << decodedMessage << "\n";
    }
    cout << "Exiting the program.\n";
    return 0;
}
