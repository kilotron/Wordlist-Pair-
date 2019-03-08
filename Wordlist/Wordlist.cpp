// Wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <ctype.h>
#include "Core.h"

using namespace std;

int main()
{
	int len = 5;
	const char *words[] = {"ab", "bc", "ae", "ed", "dc"};
	char **result = new char *[len];

	int resultLen = Core::gen_chain_word(words, len, result, 0, 0, false);

	for (int i = 0; i < resultLen; i++) {
		cout << result[i] << endl;
	}
	
	return 0;
}

