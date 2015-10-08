#include <iostream>

using namespace std;
int *fillArr(int arr[], int dl) {
	for (int i = 0; i < dl; ++i) {
		arr[i] += 1;
	}
	return &arr[0];
}

bool checkStringLength(char a[], char b[]) {
	int aLength = 0;
	int bLength = 0;
	while (a[aLength] != '\0' ) {
		++aLength;
	}
	while (b[bLength] != '\0') {
		++bLength;
	}
	return aLength == bLength;
}

int main() {
	int y[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = 10;
	int *a = fillArr(y, size);
	for (int i = 0; i < size; ++i) {
		cout << a[i] << endl;
	}

	char string0[] = { 'J', 'a', 'a', 'v', 's', 's', '\0' };
	char string1[] = { 'J', 'a', 'a', 'v', 's', '\0' };
	char string2[] = "Jaavs";
	char string3[] = { 'J', 'a', 'a' };

	cout << checkStringLength(string0, string1) << endl;
	cout << checkStringLength(string0, string2) << endl;
	cout << checkStringLength(string0, string3) << endl;
	cout << checkStringLength(string1, string2) << endl;
	cout << checkStringLength(string1, string3) << endl;
	cout << checkStringLength(string2, string3) << endl;
}