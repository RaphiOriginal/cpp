#include "stdafx.h"
#include "CppUnitTest.h"
#include "MyString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(MyString)
	{
	public:
		
		TEST_METHOD(Construction)
		{
			String s0;
			String s1("");
			String s2("abc");
			String s00(s0);
			String s11(s1);
			String s22(s2);
		}
		TEST_METHOD(Lengt) {
			Assert::IsTrue(String().length() == 0);
			Assert::IsTrue(String("").length() == 0);
			Assert::IsTrue(String("abc").length() == 3);
		}
		TEST_METHOD(CharAt) {
			Assert::IsTrue(String("abc").charAt(0) == 'a');
			Assert::IsTrue(String("abc").charAt(1) == 'b');
			Assert::IsTrue(String("abc").charAt(2) == 'c');
			try {
				String("abc").charAt(-1);
				Assert::Fail();
			}
			catch (std::out_of_range ex) {
				//every thing is fine
			}
			catch (...) {
				Assert::Fail();
			}
			try {
				String("abc").charAt(3);
				Assert::Fail();
			}
			catch (std::out_of_range ex) {
				//every thing is fine
			}
			catch (...) {
				Assert::Fail();
			}
		}
		TEST_METHOD(CompareTo) {
			Assert::IsTrue(String("abc").compareTo(String("abc")) == 0);
			Assert::IsTrue(String("abc").compareTo(String("bbc")) == -1);
			Assert::IsTrue(String("bbc").compareTo(String("abc")) == 1);
			Assert::IsTrue(String("ab").compareTo(String("abc")) == -1);
			Assert::IsTrue(String("abc").compareTo(String("ab")) == 1);
		}
		TEST_METHOD(Equals) {
			Assert::IsTrue(String("abc") == String("abc"));
			Assert::IsFalse(String("abc") == String("bbc"));
			Assert::IsFalse(String("bbc") == String("abc"));
			Assert::IsFalse(String("ab") == String("abc"));
			Assert::IsFalse(String("abc") == String("ab"));
		}
		TEST_METHOD(Concat) {
			Assert::IsTrue(String("abc").concat('d').compareTo(String("abcd")) == 0);
			Assert::IsTrue(String("abc").concat(String("d")).compareTo(String("abcd")) == 0);
		}
		TEST_METHOD(Substring) {
			Assert::IsTrue(String("aabcc").substring(1, 3).compareTo(String("abc")) == 0);
			Assert::IsTrue(String("aabcc").substring(1, 1) == String("a"));
			Assert::IsTrue(String("aabcc").substring(5, 7) == String(""));
			Assert::IsTrue(String("aabcc").substring(1, 3).length() == 3);
			Assert::IsTrue(String("aabcc").substring(2, 3).length() == 2);
			Assert::IsTrue(String("aabcc").substring(3, 3).length() == 1);
		}
		TEST_METHOD(ToCString) {
			Assert::AreEqual(String("abc").toCString().get(), "abc\0");
		}
		TEST_METHOD(ValueOf) {
			Assert::IsTrue(String::valueOf(1).compareTo(String("1")) == 0);
			Assert::IsTrue(String::valueOf(2).compareTo(String("1")) == 1);
			Assert::IsTrue(String::valueOf(-123).compareTo(String("-123")) == 0);
			Assert::IsTrue(String::valueOf(0) == "0");
			Assert::IsTrue(String::valueOf(10) == "10");
			Assert::IsTrue(String::valueOf(999) == "999");
		}
	};
}