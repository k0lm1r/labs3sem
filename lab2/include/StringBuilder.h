#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>

class StringBuilder
 {
    int size = 0;
    char* string = nullptr;

    public:
        StringBuilder() = default;
        StringBuilder(const char* string);
        StringBuilder(const StringBuilder& other);
        
        void setString(const char* str);
        bool operator!();
        StringBuilder operator+(const StringBuilder& other) const;
        StringBuilder operator+(const char* str) const;
        StringBuilder operator++(int);
        StringBuilder& operator++();
        StringBuilder operator--(int);
        StringBuilder& operator--();
        StringBuilder& operator=(const StringBuilder& other);
        StringBuilder& operator+=(const StringBuilder& other);
        bool operator>(const StringBuilder& other) const;
        bool operator<(const StringBuilder& other) const;
        StringBuilder operator()(int start, int end);
        char operator[](int index);

        friend StringBuilder operator+(const char* str, const StringBuilder& obj);
        friend std::ostream& operator<<(std::ostream& os, const StringBuilder& str);
        friend std::istream& operator>>(std::istream& is, StringBuilder& str);

        ~StringBuilder();
};