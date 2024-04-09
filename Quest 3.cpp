#include <iostream>
#include <string>
#include <limits>
using namespace std;

class CaesarCipher { // base class
    private:
        int shiftValue;

    protected:
        string encode(const string& message) { // encode message method
            string newMsg = "";
            for (int i = 0; i < message.size(); i++) { // iterate through message string
                if (isalpha(message[i])) {
                    int n = char(message[i] + shiftValue);
                    if (isupper(message[i])) {
                        if (int(message[i] + shiftValue) > 90) { // adjust characters near the end of the alphabet
                            n = char(message[i] + shiftValue) - 26;
                        }
                        newMsg.push_back(char(n)); // add character to encoded string
                    }
                    else {
                        if (int(message[i] + shiftValue) > 122) {
                            n = char(message[i] + shiftValue) - 26;
                        }
                        newMsg.push_back(n); // add character to encoded string
                    }
                }
                else {
                    newMsg.push_back(' ');
                }
            }
            return newMsg;
        }

    public:
        CaesarCipher(int value) : shiftValue(value) {} // constructor
        void setShiftValue(int value) { // setter
            shiftValue = value;
        }
        string getEncode(const string& message) { // encode method getter
            return encode(message);
        }
        string decode(const string& eMsg) { // decode message method
            string dMsg = "";
            for (int i = 0; i < eMsg.size(); i++) { // iterate through message string
                if (isalpha(eMsg[i])) {
                    int n = char(eMsg[i] - shiftValue);
                    if (isupper(eMsg[i])) {
                        if (int(eMsg[i] - shiftValue) < 65) { // adjust characters near the beginning of the alphabet
                            n = char(eMsg[i] - shiftValue) + 26;
                        }
                        dMsg.push_back(n); //add character to decoded string
                    }
                    else {
                        if (int(eMsg[i] - shiftValue) < 97) {
                            n = char(eMsg[i] - shiftValue) + 26;
                        }
                        dMsg.push_back(n); //add character to decoded string
                    }
                }
                else {
                    dMsg.push_back(' ');
                }
            }
            return dMsg;
        }
};

class Rot13Cipher : public CaesarCipher { // derived class
    public:
    Rot13Cipher() : CaesarCipher(13) {}
};

int validateInteger() { // function: validate user input as integer
    int value;
    while (true) {
        cout << "Enter a shift value (1-13): ";
        cin >> value;
        if (cin.fail()) {
            cout << "Invalid input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (cin.gcount() > 1) {
                cout << "Invalid input. Please enter only an integer.\n";
                continue;
            }
            break;
        }
    }
    return value;
}

bool encodePrompt() { // function: prompt user whether to encode a message
    string uInput = "";
    bool p = false;
    cout << "Do you want to encode a new message? (y/n or yes/no): ";
    getline(cin, uInput);
    while (true) { // iterate loop until proper input is entered
        if (uInput == "y" || uInput == "Y" || uInput == "yes" || uInput == "Yes") {
            p = true;
            break;
        }
        else if (uInput == "n" || uInput == "N" || uInput == "no" || uInput == "No") {
            p = false;
            break;
        }
        else {
            cout << "Invalid input. Please enter y, n, yes, or no: ";
            getline(cin, uInput);
        }
    }
    return p;
}

bool decodePrompt(bool e) { // function: prompt user whether to decode a message
    string uInput;
    bool p = false;
    if (!e) {
        cout << "Do you want to decode a message? (y/n or yes/no): ";
    }
    else if (e) {
        cout << "Do you want to decode the recently captured message? (y/n or yes/no): ";
    }
    getline(cin, uInput);
    while (true) { // iterate loop until proper input is entered
        if (uInput == "y" || uInput == "Y" || uInput == "yes" || uInput == "Yes") {
            p = true;
            break;
        }
        else if (uInput == "n" || uInput == "N" || uInput == "no" || uInput == "No") {
            p = false;
            break;
        }
        else {
            cout << "Invalid input. Please enter y, n, yes, or no: ";
            getline(cin, uInput);
        }
    }
    return p;
}

