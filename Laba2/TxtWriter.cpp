#include "TxtWriter.h"
#include <fstream>
#include <stdexcept>

void TxtWriter::write(const std::string& fileName, const String& data) {
    std::ofstream file(fileName);
    if (!file) {
        throw std::runtime_error("������ ��� �������� ����� ��� ������: " + fileName);
    }

    // ������ ������ � ����
    file << data;
}
