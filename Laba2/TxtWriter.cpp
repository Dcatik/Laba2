#include "TxtWriter.h"
#include <fstream>
#include <stdexcept>

void TxtWriter::write(const std::string& fileName, const String& data) {
    std::ofstream file(fileName);
    if (!file) {
        throw std::runtime_error("Ошибка при открытии файла для записи: " + fileName);
    }

    // Запись данных в файл
    file << data;
}
