#include "Geometry.h"
#include <iostream>
using namespace std;


PointArray::PointArray() : m_size(0), m_capacity(0), m_points(nullptr) {}

PointArray::PointArray(const Point pts[], const size_t size) : m_size(size), m_capacity(size){
	m_points = new Point[size];
	for (size_t i = 0; i < size; i++) {
		m_points[i] = pts[i];
	}
}

PointArray::PointArray(const PointArray& pv) : m_size(pv.m_size), m_capacity(pv.m_capacity) {
	m_points = new Point[pv.m_size];
	for (size_t i = 0; i < pv.m_size; i++) {
		m_points[i] = pv.m_points[i];
	}
}

PointArray::~PointArray() {
	delete[] m_points;
}

void PointArray::clear() {
	resize(0);
}

void PointArray::print() const {
	cout << "[";
	for (size_t i = 0; i < m_size; i++) {
		cout << "(" << at(i)->getX() << "," << at(i)->getY() << ")";
		if (i < m_size - 1) cout << ",";
	}
	cout << "]" << endl;
}

void PointArray::pushBack(const Point& p) {
	if (m_size == m_capacity) { resize(m_capacity * 2); }
	m_points[m_size++] = p;
}

void PointArray::insert(const size_t pos, const Point& p) {
	if (pos >= m_capacity) { resize(m_capacity * 2); }
	for (size_t i = m_size++; i > pos; i--) {
		m_points[i] = m_points[i - 1];
	}
	m_points[pos] = p;
}

void PointArray::remove(const size_t pos) {
	if (m_size > pos) {
		for (size_t i = pos; i < --m_size; i++) {
			m_points[i] = m_points[i + 1];
		}
	}
}

bool PointArray::get(const size_t pos, Point& p) const {
	if (pos < m_size) {
		p = m_points[pos];
		return true;
	}
	return false;
}

const Point* PointArray::at(const size_t pos) const {
	return (pos < m_size) ? m_points + pos : nullptr;
}

void PointArray::resize(size_t capacity) {
	if (capacity < m_size) m_size = capacity;
	Point* temp = new Point[capacity];
	m_capacity = capacity;
	for (size_t i = 0; i < m_size; i++) {
		temp[i] = m_points[i];
	}
	delete[] m_points;
	m_points = temp;
}