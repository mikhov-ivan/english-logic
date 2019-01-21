#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>

class Logger {
public:
    Logger();
    virtual ~Logger();

    void print(const std::string& str);
    void info(const std::string& str);

private:
    std::ofstream output;
    long count;
};

#endif
