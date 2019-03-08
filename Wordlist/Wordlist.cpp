// Wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <Windows.h>

using namespace std;

int main()
{
	// DLL使用示例

	typedef int (*p_gen_chain_word)(const char* words[], int len, char* result[], char head, char tail, bool enable_loop);
	typedef int (*p_gen_chain_char)(const char* words[], int len, char* result[], char head, char tail, bool enable_loop);

	HMODULE CoreDLL = LoadLibrary(L"..\\Debug\\Core.dll");

	p_gen_chain_word gen_chain_word = p_gen_chain_word(GetProcAddress(CoreDLL, "gen_chain_word"));

	int len = 5;
	const char *words[] = {"ab", "bc", "ae", "ed", "dc"};
	char **result = new char *[len];
	
	int resultLen = gen_chain_word(words, len, result, 0, 0, false);

	for (int i = 0; i < resultLen; i++) {
		cout << result[i] << endl;
	}
	
	FreeLibrary(CoreDLL);
	return 0;
}

