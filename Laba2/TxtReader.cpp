#include "TxtReader.h"
#include <fstream>
#include <stdexcept>

String TxtReader::read(const std::string& fileName) {
    std::ifstream file(fileName);
    String result;
    if (!file) {
        throw std::runtime_error("Ошибка при открытии файла: " + fileName);
    }

    std::string line;
    while (std::getline(file, line)) {
        result = result + String(line);
    }
    return result;
}
