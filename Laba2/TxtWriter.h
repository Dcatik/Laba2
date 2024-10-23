#pragma once
#include "IWriter.h"
#include "String.h"

class TxtWriter : public IWriter<String> {
public:
    void write(const std::string& fileName, const String& data) override;  // Запись данных в TXT
};
