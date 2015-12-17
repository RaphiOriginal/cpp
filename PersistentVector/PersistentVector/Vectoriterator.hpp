#pragma once
#include <assert.h>

//prototype
template<class T> class PersistentVector;

template<class T> class ConstVectorIterator {
	friend class PersistentVector<T>; //Er kann jetzt auf die privaten attribute von ConstVectorIterator zugreiffen.

	const PersistentVector<T> *m_vector;
	size_t m_pos; // current iterator position

	// privater ctor
	ConstVectorIterator(const PersistentVector<T> *vector, size_t pos) : m_vector(vector), m_pos(pos) {}

public:
	typedef random_access_iterator_tag iterator_category; // Markierung, wird nie verwendet, nur um zu sehen was für ein Iterator es ist!
	typedef T value_type;
	typedef int _w64 difference_type;
	typedef const T& const_reference;

	// relational operators
	bool operator==(const ConstVectorIterator& it) {
		return m_vector == it.m_vector && m_pos == it.m_pos;
	}
	bool operator!=(const ConstVectorIterator& it) {
		return m_vector != it.m_vector || m_pos != it.m_pos;
	}
	bool operator<(const ConstVectorIterator& it) {
		return m_vector == it.m_vector && m_pos < it.m_pos;
	}

	// increment and decrement operators
	//prefix
	ConstVectorIterator& operator++() {
		m_pos++;
		return *this;
	}
	ConstVectorIterator& operator--() {
		m_pos--;
		return *this;
	}
	//postfix
	ConstVectorIterator operator++(int) {
		return ConstVectorIterator(m_vector, m_pos++);
	}
	ConstVectorIterator operator--(int) {
		return ConstVectorIterator(m_vector, m_pos--);
	}

	// arithmetic operators: +, -, +=, -=
	difference_type operator+(const ConstVectorIterator& it) {
		assert(m_vector == it.m_vector);
		return m_pos += it.m_pos;
	}
	ConstVectorIterator& operator+(difference_type diff) {
		return ConstVectorIterator(m_vector, m_pos + diff);
	}
	ConstVectorIterator& operator+=(difference_type diff) {
		m_pos += diff;
		return *this;
	}
	difference_type operator-(const ConstVectorIterator& it) {
		assert(m_vector == it.m_vector);
		return m_pos -= it.m_pos;
	}
	ConstVectorIterator& operator-(difference_type diff) {
		return ConstVectorIterator(m_vector, m_pos - diff);
	}
	ConstVectorIterator& operator-=(difference_type diff) {
		m_pos -= diff;
		return *this;
	}

	//acess operator
	T operator*() const {
		return (*m_vector)[m_pos];
	}
	T operator[](size_t delta) const {
		return (*m_vector[m_pos + delta]);
	}

};