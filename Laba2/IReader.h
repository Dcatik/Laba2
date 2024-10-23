#pragma once
#include <string>

template<typename T>
class IReader {
public:
    virtual T read(const std::string& fileName) = 0;
    virtual ~IReader() = default;
};
