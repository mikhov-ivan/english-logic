#ifndef STRING_HPP
#define STRING_HPP

#include <string>
#include <vector>

class String {
private:
struct Char;

public:
    String();
    String(const std::string& _str);
    virtual ~String();

    unsigned int length() const;
    std::string to_string();

    Char& operator[](int i) const;
    void operator=(const String& rhs);
    String* operator+(const String& rhs) const;

private:
    struct Char {
        char byte_1;
        char byte_2;

        void operator=(const Char& rhs) {
            byte_1 = rhs.byte_1;
            byte_2 = rhs.byte_2;
        }
    };
    
    Char* str;
    unsigned int len;
};

#endif
