#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int MaxSize = 3000;
int seq[MaxSize]; // darf nicht variabel sein zu compilezeit! in Java: int[] seq = new int[MaxSize];
bool diff[MaxSize];

bool jolly(int n) {
	for (int i = 0; i < n; i++) diff[i] = false;

	for (int i = 1; i < n; i++) {
		int d = abs(seq[i] - seq[i - 1]);
		if (d < 1 || diff[d] == true) return false;
		diff[d] = true;
	}
	return true;
}

int main() {
	int n;

	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> seq[i];
		}
		if (jolly(n)) {
			cout << "jolly" << endl;
		}
		else {
			cout << "Not jolly" << endl;
		}
	}
	return 0;
}