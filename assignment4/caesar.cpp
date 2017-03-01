// caesar.cpp
// By: Kyle Holmberg
// CIS330
#include <string>

#include "cipher.hpp"
#include "caesar.hpp"

using namespace std;

//CONSTRUCTOR
CaesarCipher::CaesarCipher() : Cipher(), rotation(2) {}

CaesarCipher::~CaesarCipher() {}

//OVERLOAD ENCRYPT METHOD
string CaesarCipher::rotate(string &input, int rotor) {
	string text = input;
	string::size_type size = text.length();

	for (int i = 0; i < size; ++i) {
        if (text[i] >= 'a' && text[i] <= 'z'){ // inside lowercase alphabet
            int character = text[i] + rotor;
            if (character > 'z') {
                int fubar = character - 'z';
                if (fubar == 1) {
                    character = ' ';
                } else {
                  character = 'a' + fubar - 2;
                }
            } else if (character < 'a') {
                int fubar = 'a' - character;
                if (fubar == 1) {
                    character = ' ';
                } else {
                    character = 'z' - fubar + 2;
                }
            }
            
            text[i] = character;
            
        } else if(text[i] >= 'A' && text[i] <= 'Z') { // INSIDE UPPERCASE ALPHABET
            int character = text[i] + rotor;
            if (character > 'Z') {
                int fubar = character - 'Z';
                if (fubar == 1) {
                    character = ' ';
                } else {
                    character = 'A' + fubar - 2;
                }
            } else if (character < 'A') {
                int fubar = 'A' - character;
                if (fubar == 1) {
                    character = ' ';
                } else {
                    character = 'Z' - fubar + 2;
                }
            }
            text[i] = character;
        } else if (text[i] == ' ') {
            if (rotor > 0) {
                text[i] = 'a' + rotor - 1;
            } else {
                text[i] = 'z' + rotor + 1;
            }
        }
	}
	return text;
}

string CaesarCipher::encrypt(string &text) {
    return this->rotate(text, rotation);
}

string CaesarCipher::decrypt(string &text) {
    return this->rotate(text, -rotation);
}