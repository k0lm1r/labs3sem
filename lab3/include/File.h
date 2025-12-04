#pragma once
#include <string>
#include <fstream>

class File {
    std::string filename;
    std::ifstream in;
    std::ofstream out;
    std::fstream inout;

    public:
        File() = default;
        File(std::string filename) : filename(filename) {}
        ~File() {
            if (in.is_open()) in.close();
            if (out.is_open()) out.close(); 
            if (inout.is_open()) inout.close();
        }


};