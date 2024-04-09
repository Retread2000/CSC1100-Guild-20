#include <iostream>
#include <string>
#include <algorithm> 
#include <limits>

using namespace std;

class CaesarCipher {
    private:
        int shiftValue;

    protected:
        string encode(const string& message) {
    string newMsg = "";
    for (char c : message) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            newMsg += char(((c + shiftValue - base) % 26) + base);
        } else {
            
            newMsg += c; 
        }
    }
    return newMsg;
}

    public:
        CaesarCipher(int value) : shiftValue(value) {} 
        void setShiftValue(int value) { 
            shiftValue = value;
        }
        string getEncode(const string& message) { 
            return encode(message);
        }
        string decode(const string& eMsg) {
    string dMsg = "";
    for (char c : eMsg) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            dMsg += char(((c - shiftValue - base + 26) % 26) + base); 
        } else {
            
            dMsg += c;
        }
    }
    return dMsg;
}
};

class Rot13Cipher : public CaesarCipher { 
    public:
    Rot13Cipher() : CaesarCipher(13) {}
};

bool encodePrompt() { 
    string uInput = "";
    bool p = false;
    cout << "Do you want to encode a new message? (y/n or yes/no): ";
    while (true) { 
        getline(cin, uInput); 
        transform(uInput.begin(), uInput.end(), uInput.begin(), ::tolower);
        if (uInput == "y" || uInput == "yes") {
            p = true;
            break;
        } else if (uInput == "n" || uInput == "no") {
            p = false;
            break;
        } else {
            cout << "Invalid input. Please enter y, n, yes, or no: ";
        }
    }
    return p;
}


bool decodePrompt(bool e) { 
    string uInput;
    bool p = false;
    if (!e) {
        cout << "Do you want to decode a message? (y/n or yes/no): ";
    } else {
        cout << "Do you want to decode the recently captured message? (y/n or yes/no): ";
    }
    while (true) { 
        getline(cin, uInput); 
        
        transform(uInput.begin(), uInput.end(), uInput.begin(), ::tolower);
        if (uInput == "y" || uInput == "yes") {
            p = true;
            break;
        } else if (uInput == "n" || uInput == "no") {
            p = false;
            break;
        } else {
            cout << "Invalid input. Please enter y, n, yes, or no: ";
        }
    }
    return p;
}

string runEncode() {
    string message;
    int value;
    bool condition = true;

    while (condition) {
        cout << "Enter the message to be encoded (only alphabetic characters): ";
        getline(cin, message); 

        
        bool error = any_of(message.begin(), message.end(), [](char c) { return !isalpha(c) && !isspace(c); });

        if (error) {
            cout << "Error: Please enter only alphabetic characters.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            condition = false;
        }
    }

    cout << "Enter a shift value (1-26) to encode the message accordingly: ";
    while (!(cin >> value) || value < 1 || value > 26) {
        cout << "Invalid input. Please enter a number between 1 and 26: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }

    CaesarCipher cipher(value); 
    string encodedMessage = cipher.getEncode(message);
    cout << "Encoded message using Caesar Cipher (shift value " << value << "): " << encodedMessage << endl;
    return encodedMessage;
}


void runDecode(bool e, const string msg) { 
    int value;
    string eMessage;
    if (!e) {
        bool condition = true;
        while (condition) { 
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
    while (decoding) { 
        cout << "Enter your guess for the shift value (1-13) to decode the message: ";
        cin >> value;
        cout << "Decoding message using Caesar Cipher:\n";
        CaesarCipher cipher(value); 
        cout << "Encoded message: " << eMessage << endl;
        cout << "Decoded message: " << cipher.decode(eMessage) << endl;
        cout << "Is the decoded message correct? (y/n or yes/no): ";
        cin >> uInput;
        string uInput2;
        while (true) { 
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

int main() { 
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