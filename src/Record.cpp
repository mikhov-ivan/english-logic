#include "Globals.hpp"
#include "Record.hpp"
#include "String.hpp"

Record::Record(const std::string& _en, const std::string& _ru, const std::string& _tr) {
    logger.info("Record::Record(_en, _ru, _tr);");

    en = String(_en);
    ru = String(_ru);
    tr = String(_tr);
}

Record::~Record() {
    logger.info("Record::~Record();");
}

std::string Record::to_string() {
    std::string res = "";
    res += en.to_string();
    res += tr.to_string();
    res += " - " + ru.to_string();

    return res;
}
