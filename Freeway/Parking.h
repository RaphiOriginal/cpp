#pragma once

#include <forward_list>
#include <memory>
#include "Car.h"

using namespace std;

class Parking {
	forward_list<unique_ptr<Car>> m_freeList;

public:
	void parkCar(unique_ptr<Car>&& c) { //&& referenz auf rvalue (nicht lvalue) man verschiebt so die referenz
		m_freeList.push_front(move(c));
	}

	unique_ptr<Car> getCar() {
		if (m_freeList.empty()) {
			return make_unique<Car>(new Car());
		}
		else {
			unique_ptr<Car> c = move(m_freeList.front());
			m_freeList.pop_front(); //keinen rückgabewert
			return c;
		}
	}
};