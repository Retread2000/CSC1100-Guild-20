#include <iostream>
#include <string>

using namespace std;

class CaesarCipher { //base class
    private:
        int shiftValue;

    protected:
        string encode(const string& message) { //encode message function
            string newMsg = "";
            for (int i = 0; i < message.size(); i++) { //iterate through message string
                if (int(message[i]) > 65 && int(message[i]) < 84) { //use ascii and shift value to create encoded string
                    newMsg.push_back(char(message[i] + shiftValue));
                }
                else if (int(message[i]) > 83 && int(message[i]) < 91) { //condition for the letters at the end of alphabet
                    newMsg.push_back(char(int(message[i]) - 19));
                }
            }
            return newMsg;
        }

    public:
        CaesarCipher(int value) : shiftValue(value) {} //constructor
        void setShiftValue(int value) { //setter
            shiftValue = value;
        }
        string getEncode(const string& message) {
            return encode(message);
        }
        string decode(const string& message) { //decode message function
            string eMsg = encode(message);
            string dMsg = "";
            if (!eMsg.empty()) {
                for (int i = 0; i < eMsg.size(); i++) {
                    if (int(eMsg[i]) > 71 && int(eMsg[i]) < 91) { //use ascii and shift value to create decoded string
                        dMsg += (char(eMsg[i] - shiftValue));
                    }
                    else if (int(eMsg[i]) > 64 && int(eMsg[i]) < 72) { //condition for the letters at the beginning of alphabet
                        dMsg += (char(int(eMsg[i]) + 19));
                    }
                }
            }
            else if (eMsg.empty()) {
                for (int i = 0; i < message.size(); i++) {
                    if (int(message[i]) > 71 && int(message[i]) < 91) { //use ascii and shift value to create decoded string
                        dMsg[i] = char(message[i] - shiftValue);
                    }
                    else if (int(message[i]) > 64 && int(message[i]) < 72) { //condition for the letters at the beginning of alphabet
                        dMsg[i] = char(int(message[i]) + 19);
                    }
                }
            }
            return dMsg;
        }
};

class Rot13Cipher : public CaesarCipher { //derived class
    public:
    //Rot13Cipher() : CaesarCipher(13) {}
};

bool encodePrompt() {
    string uInput = "";
    bool p = false;
    cout << "Do you want to encode a new message? (y/n or yes/no): ";
    cin >> uInput;
    bool condition = true;
    while (condition == true) {
        if (uInput == "y" || uInput == "Y" || uInput == "yes" || uInput == "Yes") {
            p = true;
            condition = false;
        }
        else if (uInput == "n" || uInput == "N" || uInput == "no" || uInput == "No") {
            p = false;
            condition = false;
        }
        else {
            cout << "Invalid input. Please enter y, n, yes, or no: ";
            condition = true;
            cin >> uInput;
        }
    }
    return p;
}

bool decodePrompt(bool e) {
    string uInput;
    bool p = false;
    if (!e) {
        cout << "Do you want to decode a message? (y/n or yes/no): ";
    }
    else if (e) {
        cout << "Do you want to decode the recently captured message? (y/n or yes/no): ";
    }
    cin >> uInput;
    if (uInput == "y" || uInput == "Y" || uInput == "yes" || uInput == "Yes") {
        p = true;
    }
    else if (uInput == "n" || uInput == "N" || uInput == "no" || uInput == "No") {
        p = false;
    }
    return p;
}

void runEncode() {
    string message;
    int value;
    cout << "Enter the message to be encoded: ";
    cin >> message;
    cout << "Enter a shift value (1-13) to encode the message accordingly: ";
    cin >> value;
    CaesarCipher cipher(value);
    cout << "Encoded message using Caesar Cipher (shift value " << value << "): " << cipher.getEncode(message) << endl;
}

void runDecode(bool e) {
    int value;
    string message;
    if (!e) {
        cout << "Enter the captured message: ";
        cin >> message;
    }
    cout << "Enter your guess for the shift value (1-13) to decode the message: ";
    cin >> value;
    cout << "Decoding message using Caesar Cipher:\n";
    CaesarCipher cipher(value);
    cout << "Encoded message: " << message << endl;
    cout << "Decoded message: " << cipher.decode(message) << endl;
}


int main() { //work in progress
    cout << "~~~~~~~~~~ Welcome to Guild 20's Cipher Program! ~~~~~~~~~~\n\n";
    bool ePrompt = true;
    bool dPrompt = true;
    while (ePrompt == true || dPrompt == true) {
        ePrompt = encodePrompt();
        if (ePrompt == true) {
            runEncode();
        }
        dPrompt = decodePrompt(ePrompt);
        if (dPrompt == true) {
            runDecode(ePrompt);
        }
    }
    cout << "The end.";
    return 0;
}

