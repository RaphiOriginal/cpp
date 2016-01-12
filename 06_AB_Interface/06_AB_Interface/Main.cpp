#include <iostream>

class IBar {
public:
	virtual ~IBar() {};
	virtual void Describe() = 0;
};

class BarTester : public IBar {
	std::string m_privateName;
public:
	BarTester(std::string name);
	virtual ~BarTester();
	virtual void Describe();
};

BarTester::BarTester(std::string name) : m_privateName(name) {
	std::cout << "BarTester constructor" << std::endl;
}
BarTester::~BarTester() {
	std::cout << "BarTester destructor" << std::endl;
}
void BarTester::Describe() {
	//std::cout << "I'm BarTester [" << m_privateName << "]" << std::endl;
}
void descriptor(IBar *obj) {
	obj->Describe();
}

int main(int argc, char **argv) {
	std::cout << std::endl << "BarTester Testing..." << std::endl;
	BarTester *obj1 = new BarTester("Declared with BarTester");
	descriptor(obj1);
	delete obj1; obj1 = nullptr;
	std::cout << std::endl << "IBar Testing..." << std::endl;
	IBar *obj2 = new BarTester("Declared with IBar");
	descriptor(obj2);
	delete obj2; obj2 = nullptr;   // 1
	std::cout << std::endl << "BarTester not defined..." << std::endl;
	descriptor(new BarTester("Not defined")); // 2
}