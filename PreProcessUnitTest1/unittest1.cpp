#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Wordlist/Preprocess.h"
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PreProcessUnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		// pre.change
		TEST_METHOD(TestMethod1)
		{
			Preprocess pre;
			std::set<std::string> sets;
			sets.insert("hello");
			sets.insert("world");
			sets.insert("test");
			sets.insert("preprocess");
			int length;
			pre.change(sets, &length);
			Assert::AreEqual(length, 4);
			std::set<std::string>::iterator iter = sets.begin();
			Assert::AreEqual(strcmp("hello", (*iter).data()), 0);
			iter++;
			Assert::AreEqual(strcmp("preprocess", (*iter).data()), 0);
			iter++;
			Assert::AreEqual(strcmp("test", (*iter).data()), 0);
			iter++;
			Assert::AreEqual(strcmp("world", (*iter).data()), 0);

		}


		// pre.write
		TEST_METHOD(TestMethod2)
		{
			Preprocess pre;
			int length = 5;
			char ** result = (char **)malloc(sizeof(char *) * 5);
			result[0] = (char *)malloc(sizeof(char) * 10);
			strcpy(result[0], "fIrst");
			result[1] = (char *)malloc(sizeof(char) * 10);
			strcpy(result[1], "Second");
			result[2] = (char *)malloc(sizeof(char) * 10);
			strcpy(result[2], "third");
			result[3] = (char *)malloc(sizeof(char) * 10);
			strcpy(result[3], "fortH");
			result[4] = (char *)malloc(sizeof(char) * 10);
			strcpy(result[4], "fiFth");


			pre.write(result, 5);

			std::exception expectedExcetpion;
			try {
				//文件不存在的异常检测
				std::set<std::string> result = pre.readfile("not a file");
				Assert::Fail();
			}
			catch (std::exception e) {
				expectedExcetpion = e;
			}


		}

		// pre.readfile
		TEST_METHOD(TestMethod3) {
			std::ofstream testFile("testRead.txt");
			testFile << "Fifth-FIRST\nforth sEcond, third***\n\n";
			testFile.close();
			Preprocess pre;
			std::set<std::string> stringsets = pre.readfile("testRead.txt");

			std::set<std::string>::iterator iter = stringsets.begin();
			Assert::AreEqual(5, (int)stringsets.size());
			Assert::AreEqual(strcmp("fifth", (*iter).data()), 0);
			iter++;
			Assert::AreEqual(strcmp("first", (*iter).data()), 0);
			iter++;
			Assert::AreEqual(strcmp("forth", (*iter).data()), 0);
			iter++;
			Assert::AreEqual(strcmp("second", (*iter).data()), 0);
			iter++;
			Assert::AreEqual(strcmp("third", (*iter).data()), 0);
		}

		// pre.command
		TEST_METHOD(TestMethod4) {
			Preprocess pre;
			int argc = 4;
			char ** argv = (char **)malloc(sizeof(char *) * 4);
			argv[0] = (char *)malloc(sizeof(char) * 10);
			strcpy(argv[0], "Wordlist.exe");
			argv[1] = (char *)malloc(sizeof(char) * 10);
			strcpy(argv[1], "-w");
			argv[2] = (char *)malloc(sizeof(char) * 10);
			strcpy(argv[2], "-r");
			argv[3] = (char *)malloc(sizeof(char) * 10);
			strcpy(argv[3], "wordlist.txt");

			pre.command(argc, argv);
			Assert::AreEqual((int)(pre.kind == RW), 1);
			Assert::AreEqual(strcmp(pre.filename, "wordlist.txt"), 0);
		}

		// pre.command 指定head
		TEST_METHOD(TestMethod5) {
			Preprocess pre;
			int argc = 5;
			char ** argv = new char *[argc];
			for (int i = 0; i < argc; i++) {
				argv[i] = new char[10];
			}
			strcpy(argv[0], "Wordlist.exe");
			strcpy(argv[1], "-w");
			strcpy(argv[2], "-h");
			strcpy(argv[3], "A");
			strcpy(argv[4], "wordlist.txt");

			pre.command(argc, argv);
			Assert::IsTrue(pre.kind == W);
			Assert::AreEqual("wordlist.txt", pre.filename);
			Assert::AreEqual('a', pre.head);
		}

		// pre.command 指定tail
		TEST_METHOD(TestMethod7) {
			Preprocess pre;
			int argc = 5;
			char ** argv = (char **)malloc(sizeof(char *) * 5);
			argv[0] = (char *)malloc(sizeof(char) * 10);
			strcpy(argv[0], "Wordlist.exe");
			argv[1] = (char *)malloc(sizeof(char) * 10);
			strcpy(argv[1], "-w");
			argv[2] = (char *)malloc(sizeof(char) * 10);
			strcpy(argv[2], "-t");
			argv[3] = (char *)malloc(sizeof(char) * 10);
			strcpy(argv[3], "t");
			argv[4] = (char *)malloc(sizeof(char) * 10);
			strcpy(argv[4], "wordlist.txt");

			pre.command(argc, argv);
			Assert::AreEqual((int)(pre.kind == W), 1);
			Assert::AreEqual(strcmp(pre.filename, "wordlist.txt"), 0);
			Assert::AreEqual(pre.tail, 't');
			Assert::AreEqual((int)pre.head, 0);
		}

		// pre.command 异常测试
		TEST_METHOD(TestMethod6) {
			try {
				Preprocess pre;
				int argc = 1;
				char ** argv = new char *[argc];
				argv[0] = new char[10];
				strcpy(argv[0], "Wordlist.exe");
				pre.command(argc, argv);
				Assert::Fail();
			}
			catch (std::exception e) {

			}
		}

		// 文件错误 异常测试
		TEST_METHOD(TestMethod8)
		{
			Preprocess pre;
			Assert::ExpectException<std::exception>([&]
			{
				pre.readfile("you asshole");
			});
		}

	};
}