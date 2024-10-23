#pragma once
#include "IReader.h"
#include "String.h"

class TxtReader : public IReader<String> {
public:
    String read(const std::string& fileName) override;  // Чтение данных из TXT
};
