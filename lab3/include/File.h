#pragma once
#include <string>
#include <fstream>
#include <utility>
#include "Exceptions.h"

class File {
    protected:
        std::string filename;
        std::ifstream in;
        std::ofstream out;
        std::fstream inout;

        void closeStreams() {
            if (in.is_open()) in.close();
            if (out.is_open()) out.close(); 
            if (inout.is_open()) inout.close();
        }

        void ensureFilenameSet() const {
            if (filename.empty())
                throw FileException(50, "имя файла не задано");
        }

    public:
        File() = default;
        File(std::string filename) : filename(std::move(filename)) {}
        virtual ~File() {
            if (in.is_open()) in.close();
            if (out.is_open()) out.close(); 
            if (inout.is_open()) inout.close();
        }

        const std::string& getFilename() const { return filename; }
        void setFilename(const std::string& newFilename) { filename = newFilename; }

};
