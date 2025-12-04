#pragma once
#include "File.h"
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

template<typename T>
class TextFile : public File {
    std::map<int, size_t> indexes;
    int nextId = 1;

    public:
        TextFile() = default;
        TextFile(const std::string& filename) : File(filename) {
            updateIndexes();
        }
        ~TextFile() {
            removeAll();
        }

        void openForRead(std::ios_base::openmode mode) override {
            if (this->ifs.is_open()) {
                this->ifs.close();
            }
            this->ifs.open(this->filename, mode);
        }

        void openForWrite(std::ios_base::openmode mode) override {
            if (this->ofs.is_open()) {
                this->ofs.close();
            }
            this->ofs.open(this->filename, mode);
        }

        void openForReadAndWrite(std::ios_base::openmode mode) override {
            if (this->fs.is_open())
                this->fs.close();
            this->fs.open(this->filename, mode);
        }

        void updateIndexes() {
            indexes.clear();
            nextId = 1;

            std::ifstream file(this->filename);

            if (!file.is_open()) {
                std::ofstream newFile(this->filename);
                newFile.close();
                return;
            }

            size_t currentPos = 0;
            std::string objString;
            while (std::getline(file, objString)) {
                if (!objString.empty()) {
                    size_t firstSemicolon = objString.find(';');
                    if (firstSemicolon != std::string::npos) {
                        try {
                            std::string idStr = objString.substr(0, firstSemicolon);
                            if (!idStr.empty()) {
                                int objId = std::stoi(idStr);
                                
                                if (firstSemicolon + 1 < objString.length() && 
                                    objString[firstSemicolon + 1] == '0') {
                                    indexes[objId] = currentPos;

                                    if (objId >= nextId) {
                                        nextId = objId + 1;
                                    }
                                }
                            }
                        } catch (const std::exception&) {
                            // Пропускаем строки с невалидным ID
                        }
                    }
                }
                currentPos += objString.length() + 1;
            }
            file.close();
        }

        ArrayList<T> getAll() {
            std::ifstream file(this->filename);
            ArrayList<T> allObjects;

            if (!file.is_open())
                throw FileException(50, "не удалось открыть файл " + this->filename);
            
            for (const auto& [id, position] : indexes) {
                try {
                    std::string line;
                    file.seekg(position);
                    if (file.fail()) {
                        continue;
                    }
                    std::getline(file, line);
                    if (!line.empty()) {
                        std::istringstream iss(line);
                        T obj;
                        iss >> obj;
                        if (!obj.wasDeleted()) {
                            allObjects.push_back(obj);
                        }
                    }
                } catch (const std::exception&) {
                    continue;
                }
            }
            file.close();
            return allObjects;
        }

        T findById(int id) {
            std::ifstream file(this->filename);            
            T obj;
            
            if (!file.is_open())
                throw FileException(50, "не удалось открыть файл " + this->filename);

            if (indexes.find(id) == indexes.end())
                throw FileException(51, "oбъект с id " + std::to_string(id) + " не найден");

            std::string line;
            file.seekg(indexes[id]);
            if (file.fail()) {
                file.close();
                throw FileException(51, "не удалось прочитать объект с id " + std::to_string(id));
            }
            std::getline(file, line);
            if (!line.empty()) {
                std::istringstream iss(line);
                iss >> obj;
            }
            file.close();
            return obj;
        }

        void save(T& obj) {
            std::ofstream file(this->filename, std::ios::app);

            if (!file.is_open())
                throw FileException(50, "не удалось открыть файл " + this->filename);
            
            obj.setId(nextId);
            file.seekp(0, std::ios::end);
            size_t position = file.tellp();
            indexes[nextId++] = position;
            file << obj << std::endl;
            file.close();
        }

        void update(const T& obj) {
            if (indexes.find(obj.getId()) == indexes.end())
                throw FileException(51, "данный объект не найден");

            std::fstream file(this->filename, std::ios::in | std::ios::out);

            if (!file.is_open())
                throw FileException(50, "не удалось открыть файл " + this->filename);
            
            file.seekp(indexes[obj.getId()]);
            file << obj << std::endl;
            file.close();
        }

        void remove(int id) {
            if (indexes.find(id) == indexes.end())
                throw FileException(51, "oбъект с id " + std::to_string(id) + " не найден");

            std::fstream file(this->filename, std::ios::in | std::ios::out);
            if (!file.is_open()) 
                throw FileException(50, "не удалось открыть файл " + this->filename);
            
            size_t position = indexes[id];
            file.seekp(position);
            std::string line;
            std::getline(file, line);
            if (!line.empty()) {
                size_t firstSemicolon = line.find(';');
                if (firstSemicolon != std::string::npos) {
                    file.seekp(position + firstSemicolon + 1);
                    file << '1';
                    file.flush();
                }
            }
            indexes.erase(id);
            file.close();
        }

    private:
        void removeAll() {

            ArrayList<T> allLiveObjects = getAll();

            if (!allLiveObjects.empty()) {
                std::ofstream file(this->filename, std::ios::trunc);
                if (file.is_open()) {
                    for (size_t i = 0; i < allLiveObjects.size(); ++i) {
                        file << allLiveObjects[i] << std::endl;
                    }
                    file.close();
                }
            }
        }
};