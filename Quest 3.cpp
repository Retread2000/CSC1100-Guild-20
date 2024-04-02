#include <iostream>
#include <string>

using namespace std;

class CaesarCipher { //base class
    private:
        int shiftValue;

    protected:
        string encode(const string& message) { //encode message function
            string newMsg;
            for (int i = 0; i < message.size(); i++) { //iterate through message string
                if (int(message[i]) > 65 && int(message[i]) < 84) { //use ascii and shift value to create encoded string
                    newMsg[i] = char(message[i] + shiftValue);
                }
                else if (int(message[i]) > 83 && int(message[i]) < 91) { //condition for the letters at the end of alphabet
                    newMsg[i] = char(int(message[i]) - 19);
                }
            }
            return newMsg;
        }

    public:
        //constructor
        CaesarCipher(int value) : shiftValue(value) {}
        void setShiftValue(int value) { //setter
            shiftValue = value;
        }
        string decode(const string& message) { //decode message function
            string eMsg = encode(message);
            string dMsg;
            for (int i = 0; i < eMsg.size(); i++) {
                if (int(eMsg[i]) > 71 && int(eMsg[i]) < 91) { //use ascii and shift value to create decoded string
                    dMsg[i] = char(eMsg[i] - shiftValue);
                }
                else if (int(eMsg[i]) > 64 && int(eMsg[i]) < 72) { //condition for the letters at the beginning of alphabet
                    dMsg[i] = char(int(eMsg[i]) + 19);
                }
            }
            return dMsg;
        }
};

class Rot13Cipher : public CaesarCipher { //derived class
    public:
    Rot13Cipher() : CaesarCipher(13) {}
};

bool encodePrompt() {
    string uInput;
    bool p;
    cout << "Do you want to encode a new message? (y/n or yes/no): ";
    cin >> uInput;
    if (uInput == "y" || uInput == "yes" || uInput == "Yes") {
        p = true;
    }
    else if (uInput == "n" || uInput == "no" || uInput == "No") {
        p = false;
    }
    return p;
}

int main() { //work in progress
    cout << "~~~~~~~~~~ Welcome to Guild 20's Cipher Program! ~~~~~~~~~~\n\n";
    bool ePrompt = encodePrompt();
    if (ePrompt == true) {

    }
    else if (ePrompt == false) {

    }



}

