#include "stdafx.h"
#include "CppUnitTest.h"
#include <string.h>
#include <stdarg.h>
#include "../Core/Core.h"

#define TEST_INIT(_len, ...) int len = _len; int resultLen; char **result = new char *[len];\
							 char **words = ToWordsArray(_len, ##__VA_ARGS__)
							 

#define GEN_CHAIN_WORD(head, tail, enable_loop) \
		resultLen = Core::gen_chain_word(words, len, result, head, tail, enable_loop)

#define GEN_CHAIN_CHAR(head, tail, enable_loop) \
		resultLen = Core::gen_chain_char(words, len, result, head, tail, enable_loop)

#define ASSERT_RESULT_LEN(len) Assert::AreEqual(resultLen, len)

#define ASSERT_RESULT(expected, no) Assert::AreEqual(expected, result[no])

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CoreUnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

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

	};
}