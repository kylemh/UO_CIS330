// cipher.hpp
// By: Kyle Holmberg
// CIS330
#ifndef CIPHER_HPP_
#define CIPHER_HPP_

#include <string>

using namespace std;

class Cipher {
public:
	Cipher() {}
	~Cipher() {}

	//Encrypt
	virtual string encrypt(string &text) = 0;

	//Decrypt
	virtual string decrypt(string &text) = 0;
};

#endif /* CIPHER_HPP_ */