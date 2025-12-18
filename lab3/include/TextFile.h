#pragma once
#include <vector>
#include "File.h"

template <typename T>
class TextFile : public File {
    public:
        using File::File;

        void write(const T& value, bool append = false);
        void writeLines(const std::vector<T>& values, bool append = false);
        T read();
        std::vector<T> readAll();
};

#include "../src/TextFile.tpp"
