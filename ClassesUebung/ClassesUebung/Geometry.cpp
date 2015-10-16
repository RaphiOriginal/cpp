#include "Geometry.h"


PointArray::PointArray() : m_size(0), m_capacity(0), m_points(nullptr) {}
PointArray::PointArray(const Point pts[], size_t size) : m_size(size), m_capacity(size) {
	
}
	
PointArray::PointArray(const PointArray& pv) : m_size(pv.m_size), m_capacity(pv.m_capacity) {
	m_points = new Points[m_size];
	for (size_t i = 0; i < m_size; i++) {
		m_points[i] = pv[i];
	}
}

