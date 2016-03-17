// test-caesar.cpp
// By: Kyle Holmberg
// CIS330
#include <iostream>
#include <fstream>

#include "ioutils.hpp"
#include "caesar.hpp"
#include "cipher.hpp"

using namespace std;

int main(int argc, const char *argv[]) {
    IOUtils io;
    CaesarCipher caesar;
    io.openStream(argc,argv);
    string input, encrypted, decrypted;
    input = io.readFromStream();

    cout << "Original text:" << endl << input;
    encrypted = caesar.encrypt(input);
    cout << "Encrypted text:" << endl << encrypted;
    decrypted = caesar.decrypt(encrypted);
    cout << "Decrypted text:" << endl << decrypted;
    
    if (decrypted == input) {
        cout << "Decrypted text matches input!" << endl;
    } else {
        cout << "Oops! Decrypted text doesn't match input!" << endl;
        return 1; 
    }
    return 0;
}