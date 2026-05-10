#pragma once
#include <ostream>
class Calorix {
	char* name;

public:
	std::ostream readFromFile(char* fileName);
	std::ifstream writeInFile(char* fileName);
};