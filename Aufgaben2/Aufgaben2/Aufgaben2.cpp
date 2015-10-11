#include <iostream>
#include <cmath>

using namespace std;

//Aufgabe 1
//Eine Referenz kann nur gemacht werden, wenn diese von einer lvalue entnommen wird, was die Referenz repräsentiert.
//macht man aber eine constante und holt sich die Referenz einer Zahl wird die adresse fix gespeichert und die adresse
//kann die rolle von lvalue selbst übernehmen da er weiss dass sich der Wert/Adresse eh nie ändert.

//42 ist ein Integer-Literal. Als solches kannes nie ein lvalue sien, sondern ist immer ein rvalue. dRef ist ein
//Alias für ein variables double Objekt. Es darf nicht auf einen rvalue verweisen, sondern muss auf einen lvalue verweisen
//Wäre dRef ein Alias für einen konstanten double, dann wäre die 42 in Ordnung.

//double temp = 1; //first create a temporary with the right value
//const double& = temp; //then use the temporary as the initializer for dRef

/*
int i = 7;
int& ri = i;
const int ci = 7;
const int& rci = ci;
const int& rci = 7;
*/

//Aufgabe 2
int task1() {
	int i = 'a';
	const int ic = i;
	const int *pic = &ic;
	//int *const cpi = &ic; nicht legal weil der inteager konstant ist
	//Error: a value of type "const int *" cannot be used to initialize an entitiy of type "int * const".
	const int *const cpic = &ic;
	return 0;
}
int task2() {
	//int& i = 'a'; //nicht legal: referenc kann nur von einer lvalue entnommen werden
	//Error: initial value of reference to non-const must be an lvalue
	const int& i = 'a'; //workaround
	const int ic = i;
	//const int& ric = &ic; //nicht legal: keine referenz auf eine referenz möglich
	//Error: a value of type "const int *" cannot be used to initialize an entity of type "const int &"
	//int& const rpi = &ic; //nicht legal: weiss ich nicht =/
	//Error: ...
	//const int& const cpic = &ic; //nicht legal: weiss ich nicht =/
	//Error: ...
	return 0;
}

//Aufgabe 3
//using pointers
void swap(int* one, int* two) {
	int temp = *one;
	*one = *two;
	*two = temp;
}
//using reference
void swap(int& one, int& two) {
	int temp = one;
	one = two;
	two = temp;
}
//Aufgabe 4
//Erwartet wird die Adresse zu 42
//Die lokale Variable lebt nur innerhalb vom Scope und wird nach dem Methodenaufruf gelöscht und kann daher zu Segmentationsfehler führen
//Man erhält die Adresse von einem Speicher der nicht mehr existiert.
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
