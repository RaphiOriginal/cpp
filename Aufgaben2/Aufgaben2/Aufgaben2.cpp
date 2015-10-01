#include <iostream>
#include <cmath>

using namespace std;

//Aufgabe 1
//Eine Referenz kann nur gemacht werden, wenn diese von einer lvalue entnommen wird, was die Referenz repräsentiert.
//macht man aber eine constante und holt sich die Referenz einer Zahl wird die adresse fix gespeichert und die adresse
//kann die rolle von lvalue selbst übernehmen da er weiss dass sich der Wert/Adresse eh nie ändert.

//Aufgabe 2
int task1() {
	int i = 'a';
	const int ic = i;
	const int *pic = &ic;
	//int *const cpi = &ic; nicht legal weil der inteager konstant ist
	const int *const cpic = &ic;
	return 0;
}
int task2() {
	//int& i = 'a'; //nicht legal: referenc kann nur von einer lvalue entnommen werden
	const int& i = 'a'; //workaround
	const int ic = i;
	//const int& ric = &ic; //nicht legal: keine referenz auf eine referenz möglich
	//int& const rpi = &ic; //nicht legal: weiss ich nicht =/
	//const int& const cpic = &ic; //nicht legal: weiss ich nicht =/
	return 0;
}

//Aufgabe 3
void swap(int* one, int* two) {
	int temp = *one;
	*one = *two;
	*two = temp;
	//Ich habe das gefühl dass muss mit Pointern noch ressourcensparender gehen, bin aber nicht
	//darauf gekommen...
}
void swap(int& one, int& two) {
	int temp = one;
	one = two;
	two = temp;
}
//Aufgabe 4
//Erwartet wird die Adresse zu 42
int* mySmartFunc() {
	int ghostInTheMachine = 42;
	return &ghostInTheMachine;
}
# define PI           3.14159265358979323846
//Aufgabe 5
void sinus(int a, int b) {
	int draw = 0;
	double step = 2 * PI / b;
	for (int j = 0; j < a*2; j++) {
		for (int i = 0; i < b; i++) {
			draw = sin(((double)i)*step)*a+a;
			if (draw == j) {
				cout << "#"; //Sinuslinie
			}
			else if(a == j){
				cout << "_"; //Null-Linie (eigentlich 1 da 0 nicht dargestellt wird, daher _)
			}
			else {
				cout << " "; //Leerer Raum
			}
		}
		cout << endl;
	}

}
int main() {
	int one = 1;
	int two = 2;

	swap(&one, &two);

	cout << "(" << one << " , " << two << ")" << endl;

	swap(one, two);
	cout << "(" << one << " , " << two << ")" << endl;

	cout << *mySmartFunc() << endl;

	sinus(10, 30);
}