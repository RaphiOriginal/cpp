#include <iostream>
#include <ctime>

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
	unsigned int time;
	cin >> n;
	time = clock();
	cout << cycleLength(n) << endl;
	cout << clock() - time << " miliseconds to calculate" << endl;
	return 0;
}