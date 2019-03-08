#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
#include <set>

#if !defined (PREPROCESS_H) 
#define PREPROCESS_H

enum  Kind
{
	W, C, RW, RC
};

class Preprocess {
public:

	std::set<std::string> readfile(char *filename);
	void command(int argc, char *argv[]);
	char** change(std::set<std::string> strSet, int *length);
	void write(char *result[], int length);

	char head = 0;
	char tail = 0;
	char filename[256];
	Kind kind = W;
};

#endif
