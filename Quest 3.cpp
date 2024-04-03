#include <iostream>
#include <string>

using namespace std;

class CaesarCipher { // base class
    private:
        int shiftValue;

    protected:
        string encode(const string& message) { // encode message method
            string newMsg = "";
            for (int i = 0; i < message.size(); i++) { // iterate through message string
                newMsg.push_back(char(message[i] + shiftValue)); // add character to encoded string
                if (isupper(message[i])) {
                    if (newMsg[i] > 'Z') { // adjust characters near the end of the alphabet
                        newMsg[i] -= 26;
                    }
                }
                else {
                    if (newMsg[i] > 'z') {
                        newMsg[i] -= 26;
                    }
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
                dMsg.push_back(char(eMsg[i] - shiftValue)); //add character to decoded string
                if (isupper(eMsg[i])) {
                    if (dMsg[i] < 'A') { // adjust characters near the beginning of the alphabet
                        dMsg[i] += 26;
                    }
                }
                else {
                    if (dMsg[i] < 'a') {
                        dMsg[i] += 26;
                    }
                }
            }
            return dMsg;
        }
};

class Rot13Cipher : public CaesarCipher { // derived class
    public:
    Rot13Cipher() : CaesarCipher(13) {}
};

bool encodePrompt() { // function: prompt user whether to encode a message
    string uInput = "";
    bool p = false;
    cout << "Do you want to encode a new message? (y/n or yes/no): ";
    cin >> uInput;
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

            cin >> uInput;
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
    cin >> uInput;
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
            cin >> uInput;
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
        cin >> message;
        bool error = false;
        for (int i = 0; i < message.size(); i++) {
            if (!isalpha(message[i])) {
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
    cout << "Enter a shift value (1-13) to encode the message accordingly: ";
    cin >> value;
    CaesarCipher cipher(value); // create object to use for encoding
    cout << "Encoded message using Caesar Cipher (shift value " << value << "): " << cipher.getEncode(message) << endl;
    return cipher.getEncode(message);
}

void runDecode(bool e, const string msg) { // function: prompt user and run decode method
    int value;
    string eMessage;
    if (!e) {
        bool condition = true;
        while (condition) { // iterate loop until proper input is entered
            cout << "Enter the captured message: ";
            cin >> eMessage;
            bool error = false;
            for (int i = 0; i < eMessage.size(); i++) {
                if (!isalpha(eMessage[i])) {
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
        cout << "Enter your guess for the shift value (1-13) to decode the message: ";
        cin >> value;
        cout << "Decoding message using Caesar Cipher:\n";
        CaesarCipher cipher(value); // create object to use for decoding and print messages
        cout << "Encoded message: " << eMessage << endl;
        cout << "Decoded message: " << cipher.decode(eMessage) << endl;
        cout << "Is the decoded message correct? (y/n or yes/no): ";
        cin >> uInput;
        string uInput2;
        while (true) { // iterate loop until user enters proper input
            if (uInput == "y" || uInput == "Y" || uInput == "yes" || uInput == "Yes") {
                cout << "Congratulations! You decoded the message correctly.\n";
                decoding = false;
                break;
            }
            else if (uInput == "n" || uInput == "N" || uInput == "no" || uInput == "No") {
                cout << "Do you want to try again with a different shift value? (y/n or yes/no): ";
                cin >> uInput2;
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
    while (ePrompt == true || dPrompt == true) {
        ePrompt = encodePrompt();
        if (ePrompt == true) {
            msg = runEncode();
        }
        dPrompt = decodePrompt(ePrompt);
        if (dPrompt == true) {
            runDecode(ePrompt, msg);
        }
    }
    cout << "Exiting the program.\n";
    return 0;
}

