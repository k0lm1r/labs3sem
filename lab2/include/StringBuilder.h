#pragma once
#include <iostream>
#include <algorithm>

class StringBuilder {
    int size;
    char* string;

    public:
        StringBuilder() = default;
        StringBuilder(const int size) : size(size) {}
        StringBuilder(const StringBuilder& other);

        void setString(const char* string);
        bool operator!();
        StringBuilder operator()(int start, int end);
        char operator[](int index);

        friend std::ostream& operator<<(std::ostream& os, const StringBuilder& str);
        friend std::istream& operator>>(std::istream& is, StringBuilder& str);

        ~StringBuilder();
};