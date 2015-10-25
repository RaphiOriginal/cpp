#include "MyString.h"
#include <iostream>

using namespace std;

int main() {
	String s0;
	String s1("");
	String s2("abc");
	String s00(s0);
	String s11(s1);
	String s22(s2);
	//initialisierungsende
	cout << "String initial done" << endl;


	cout << "charat: " << s2.charAt(1) << endl;
	cout << "compare1: " << s2.compareTo(s22) << endl;
	cout << "compare2: " << s2.compareTo(s1) << endl;
	cout << "compare3: " << s1.compareTo(s2) << endl;
	cout << "valueof1: " << String::valueOf(1) << endl;
	cout << "valueof2: " << String::valueOf(123) << endl;
	cout << "valueof2: " << String::valueOf(-123) << endl;
	cout << "intMaxValue: " << numeric_limits<int>::max() << endl;
	cout << "valueofMAX: " << String::valueOf(std::numeric_limits<int>::max()) << endl;
	cout << "valueofMIN: " << String::valueOf(std::numeric_limits<int>::min()) << endl;
	cout << "concat1: " << String("abc").concat('d') << endl;
	cout << "concat1: " << String("abc").concat("abc") << endl;

	{
		//Move-Semantik
		cout << endl;
		cout << endl;
		cout << "Move-Semantik" << endl;
		String s = String("ab").concat("cd").concat("ef");
		cout << s << endl;
	}
	cout << endl;
	cout << endl;

	//programmende
	cout << "programm finished" << endl;
}