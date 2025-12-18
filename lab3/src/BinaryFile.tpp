#pragma once

#include "BinaryFile.h"

template <typename T>
void BinaryFile<T>::write(const std::vector<T>& data, bool append) {
    const char* raw = reinterpret_cast<const char*>(data.data());
    writeRawBytes(raw, data.size() * sizeof(T), append);
}

template <typename T>
std::vector<T> BinaryFile<T>::readAll() {
    this->ensureFilenameSet();
    this->closeStreams();
    this->in.open(this->filename, std::ios::binary);
    if (!this->in.is_open())
        throw FileException(63, "не удалось открыть бинарный файл для чтения");
    this->in.seekg(0, std::ios::end);
    std::streamsize size = this->in.tellg();
    if (size < 0)
        throw FileException(64, "не удалось определить размер бинарного файла");
    this->in.seekg(0, std::ios::beg);

    if (size % static_cast<std::streamsize>(sizeof(T)) != 0)
        throw FileException(69, "размер файла не кратен размеру элемента");
    std::size_t count = static_cast<std::size_t>(size) / sizeof(T);

    std::vector<T> buffer(count);
    if (size > 0) {
        this->in.read(reinterpret_cast<char*>(buffer.data()), size);
        if (!this->in)
            throw FileException(65, "ошибка чтения из бинарного файла");
    }
    this->in.close();
    return buffer;
}

template <typename T>
void BinaryFile<T>::writeOne(const T& value, bool append) {
    writeRawBytes(reinterpret_cast<const char*>(&value), sizeof(T), append);
}

template <typename T>
T BinaryFile<T>::readOne(std::streamoff offset) {
    this->ensureFilenameSet();
    this->closeStreams();
    this->in.open(this->filename, std::ios::binary);
    if (!this->in.is_open())
        throw FileException(66, "не удалось открыть бинарный файл для чтения");
    if (offset != 0 && !this->in.seekg(offset))
        throw FileException(67, "ошибка позиционирования при чтении бинарного файла");
    T value{};
    this->in.read(reinterpret_cast<char*>(&value), sizeof(T));
    if (!this->in)
        throw FileException(68, "ошибка чтения из бинарного файла");
    this->in.close();
    return value;
}

template <typename T>
void BinaryFile<T>::writeRawBytes(const char* data, std::size_t byteSize, bool append) {
    this->ensureFilenameSet();
    this->closeStreams();
    std::ios::openmode mode = std::ios::binary | std::ios::out;
    if (append) mode |= std::ios::app;
    this->out.open(this->filename, mode);
    if (!this->out.is_open())
        throw FileException(61, "не удалось открыть бинарный файл для записи");

    if (byteSize > 0) {
        this->out.write(data, static_cast<std::streamsize>(byteSize));
        if (!this->out)
            throw FileException(62, "ошибка записи в бинарный файл");
    }
    this->out.close();
}
