// Wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Preprocess.h"
#include <Windows.h>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	typedef int (*p_gen_chain_word)(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
	typedef int (*p_gen_chain_char)(char* words[], int len, char* result[], char head, char tail, bool enable_loop);

	HMODULE CoreDLL = LoadLibrary(L"Core.dll");

	if (CoreDLL == nullptr) {
		cerr << "未找到Core.dll" << endl;
		return -1;
	}

	p_gen_chain_word gen_chain_word = p_gen_chain_word(GetProcAddress(CoreDLL, "gen_chain_word"));
	p_gen_chain_char gen_chain_char = p_gen_chain_char(GetProcAddress(CoreDLL, "gen_chain_char"));

	if (gen_chain_char == nullptr || gen_chain_word == nullptr) {
		cerr << "无效的Core.dll" << endl;
		return -1;
	}
	
	try
	{
		Preprocess pre;
		pre.command(argc, argv);

		set<string> stringSet = pre.readfile(pre.filename);

		int length;
		char **words = pre.change(stringSet, &length);

		char **ans = new char *[length];
		int anslen = 0;
		bool loop = false;
		if (pre.kind == RC || pre.kind == RW)
			loop = true;
		if (pre.kind == C || pre.kind == RC) {
			anslen = gen_chain_char(words, length, ans, pre.head, pre.tail, loop);
		}
		else {
			anslen = gen_chain_word(words, length, ans, pre.head, pre.tail, loop);
		}

		pre.write(ans, anslen);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
	}

	FreeLibrary(CoreDLL);

	return 0;
}

