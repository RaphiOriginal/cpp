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
			D.print();
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
			D.print();
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
			D.print();
			D = k*A + B + l*C;
			D.print();
			D = k*A - B - 1 * C;
			D.print();
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

			D = A^C;
			D.print();
		}

	};
}