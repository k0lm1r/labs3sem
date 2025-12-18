#pragma once

#include "TextFile.h"

template <typename T>
void TextFile<T>::write(const T& value, bool append) {
    this->ensureFilenameSet();
    this->closeStreams();
    std::ios::openmode mode = std::ios::out;
    if (append) mode |= std::ios::app;
    this->out.open(this->filename, mode);
    if (!this->out.is_open())
        throw FileException(51, "не удалось открыть текстовый файл для записи");
    this->out << value;
    if (!this->out.good())
        throw FileException(52, "ошибка записи в текстовый файл");
    this->out.close();
}

template <typename T>
void TextFile<T>::writeLines(const std::vector<T>& values, bool append) {
    this->ensureFilenameSet();
    this->closeStreams();
    std::ios::openmode mode = std::ios::out;
    if (append) mode |= std::ios::app;
    this->out.open(this->filename, mode);
    if (!this->out.is_open())
        throw FileException(53, "не удалось открыть текстовый файл для записи");
    for (const auto& value : values) {
        this->out << value << '\n';
        if (!this->out.good())
            throw FileException(54, "ошибка записи в текстовый файл");
    }
    this->out.close();
}

template <typename T>
T TextFile<T>::read() {
    this->ensureFilenameSet();
    this->closeStreams();
    this->in.open(this->filename);
    if (!this->in.is_open())
        throw FileException(55, "не удалось открыть текстовый файл для чтения");
    T value{};
    this->in >> value;
    if (this->in.fail())
        throw FileException(56, "ошибка чтения из текстового файла");
    this->in.close();
    return value;
}

template <typename T>
std::vector<T> TextFile<T>::readAll() {
    this->ensureFilenameSet();
    this->closeStreams();
    this->in.open(this->filename);
    if (!this->in.is_open())
        throw FileException(57, "не удалось открыть текстовый файл для чтения");
    std::vector<T> result;
    T value{};
    while (this->in >> value) {
        result.push_back(value);
    }
    if (!this->in.eof())
        throw FileException(58, "ошибка чтения из текстового файла");
    this->in.close();
    return result;
}
