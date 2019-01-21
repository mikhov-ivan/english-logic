#ifndef RECORD_HPP
#define RECORD_HPP

#include "String.hpp"

class Record {
public:
    Record(const std::string& _en, const std::string& _ru, const std::string& _tr);
    virtual ~Record();

    std::string to_string();

private:
    String en;
    String ru;
    String tr;
};

#endif
