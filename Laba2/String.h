#pragma once
#include <string>
#include "IReader.h"
#include "IWriter.h"

class String {
private:
	char* date;
	int str_lenght;
public:
	String();
	String(IReader reader, std::string filename);
	String(std::string string);
	template<typename str>
	void operator=(str other);
	~String();

	void Print();
	int Find(String str, String aim);
};