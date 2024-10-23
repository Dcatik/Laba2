#pragma once
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <map>
#include "IStringOperation.h"
#include "IReader.h"
#include "IWriter.h"

class String {
private:
    std::vector<char> data;
    int length;

    void calculateLength();
    std::string toLower(const std::string& str) const;
public:
    String();
    String(const std::string& str);
    String(const std::vector<char>& vec);
    String(const char* str);

    void printContent() const;
    int findSubstring(const String& substring) const;
    std::map<String, int> wordDistribution();
    void showWordDistributionAlphabetic();
    void showWordDistributionNext();
    void showWordDistributionQuantitative();
    int countWords() const;

    String& operator=(const String& other);
    String operator+(const String& other) const;
    String operator*(int times) const;
    bool operator==(const String& other) const;
    bool operator<(const String& other) const;
    bool operator>(const String& other) const;

    int size() const;

    friend std::ostream& operator<<(std::ostream& os, const String& str);

    void saveToFile(IWriter<String>& writer, const std::string& filename) const;
    String readFromFile(IReader<String>& reader, const std::string& filename) const;

    ~String() = default;
};
