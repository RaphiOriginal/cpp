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


	cout << s2.charAt(1) << endl;

	//programmende
	cout << "programm finished" << endl;
}