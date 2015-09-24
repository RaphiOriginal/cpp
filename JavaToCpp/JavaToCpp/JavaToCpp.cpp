#include <iostream>

using namespace std;

int main() {
	const long long l = 1000000000000L;
	long long a[10];
	int i = 0;

	while (i < 10) {
		a[i] = l + i + 1;
		i++;
	}
	cout << '[';
	for (int i = 0; i < 9; i++) {
		cout << a[i] << ',';
	}
	cout << a[9] << ']' << endl;

}