string runEncode() { // function: prompt user and run encode method
    string message;
    int value;
    bool condition = true;
    while (condition) { // iterate loop until proper input is entered
        cout << "Enter the message to be encoded: ";
        getline(cin, message);
        bool error = false;
        for (int i = 0; i < message.size(); i++) {
            if (!isalpha(message[i]) && message[i] != ' ') {
                error = true;
                break;
            }
        }
        if (error) {
            cout << "Error: Please enter only alphabetic characters.\n";
        }
        else {
            condition = false;
        }
    }
    cout << "Choose an integer to encode the message accordingly.\n";
    value = validateInteger();
    if (value == 13) { 
        Rot13Cipher rot13; // create object to use for encoding
        cout << "Encoded message using Rot13 Cipher (shift value " << value << "): " << rot13.getEncode(message) << endl;
        return rot13.getEncode(message);
    }
    else {
        CaesarCipher cipher(value); // create object to use for encoding
        cout << "Encoded message using Caesar Cipher (shift value " << value << "): " << cipher.getEncode(message) << endl;
        return cipher.getEncode(message);
    }
}

void runDecode(bool e, const string msg) { // function: prompt user and run decode method
    int value;
    string eMessage;
    if (!e) {
        bool condition = true;
        while (condition) { // iterate loop until proper input is entered
            cout << "Enter the captured message: ";
            getline(cin, eMessage);
            bool error = false;
            for (int i = 0; i < eMessage.size(); i++) {
                if (!isalpha(eMessage[i]) && eMessage[i] != ' ') {
                    error = true;
                    break;
                }
            }
            if (error) {
                cout << "Error: Please enter only alphabetic characters.\n";
            }
            else {
                condition = false;
            }
        }
    }
    else {
        eMessage = msg;
    }
    bool decoding = true;
    string uInput;
    while (decoding) { // run loop until user is satisfied attempting decode
        cout << "What is your guess?\n";
        value = validateInteger();
        if (value == 13) {
            cout << "Decoding message using Rot13 Cipher:\n";
            Rot13Cipher rot13; // create object to use for decoding and print messages
            cout << "Encoded message: " << eMessage << endl;
            cout << "Decoded message: " << rot13.decode(eMessage) << endl;
        }
        else {
            cout << "Decoding message using Caesar Cipher:\n";
            CaesarCipher cipher(value); // create object to use for decoding and print messages
            cout << "Encoded message: " << eMessage << endl;
            cout << "Decoded message: " << cipher.decode(eMessage) << endl;
        }
        cout << "Is the decoded message correct? (y/n or yes/no): ";
        getline(cin, uInput);
        string uInput2;
        while (true) { // iterate loop until user enters proper input
            if (uInput == "y" || uInput == "Y" || uInput == "yes" || uInput == "Yes") {
                cout << "Congratulations! You decoded the message correctly.\n";
                decoding = false;
                break;
            }
            else if (uInput == "n" || uInput == "N" || uInput == "no" || uInput == "No") {
                cout << "Do you want to try again with a different shift value? (y/n or yes/no): ";
                getline(cin, uInput2);
                if (uInput2 == "y" || uInput2 == "Y" || uInput2 == "yes" || uInput2 == "Yes") {
                    break;
                }
                else if (uInput2 == "n" || uInput2 == "N" || uInput2 == "no" || uInput2 == "No") {
                    decoding = false;
                    break;
                }
                else {
                    cout << "Invalid input. Please enter y, n, yes, or no: ";
                }
            }
            else {
                cout << "Invalid input. Please enter y, n, yes, or no: ";
            }
        }
    }
}

int main() { // main function: displays welcome message & loops through program until exit condition is met
    cout << "~~~~~~~~~~ Welcome to Guild 20's Cipher Program! ~~~~~~~~~~\n\n";
    bool ePrompt = true;
    bool dPrompt = true;
    string msg;
    while (ePrompt || dPrompt ) {
        ePrompt = encodePrompt();
        if (ePrompt) {
            msg = runEncode();
        }
        dPrompt = decodePrompt(ePrompt);
        if (dPrompt) {
            runDecode(ePrompt, msg);
        }
    }
    cout << "Exiting the program.\n";
    return 0;
}
