#include "RandomAccessFile.hpp"
#include "PersistentVector.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	try {
		RandomAccessFile raf("test.bin");
		raf.write(0x01020304, 0);
		cout << "0x" << setw(8) << setfill('0') << hex << uppercase << raf.read<int>(0) << endl;
		cout << "Length: " << raf.length() << endl;

		PersistentVector<int> pv("pv.bin", 50, 99);
		cout << dec << pv[3] << endl;
		cout << "99 = " << pv.front() << endl;
		cout << "99 = " << pv.back() << endl;
		pv.push_back(100);
		cout << "100 = " << pv.back() << endl;
		pv.pop_back();
		cout << "99 = " << pv.back() << endl;
	}
	catch (RandomAccessFile::IOException& ex) {
		cout << "Error: " << ex.what() << endl;
	}
	return 0;
}