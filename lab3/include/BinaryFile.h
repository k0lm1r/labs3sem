#pragma once
#include <vector>
#include <cstddef>
#include "File.h"

template <typename T>
class BinaryFile : public File {
    public:
        using File::File;

        void write(const std::vector<T>& data, bool append = false);
        std::vector<T> readAll();
        void writeOne(const T& value, bool append = false);
        T readOne(std::streamoff offset = 0);

    private:
        void writeRawBytes(const char* data, std::size_t byteSize, bool append);
};

#include "BinaryFile.tpp"
