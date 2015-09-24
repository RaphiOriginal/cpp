#include <iostream>

using namespace std;

int cycleLength(long long n) {
	if (n == 1) {
		return 1;
	}
	else {
		int cnt = 1;
		while (n != 1) {
			if (n % 2 == 0) {
				n /= 2;
			}
			else {
				n = 3 * n + 1;
			}
			cnt++;
		}
		return cnt;
	}
}

int main() {
	int n;
	cin >> n;
	cout << cycleLength(n) << endl;
	return 0;
}