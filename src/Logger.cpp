#include "Logger.hpp"

Logger::Logger() {
    output.open("log");
    count = 1;
}

Logger::~Logger() {
    output.close();
}

void Logger::print(const std::string& str) {
    output << str;
    count++;
}

void Logger::info(const std::string& str) {
    output << "[INF] " << str << std::endl;
    count++;
}
