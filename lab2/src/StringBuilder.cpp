#include "StringBuilder.h"

StringBuilder::StringBuilder(const StringBuilder& other) : size(other.size) {
    this->setString(other.string);
}

StringBuilder::StringBuilder(const char* string) {
    this->setString(string);
}

void StringBuilder::setString(const char* string) {
    this->size = strlen(string);
    this->string = new char[this->size + 1];
    strncpy(this->string, string, this->size);
    this->string[size] = '\0';
}

StringBuilder StringBuilder::operator+(const StringBuilder& other) const {
    return *this + other.string;
}

StringBuilder StringBuilder::operator+(const char* str) const {
    int capacity = size + strlen(str) + 1;
    char *newStr = new char[capacity];

    strncpy(newStr, string, size);
    strncpy(newStr + size, str, strlen(str));
    newStr[capacity - 1] = '\0';
    StringBuilder newString(newStr);

    delete[] newStr;
    return newString;
}

StringBuilder StringBuilder::operator++(int) {
    StringBuilder old = *this;
    ++(*this);
    return old;
}

StringBuilder& StringBuilder::operator++() {
    for (int i = 0; i < size; ++i)
        string[i]++;
    return *this;
}

StringBuilder StringBuilder::operator--(int) {
    StringBuilder old = *this;
    --(*this);
    return old;
}

StringBuilder& StringBuilder::operator--() {
    for (int i = 0; i < size; ++i)
        string[i]--;
    return *this;
}

StringBuilder& StringBuilder::operator=(const StringBuilder& other) {
    if (this != &other) {
        if (string != nullptr) delete[] string;
        setString(other.string);
        size = other.size;
    }
    return *this;
}

StringBuilder& StringBuilder::operator+=(const StringBuilder& other) {
    *this = *this + other;
    return *this;
}

bool StringBuilder::operator>(const StringBuilder& other) const {
    return strcmp(string, other.string) == 1;
}

bool StringBuilder::operator<(const StringBuilder& other) const {
    return strcmp(string, other.string) == -1;
}


bool StringBuilder::operator!() {
    return size == 0 || string == nullptr;
}

StringBuilder StringBuilder::operator()(int first, int last) {
    char *substr = new char[last - first + 1];
    std::copy(this->string + first, this->string + last, substr);
    substr[last - first] = '\0';
    StringBuilder newString(substr);
    delete[] substr;
    return newString;
}

char StringBuilder::operator[](int index) {
    return this->string[index];
}

StringBuilder operator+(const char* str, const StringBuilder& obj) {
    int capacity = obj.size + strlen(str) + 1;
    char *newStr = new char[capacity];
    
    strncpy(newStr, str, strlen(str));
    strncpy(newStr + strlen(str), obj.string, obj.size);
    newStr[capacity - 1] = '\0';
    StringBuilder newString(newStr);

    delete[] newStr;
    return newString;
}

std::ostream& operator<<(std::ostream& os, const StringBuilder& str) {
    for (int i = 0; i < str.size; ++i) os << str.string[i];
    return os;
}

std::istream& operator>>(std::istream& in, StringBuilder& str) {
    char string[50]; 
    in >> string;
    str.setString(string);
    return in;
}

StringBuilder::~StringBuilder() {
    if (string != nullptr) delete[] string;
}