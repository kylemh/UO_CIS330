// date.hpp
// By: Kyle Holmberg
// CIS330
#ifndef DATE_H_
#define DATE_H_

#include <stdio.h>
#include <string>

#include "cipher.hpp"

using namespace std;

class DateCipher : public Cipher {
public:
    DateCipher();
    virtual ~DateCipher();
    virtual string encrypt(string &text);
    virtual string decrypt(string &text);

private:
    string date;
    bool forward;
    virtual string rotate(string &text, string &dateNums, bool forward);
};

#endif /* DATE_H_ */