// date.cpp
// By: Kyle Holmberg
// CIS330
#include <string>

#include "cipher.hpp"
#include "date.hpp"

using namespace std;

//CONSTRUCTOR
DateCipher::DateCipher() : Cipher(), date("040992") {}

DateCipher::~DateCipher() {}

//OVERLOAD ENCRYPT METHOD
string DateCipher::rotate(string &input, string &dateNums, bool forward) {
    string text = input;
    string::size_type size = text.length();

    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if ((text[i] >= 'a' && text[i] <= 'z')) { // inside lowercase alphabet
            int index = counter % dateNums.length();
            counter++;
            int modRotor = date[index] - '0';
            if (!forward) {
                modRotor = -modRotor;
            }
            int character = text[i] + modRotor;
            if (character > 'z') {
                int fubar = character - 'z';
                character = 'a' + fubar - 1;
            }
            else if (character < 'a') {
                int fubar = 'a' - character;
                character = 'z' - fubar + 1;
            }
            text[i] = character;            

        } else if(text[i] >= 'A' && text[i] <= 'Z') { // INSIDE UPPERCASE ALPHABET
            int index = counter % dateNums.length();
            counter++;
            int modRotor = date[index] - '0';
            if (!forward) {
                modRotor = -modRotor;
            }
            int character = text[i] + modRotor;
            if (character > 'Z') {
                int fubar = character - 'Z';
                character = 'A' + fubar - 1;
            } else if (character < 'A') {
                int fubar = 'A' - character;
                character = 'Z' - fubar + 1;
            }
            text[i] = character;
        }
    }
    return text;
}

string DateCipher::encrypt(string &text) {
    return this->rotate(text, date, true);
}

string DateCipher::decrypt(string &text) {
    return this->rotate(text, date, false);
}