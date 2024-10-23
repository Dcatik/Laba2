#include "String.h"

String::String() : length(0) {}

String::String(const std::string& str) : data(str.begin(), str.end()) {
    calculateLength();
}

String::String(const std::vector<char>& vec) : data(vec), length(vec.size()) {}

String::String(const char* str) : data(str, str + strlen(str)) {
    calculateLength();
}

void String::calculateLength() {
    length = data.size();
}

void String::printContent() const {
    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i];
    }
    std::cout << std::endl;
}

int String::findSubstring(const String& substring) const {
    int strLen = data.size();
    int subLen = substring.data.size();

    for (int i = 0; i <= strLen - subLen; i++) {
        int j;
        for (j = 0; j < subLen; j++) {
            if (data[i + j] != substring.data[j]) {
                break;
            }
        }
        if (j == subLen) {
            return i;
        }
    }
    return -1;
}

std::string String::toLower(const std::string& str) const {
    std::string lowerStr;
    for (int i = 0; i < str.size(); i++) {
        lowerStr += (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
    }
    return lowerStr;
}

std::map<String, int> String::wordDistribution() {
    std::map<String, int> distribution;
    std::string word;
    bool inWord = false;

    for (int i = 0; i < data.size(); i++) {
        if ((data[i] >= 'A' && data[i] <= 'Z') || (data[i] >= 'a' && data[i] <= 'z') ||
            (data[i] == '-' && i > 0 && i < data.size() - 1 &&
                ((data[i - 1] >= 'A' && data[i - 1] <= 'Z') || (data[i - 1] >= 'a' && data[i - 1] <= 'z')) &&
                ((data[i + 1] >= 'A' && data[i + 1] <= 'Z') || (data[i + 1] >= 'a' && data[i + 1] <= 'z')))) {
                word += data[i];
                inWord = true;
        }
        else if (inWord) {
            String lowerWord = String(toLower(word));
            distribution[lowerWord]++;
            word.clear();
            inWord = false;
        }
    }

    if (inWord) {
        String lowerWord = String(toLower(word));
        distribution[lowerWord]++;
    }

    return distribution;
}

void String::showWordDistributionAlphabetic() {
    std::map<String, int> distribution = wordDistribution();
    for (auto& item : distribution) {
        std::cout << item.first << " - " << item.second << std::endl;
    }
}

void String::showWordDistributionQuantitative() {
    std::map<String, int> result = wordDistribution();

    std::vector<String> words;
    std::vector<int> counts;

    for (auto& entry : result) {
        words.push_back(entry.first);
        counts.push_back(entry.second);
    }

    int index = words.size();

    for (int i = 0; i < index - 1; i++) {
        for (int j = 0; j < index - i - 1; j++) {
            if (counts[j] < counts[j + 1]) {
                String tempWord = words[j];
                int tempCount = counts[j];
                words[j] = words[j + 1];
                counts[j] = counts[j + 1];
                words[j + 1] = tempWord;
                counts[j + 1] = tempCount;
            }
        }
    }

    result.clear();
    for (int i = 0; i < index; i++) {
        result[words[i]] = counts[i];
        std::cout << words[i] << " - " << counts[i] << std::endl;
    }
}


void String::showWordDistributionNext() {
    std::map<String, int> distribution;
    std::vector<String> insertionOrder;
    std::string word;
    bool inWord = false;

    for (int i = 0; i < data.size(); i++) {
        if ((data[i] >= 'A' && data[i] <= 'Z') || (data[i] >= 'a' && data[i] <= 'z') ||
            (data[i] == '-' && i > 0 && i < data.size() - 1 &&
                ((data[i - 1] >= 'A' && data[i - 1] <= 'Z') || (data[i - 1] >= 'a' && data[i - 1] <= 'z')) &&
                ((data[i + 1] >= 'A' && data[i + 1] <= 'Z') || (data[i + 1] >= 'a' && data[i + 1] <= 'z')))) {
            word += data[i];
            inWord = true;
        }
        else if (inWord) {
            String lowerWord = String(toLower(word));
            if (distribution.find(lowerWord) == distribution.end()) {
                insertionOrder.push_back(lowerWord);
            }
            distribution[lowerWord]++;
            word.clear();
            inWord = false;
        }
    }

    if (inWord) {
        String lowerWord = String(toLower(word));
        if (distribution.find(lowerWord) == distribution.end()) {
            insertionOrder.push_back(lowerWord);
        }
        distribution[lowerWord]++;
    }

    for (const String& word : insertionOrder) {
        std::cout << word << " - " << distribution[word] << std::endl;
    }
}

int String::countWords() const {
    int count = 0;
    std::string word;
    bool inWord = false;

    for (int i = 0; i < data.size(); i++) {
        if ((data[i] >= 'A' && data[i] <= 'Z') || (data[i] >= 'a' && data[i] <= 'z') || data[i] == '-') {
            word += data[i];
            inWord = true;
        }
        else if (inWord) {
            count++;
            word.clear();
            inWord = false;
        }
    }

    if (inWord) {
        count++;
    }

    return count;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        data = other.data;
        length = other.length;
    }
    return *this;
}

String String::operator+(const String& other) const {
    String result;
    result.data = data;
    for (int i = 0; i < other.data.size(); i++) {
        result.data.push_back(other.data[i]);
    }
    result.calculateLength();
    return result;
}

String String::operator*(int times) const {
    String result;
    for (int i = 0; i < times; i++) {
        result = result + *this;
    }
    return result;
}

bool String::operator==(const String& other) const {
    return data == other.data;
}

int String::size() const {
    return length;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    for (int i = 0; i < str.data.size(); i++) {
        os << str.data[i];
    }
    return os;
}

bool String::operator<(const String& other) const {
    return data < other.data;
}

bool String::operator>(const String& other) const {
    return data > other.data;
}

void String::saveToFile(IWriter<String>& writer, const std::string& filename) const {
    writer.write(filename, *this);
}

String String::readFromFile(IReader<String>& reader, const std::string& filename) const {
    return reader.read(filename);
}
