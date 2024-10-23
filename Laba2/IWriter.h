#pragma once
#include <string>

template<typename T>
class IWriter {
public:
    virtual void write(const std::string& fileName, const T& data) = 0;  // ������ ������ � ����
    virtual ~IWriter() = default;
};
