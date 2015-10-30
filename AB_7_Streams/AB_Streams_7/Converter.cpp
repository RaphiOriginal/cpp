#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ifstream in;
	ofstream out;
	const string input = "testin.pgm";
	const string output = "testout.pgm";
	in.open(input, ios::in);
	if (!in) {
		cerr << "Datei konnte nicht geöffnet werden!" << endl;
		return 1;
	}
	else {
		while (!in.eof()) {
			//TODO: save header and ascii code!
			cout << (char)in.get();
		}
		in.close();
	}
}