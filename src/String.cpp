#include "Globals.hpp"
#include "String.hpp"

String::String() {
    logger.info("String::String();");

    str = NULL;
    len = 0;
}

String::String(const std::string& _str) {
    logger.info("String::String(_str);");

    char mask_11000000 = (char) 0xC0;
    char mask_10000000 = (char) 0x80;

    Char ch;
    unsigned int real_len = 0;
    unsigned int byte_size = _str.length();
    for (unsigned int i = 0; i < byte_size; i++) {
        if (((_str[i] & mask_11000000) == mask_11000000)
            || ((_str[i] & mask_10000000) == 0)) {
            real_len++;
        }
    }

    len = real_len;
    str = new Char[len];
    unsigned int cur = 0;
    for (unsigned int i = 0; i < byte_size; i++) {
        if ((_str[i] & mask_11000000) == mask_11000000) {
            ch.byte_1 = _str[i];
            ch.byte_2 = _str[i + 1];
            i++;
        } else if ((_str[i] & mask_10000000) == 0) {
            ch.byte_1 = 0;
            ch.byte_2 = _str[i];
        } else {
            ch.byte_1 = ch.byte_2 = 0;
        }

        str[cur] = ch;
        cur++;
    }
}

String::~String() {
    logger.info("String::~String();");
    delete[] str;
}

String::Char& String::operator[](int i) const {
    if (i < 0 || i > (int) len) {
        // TODO: Throw IndexOutOfBounds Exception
    }

    return str[i];
}

void String::operator=(const String& rhs) {
    if (len < rhs.len) {
        delete[] str;
        
        str = new Char[rhs.len];
        len = rhs.len;
    }

    for (unsigned int i = 0; i < rhs.len; i++) {
        str[i] = rhs[i];
    }
}

String* String::operator+(const String& rhs) const {
    String* res = new String();
    res->len = len + rhs.len;
    res->str = new Char[res->len];

    for (unsigned int i = 0; i < len; i++) {
        res->str[i] = str[i];
    }

    for (unsigned int i = 0; i < rhs.len; i++) {
        res->str[len + i] = rhs.str[i];
    }

    return res;
}

unsigned int String::length() const {
    return len;
}

std::string String::to_string() {
    std::string _str = "";
    for (unsigned int i = 0; i < len; i++) {
        if (str[i].byte_1) _str += str[i].byte_1;
        if (str[i].byte_2) _str += str[i].byte_2;
    }

    return _str;
}
