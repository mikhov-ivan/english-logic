#include "Globals.hpp"
#include "Logger.hpp"
#include "Record.hpp"
#include "String.hpp"

#include <fstream>
#include <stdlib.h>
#include <iostream>

#include <sys/time.h>
#include <ctime>


static long get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);

    long res = tv.tv_usec;
    res /= 1000;
    res += tv.tv_sec * 1000;

    return res;
}

Logger logger;

int main() {
    long start_tv = get_time();

    std::ifstream input;
    input.open("input");

    std::string str;
    input >> str;
    input.close();

    Record r(str, str, str);

    long stop_tv = get_time();
    std::cout << "[INFO] Execution time: " << " " << (stop_tv - start_tv) << " ms" << std::endl;

    return 0;
}
