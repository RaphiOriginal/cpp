#include "stdafx.h"
#include "CppUnitTest.h"
#include "Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(Vector)
	{
	public:
		
		TEST_METHOD(Addition)
		{
			double a_data[] = { 2, 3, 5, 9 };
			double b_data[] = { 1, 0, 0, 1 };
			double c_data[] = { 3, 0, 2, 5 };
			double d_data[4];
			Array<double> A(a_data, 4);
			Array<double> B(b_data, 4);
			Array<double> C(c_data, 4);
			Array<double> D(d_data, 4);

			D = A + B + C;

			double expectedResult[] = { 6, 3, 7, 15 };
			for (int i = 0; i < D.m_N; i++) {
				Assert::IsTrue(expectedResult[i] == D[i]);
			}
		}
		TEST_METHOD(Substraction) {
			double a_data[] = { 2, 3, 5, 9 };
			double b_data[] = { 1, 0, 0, 1 };
			double c_data[] = { 3, 0, 2, 5 };
			double d_data[4];
			Array<double> A(a_data, 4);
			Array<double> B(b_data, 4);
			Array<double> C(c_data, 4);
			Array<double> D(d_data, 4);

			D = A - B - C;

			double expectedResult[] = { -2, 3, 3, 3 };
			for (int i = 0; i < D.m_N; i++) {
				Assert::IsTrue(expectedResult[i] == D[i]);
			}
		}
		TEST_METHOD(Skalar) {
			int k = 5;
			double l = 3.14;
			double a_data[] = { 2, 3, 5, 9 };
			double b_data[] = { 1, 0, 0, 1 };
			double c_data[] = { 3, 0, 2, 5 };
			double d_data[4];
			Array<double> A(a_data, 4);
			Array<double> B(b_data, 4);
			Array<double> C(c_data, 4);
			Array<double> D(d_data, 4);

			D = k*A;
			
			double expectedResult1[] = { 10, 15, 25, 45 };
			for (int i = 0; i < D.m_N; i++) {
				Assert::AreEqual(expectedResult1[i], D[i], 0.001);
			}

			D = k*A + B + l*C;
			
			double expectedResult2[] = { 20.42, 15, 31.28, 61.7 };
			for (int i = 0; i < D.m_N; i++) {
				Assert::AreEqual(expectedResult2[i], D[i], 0.001);
			}

			D = k*A - B;

			double expectedResult3[] = { 9, 15, 25, 44 };
			for (int i = 0; i < D.m_N; i++) {
				Assert::AreEqual(expectedResult3[i], D[i], 0.001);
			}

			D = B - l*C;

			double expectedResult4[] = { -8.42, 0, -6.28, -14.7 };
			for (int i = 0; i < D.m_N; i++) {
				Assert::AreEqual(expectedResult4[i], D[i], 0.001);
			}

			D = k*A - B - l * C;
			
			double expectedResult5[] = { -0.42, 15, 18.72, 28.3 };
			for (int i = 0; i < D.m_N; i++) {
				Assert::AreEqual(expectedResult5[i], D[i], 0.001);
			}

			D = A * 2; //New
			
			double expectedResult6[] = {4.0, 6.0, 10.0, 18.0};
			for (int i = 0; i < D.m_N; i++) {
				Assert::AreEqual(expectedResult6[i], D[i], 0.001);
			}

			D = 2 * (A - B); //New

			double expectedResult7[] = { 2.0, 6.0, 10.0, 16.0 };
			for (int i = 0; i < D.m_N; i++) {
				Assert::AreEqual(expectedResult7[i], D[i], 0.001);
			}

			D = (A - B) * 2; //New

			double expectedResult8[] = { 2.0, 6.0, 10.0, 16.0 };
			for (int i = 0; i < D.m_N; i++) {
				Assert::AreEqual(expectedResult8[i], D[i], 0.001);
			}
		}
		TEST_METHOD(Multiplikation) {
			double a_data[] = { 2, 3, 5, 9 };
			double b_data[] = { 1, 0, 0, 1 };
			double c_data[] = { 3, 0, 2, 5 };
			double d_data[4];
			Array<double> A(a_data, 4);
			Array<double> B(b_data, 4);
			Array<double> C(c_data, 4);
			Array<double> D(d_data, 4);

			double s = A^C; //Not Working

			double expectedResult = 61;
			Assert::AreEqual(expectedResult, s , 0.001);
		}

	};
}