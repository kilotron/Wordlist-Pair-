#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Core/Core.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CoreUnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int len = 11;
			const char *words[] = {
				"Algebra", "Apple", "Zoo", "Elephant", "Under", "Fox",
				"Dog", "Moon", "Leaf", "Trick", "Pseudopseudohypoparathyroidism"
			};
			char **result = new char *[len];
			int resultLen = Core::gen_chain_word(words, len, result, 0, 0, false);
			Assert::AreEqual(4, resultLen);
		}

	};
}