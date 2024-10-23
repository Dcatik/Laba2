#include <iostream>
#include "String.h"
#include "TxtWriter.h"
#include "TxtReader.h"

int main() {
    String str1("Hello, everybody! JoJo jojo reference. ,flip-flop, flip - flop , ");
    String str2("My name is Ivan.");

    str1.printContent();
    str2.printContent();

    String concatenated = str1 + str2;
    std::cout << "Concatenated: " << concatenated << std::endl;
    std::cout << std::endl;

    String repeated = str1 * 2;
    std::cout << "Repeated: " << repeated << std::endl;
    std::cout << std::endl;

    bool equal = (str1 == str2);
    std::cout << "Strings are equal: " << (equal ? "Yes" : "No") << std::endl;
    std::cout << std::endl;

    equal = (str1 == str1);
    std::cout << "Strings are equal: " << (equal ? "Yes" : "No") << std::endl;
    std::cout << std::endl;

    int index = str1.findSubstring(String("name"));
    std::cout << "Index of 'name': " << index << std::endl;
    std::cout << std::endl;

    index = str2.findSubstring(String("name"));
    std::cout << "Index of 'name': " << index << std::endl;
    std::cout << std::endl;

    std::map<String, int> distribution = str1.wordDistribution();
    std::cout << "Word distribution:\n";
    for (auto& item : distribution) {
        std::cout << item.first << " - " << item.second << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Word distribution alphabetic:\n";
    str1.showWordDistributionAlphabetic();
    std::cout << std::endl;

    std::cout << "Word distribution next:\n";
    str1.showWordDistributionNext();
    std::cout << std::endl;

    std::cout << "Word distribution quantitative:\n";
    str1.showWordDistributionQuantitative();
    std::cout << std::endl;

    int wordCount = str1.countWords();
    std::cout << "Total words: " << wordCount << std::endl;
    std::cout << std::endl;

    TxtWriter writer;
    str1.saveToFile(writer, "output.txt");
    std::cout << std::endl;

    TxtReader reader;
    String loadedStr = str1.readFromFile(reader, "output.txt");
    std::cout << "Loaded from file: " << loadedStr << std::endl;
    std::cout << std::endl;

    return 0;
}