#include "stdafx.h"
#include "CppUnitTest.h"
#include <string.h>
#include <stdarg.h>
#include "../Core/Core.h"
#include <fstream>

#define TEST_INIT(_len, ...) int len = _len; int resultLen; char **result = new char *[len];\
							 char **words = ToWordsArray(_len, ##__VA_ARGS__)
							 

#define GEN_CHAIN_WORD(head, tail, enable_loop) \
		resultLen = Core::gen_chain_word(words, len, result, head, tail, enable_loop)

#define GEN_CHAIN_CHAR(head, tail, enable_loop) \
		resultLen = Core::gen_chain_char(words, len, result, head, tail, enable_loop)

#define ASSERT_RESULT_LEN(len) Assert::AreEqual(len, resultLen)

#define ASSERT_RESULT(expected, no) Assert::AreEqual(expected, result[no])

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CoreUnitTest1
{		
	// helper function
	char ** ToWordsArray(int length, ...)
	{
		char **words = new char *[length];
		va_list ap;
		va_start(ap, length);
		for (int i = 0; i < length; i++) {
			const char *word = va_arg(ap, char *);
			words[i] = new char[strlen(word) + 1];
			strcpy_s(words[i], strlen(word) + 1, word);
		}
		return words;
	}

	void outputResult(const char *filename, char **result, int resultLen)
	{
		std::ofstream fout(filename);
		for (int i = 0; i < resultLen; i++) {
			fout << result[i] << std::endl;
		}
		fout.close();
	}

	// 无环
	TEST_CLASS(UnitTest1)
	{
	public:
		// TestMethod1 和 TestMethod2 是题目中的样例

		TEST_METHOD(TestMethod1)
		{
			TEST_INIT(11, "Algebra", "Apple", "Zoo", "Elephant", "Under", "Fox",
				"Dog", "Moon", "Leaf", "Trick", "Pseudopseudohypoparathyroidism");
			
			GEN_CHAIN_WORD(0, 0, false);
			ASSERT_RESULT_LEN(4);
			ASSERT_RESULT("algebra", 0);
			ASSERT_RESULT("apple", 1);
			ASSERT_RESULT("elephant", 2);
			ASSERT_RESULT("trick", 3);

			GEN_CHAIN_CHAR(0, 0, false);
			ASSERT_RESULT_LEN(2);
			ASSERT_RESULT("pseudopseudohypoparathyroidism", 0);
			ASSERT_RESULT("moon", 1);

			GEN_CHAIN_WORD('e', 0, false);
			ASSERT_RESULT_LEN(2);
			ASSERT_RESULT("elephant", 0);
			ASSERT_RESULT("trick", 1);

			GEN_CHAIN_WORD(0, 't', false);
			ASSERT_RESULT_LEN(3);
			ASSERT_RESULT("algebra", 0);
			ASSERT_RESULT("apple", 1);
			ASSERT_RESULT("elephant", 2);
		}

		TEST_METHOD(TestMethod2) 
		{
			TEST_INIT(5, "Element", "Heaven", "Table", "Teach", "Talk");
			GEN_CHAIN_WORD(0, 0, true);
			ASSERT_RESULT_LEN(4);
			ASSERT_RESULT("table", 0);
			ASSERT_RESULT("element", 1);
			ASSERT_RESULT("teach", 2);
			ASSERT_RESULT("heaven", 3);
		}

		// 单词数最多, 不指定开头和结尾

		TEST_METHOD(TestMethod3)
		{
			TEST_INIT(22,
				"Absorb", "bailout", "basic", "cat", "team",
				"calm", "cad", "hedonism", "dam", "moon",
				"damn", "dame", "happen", "earn", "nap",
				"each", "equip", "pack", "hasp", "hack",
				"hot", "AGoddamnSuperLongWordEndsWithT");
			GEN_CHAIN_WORD(0, 0, false);
			ASSERT_RESULT_LEN(10);
			ASSERT_RESULT("absorb", 0);
			ASSERT_RESULT("basic", 1);
			ASSERT_RESULT("cad", 2);
			ASSERT_RESULT("dame", 3);
			ASSERT_RESULT("each", 4);
			ASSERT_RESULT("hot", 5);
			ASSERT_RESULT("team", 6);
			ASSERT_RESULT("moon", 7);
			ASSERT_RESULT("nap", 8);
			ASSERT_RESULT("pack", 9);
		}

		// 单词数最多，指定开头

		TEST_METHOD(TestMethod4)
		{
			TEST_INIT(22,
				"Absorb", "bailout", "basic", "cat", "team",
				"calm", "cad", "hedonism", "dam", "moon",
				"damn", "dame", "happen", "earn", "nap",
				"each", "equip", "pack", "hasp", "hack",
				"hot", "AGoddamnSuperLongWordEndsWithT");
			GEN_CHAIN_WORD('b', 0, false);
			ASSERT_RESULT_LEN(9);
			ASSERT_RESULT("basic", 0);
			ASSERT_RESULT("cad", 1);
			ASSERT_RESULT("dame", 2);
			ASSERT_RESULT("each", 3);
			ASSERT_RESULT("hot", 4);
			ASSERT_RESULT("team", 5);
			ASSERT_RESULT("moon", 6);
			ASSERT_RESULT("nap", 7);
			ASSERT_RESULT("pack", 8);
		}

		// 单词数最多，指定结尾

		TEST_METHOD(TestMethod5)
		{
			TEST_INIT(22,
				"Absorb", "bailout", "basic", "cat", "team",
				"calm", "cad", "hedonism", "dam", "moon",
				"damn", "dame", "happen", "earn", "nap",
				"each", "equip", "pack", "hasp", "hack",
				"hot", "AGoddamnSuperLongWordEndsWithT");
			GEN_CHAIN_WORD(0, 'n', false);
			ASSERT_RESULT_LEN(8);
			ASSERT_RESULT("absorb", 0);
			ASSERT_RESULT("basic", 1);
			ASSERT_RESULT("cad", 2);
			ASSERT_RESULT("dame", 3);
			ASSERT_RESULT("each", 4);
			ASSERT_RESULT("hot", 5);
			ASSERT_RESULT("team", 6);
			ASSERT_RESULT("moon", 7);
		}

		// 单词数最多，指定开头和结尾

		TEST_METHOD(TestMethod6)
		{
			TEST_INIT(22,
				"Absorb", "bailout", "basic", "cat", "team",
				"calm", "cad", "hedonism", "dam", "moon",
				"damn", "dame", "happen", "earn", "nap",
				"each", "equip", "pack", "hasp", "hack",
				"hot", "AGoddamnSuperLongWordEndsWithT");
			GEN_CHAIN_WORD('c', 'm', false);
			ASSERT_RESULT_LEN(5);
			ASSERT_RESULT("cad", 0);
			ASSERT_RESULT("dame", 1);
			ASSERT_RESULT("each", 2);
			ASSERT_RESULT("hot", 3);
			ASSERT_RESULT("team", 4);
		}

		// 字母最多，不指定开头结尾

		TEST_METHOD(TestMethod7)
		{
			TEST_INIT(22,
				"Absorb", "bailout", "basic", "cat", "team",
				"calm", "cad", "hedonism", "dam", "moon",
				"damn", "dame", "happen", "earn", "nap",
				"each", "equip", "pack", "hasp", "hack",
				"hot", "AGoddamnSuperLongWordEndsWithT");
			GEN_CHAIN_CHAR(0, 0, false);
			ASSERT_RESULT_LEN(5);
			ASSERT_RESULT("agoddamnsuperlongwordendswitht", 0);
			ASSERT_RESULT("team", 1);
			ASSERT_RESULT("moon", 2);
			ASSERT_RESULT("nap", 3);
			ASSERT_RESULT("pack", 4);
		}

		// 字母最多，指定开头

		TEST_METHOD(TestMethod8)
		{
			TEST_INIT(22,
				"Absorb", "bailout", "basic", "cat", "team",
				"calm", "cad", "hedonism", "dam", "moon",
				"damn", "dame", "happen", "earn", "nap",
				"each", "equip", "pack", "hasp", "hack",
				"hot", "AGoddamnSuperLongWordEndsWithT");
			GEN_CHAIN_CHAR('b', 0, false);
			ASSERT_RESULT_LEN(8);
			ASSERT_RESULT("basic", 0);
			ASSERT_RESULT("cad", 1);
			ASSERT_RESULT("dame", 2);
			ASSERT_RESULT("each", 3);
			ASSERT_RESULT("hedonism", 4);
			ASSERT_RESULT("moon", 5);
			ASSERT_RESULT("nap", 6);
			ASSERT_RESULT("pack", 7);
		}

		// 字母最多，指定开头和结尾

		TEST_METHOD(TestMethod9)
		{
			TEST_INIT(22,
				"Absorb", "bailout", "basic", "cat", "team",
				"calm", "cad", "hedonism", "dam", "moon",
				"damn", "dame", "happen", "earn", "nap",
				"each", "equip", "pack", "hasp", "hack",
				"hot", "AGoddamnSuperLongWordEndsWithT");
			GEN_CHAIN_CHAR('c', 'm', false);
			ASSERT_RESULT_LEN(4);
			ASSERT_RESULT("cad", 0);
			ASSERT_RESULT("dame", 1);
			ASSERT_RESULT("each", 2);
			ASSERT_RESULT("hedonism", 3);
		}
	};

	// 有环
	TEST_CLASS(UnitTest2)
	{
	public:

		// 单词数最多，不指定开头和结尾
		TEST_METHOD(TestMethod1)
		{
			TEST_INIT(7, "gag", "fag", "glitz", "zaf", "jof", "fij", "lkkj");
			GEN_CHAIN_WORD(0, 0, true);
			ASSERT_RESULT_LEN(7);
			ASSERT_RESULT("lkkj", 0);
			ASSERT_RESULT("jof", 1);
			ASSERT_RESULT("fag", 2);
			ASSERT_RESULT("gag", 3);
			ASSERT_RESULT("glitz", 4);
			ASSERT_RESULT("zaf", 5);
			ASSERT_RESULT("fij", 6);
		}

		// 单词数最多，指定开头
		TEST_METHOD(TestMethod2)
		{
			TEST_INIT(7, "gag", "fag", "glitz", "zaf", "jof", "fij", "lkkj");
			GEN_CHAIN_WORD('j', 0, true);
			ASSERT_RESULT_LEN(6);
			ASSERT_RESULT("jof", 0);
			ASSERT_RESULT("fag", 1);
			ASSERT_RESULT("gag", 2);
			ASSERT_RESULT("glitz", 3);
			ASSERT_RESULT("zaf", 4);
			ASSERT_RESULT("fij", 5);
		}

		// 单词数最多，指定结尾
		TEST_METHOD(TestMethod3)
		{
			TEST_INIT(7, "gag", "fag", "glitz", "zaf", "jof", "fij", "lkkj");
			GEN_CHAIN_WORD(0, 'z', true);
			ASSERT_RESULT_LEN(6);
			ASSERT_RESULT("zaf", 0);
			ASSERT_RESULT("fij", 1);
			ASSERT_RESULT("jof", 2);
			ASSERT_RESULT("fag", 3);
			ASSERT_RESULT("gag", 4);
			ASSERT_RESULT("glitz", 5);
		}

		// 单词数最多，指定开头和结尾
		TEST_METHOD(TestMethod4)
		{
			TEST_INIT(7, "gag", "fag", "glitz", "zaf", "jof", "fij", "lkkj");
			GEN_CHAIN_WORD('j', 'j', true);
			ASSERT_RESULT_LEN(6);
			ASSERT_RESULT("jof", 0);
			ASSERT_RESULT("fag", 1);
			ASSERT_RESULT("gag", 2);
			ASSERT_RESULT("glitz", 3);
			ASSERT_RESULT("zaf", 4);
			ASSERT_RESULT("fij", 5);
		}

		// 字母最多，不指定开头和结尾
		TEST_METHOD(TestMethod5)
		{
			TEST_INIT(9, "i", "xlonginsidei", "ilonginsidex","lx", "lxy", "rwy", "yvo", "oq", "qur");
			GEN_CHAIN_CHAR(0, 0, true);
			ASSERT_RESULT_LEN(4);
			ASSERT_RESULT("lx", 0);
			ASSERT_RESULT("xlonginsidei", 1);
			ASSERT_RESULT("i", 2);
			ASSERT_RESULT("ilonginsidex", 3);
		}

		// 字母最多，指定结尾
		TEST_METHOD(TestMethod6)
		{
			TEST_INIT(9, "i", "xlonginsidei", "ilonginsidex", "lx", "lxy", "rwy", "yvo", "oq", "qur");
			GEN_CHAIN_CHAR(0, 'y', true);
			ASSERT_RESULT_LEN(5);
			ASSERT_RESULT("lxy", 0);
			ASSERT_RESULT("yvo", 1);
			ASSERT_RESULT("oq", 2);
			ASSERT_RESULT("qur", 3);
			ASSERT_RESULT("rwy", 4);
		}

		// 字母最多，指定开头和结尾
		TEST_METHOD(TestMethod7)
		{
			TEST_INIT(9, "i", "xlonginsidei", "ilonginsidex", "lx", "lxy", "rwy", "yvo", "oq", "qur");
			GEN_CHAIN_CHAR('i', 'x', true);
			ASSERT_RESULT_LEN(2);
			ASSERT_RESULT("i", 0);
			ASSERT_RESULT("ilonginsidex", 1);
		}

		// 字母最多，指定开头
		TEST_METHOD(TestMethod8)
		{
			TEST_INIT(9, "i", "xlonginsidei", "ilonginsidex", "lx", "lxy", "rwy", "yvo", "oq", "qur");
			GEN_CHAIN_CHAR('r', 0, true);
			ASSERT_RESULT_LEN(4);
			ASSERT_RESULT("rwy", 0);
			ASSERT_RESULT("yvo", 1);
			ASSERT_RESULT("oq", 2);
			ASSERT_RESULT("qur", 3);
		}
	};

	// 异常与边界
	TEST_CLASS(UnitTest3)
	{
		// 有环但enable_loop是false，应该抛出异常
		TEST_METHOD(TestMethod1)
		{
			TEST_INIT(7, "gag", "fag", "glitz", "zaf", "jof", "fij", "lkkj");
			Assert::ExpectException<std::exception>([&]
			{
				GEN_CHAIN_WORD(0, 0, false);
			});
		}

		// 参数head错误
		TEST_METHOD(TestMethod2)
		{
			TEST_INIT(7, "i", "xlonginsidei", "ilonginsidex", "lx", "lxy", "rwy", "yvo");
			Assert::ExpectException<std::exception>([&]
			{
				GEN_CHAIN_CHAR('-', 0, true);
			});
		}

		// 参数tail错误
		TEST_METHOD(TestMethod3)
		{
			TEST_INIT(7, "i", "xlonginsidei", "ilonginsidex", "lx", "lxy", "rwy", "yvo");
			Assert::ExpectException<std::exception>([&]
			{
				GEN_CHAIN_CHAR(0, '0', true);
			});
		}

		// 参数head和tail均错误
		TEST_METHOD(TestMethod4)
		{
			TEST_INIT(7, "i", "xlonginsidei", "ilonginsidex", "lx", "lxy", "rwy", "yvo");
			Assert::ExpectException<std::exception>([&]
			{
				GEN_CHAIN_CHAR('1', '\n', true);
			});
		}

		// 没有路径
		TEST_METHOD(TestMethod5)
		{
			TEST_INIT(7, "i", "xlonginsidei", "ilonginsidex", "lx", "lxy", "rwy", "yvo");
			GEN_CHAIN_CHAR('l', 'l', true);
			ASSERT_RESULT_LEN(0);
		}
	};
}