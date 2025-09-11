#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>

struct point {
    int x;
    int y;
};

struct rectangle {
    point top_left;
    point bottom_right;
};

std::string to_upper(const std::string& s);
std::string to_lower(const std::string& s);
std::vector<std::string> split(const std::string& s, char delim);
std::string trim(const std::string& s);

#endif // MAIN_H

