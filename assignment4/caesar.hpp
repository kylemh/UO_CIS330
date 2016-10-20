// caeser.hpp
// By: Kyle Holmberg
// CIS330
#ifndef CAESARCIPHER_H_
#define CAESARCIPHER_H_

#include <string>

#include "cipher.hpp"

using namespace std;

class CaesarCipher : public Cipher {
public:
	CaesarCipher();
	virtual ~CaesarCipher();
	virtual string encrypt(string &text);
	virtual string decrypt(string &text);

private:
	int rotation;
    virtual string rotate(string &text, int rotor);
};

#endif /* CAESARCIPHER_H_ */