#pragma once
#include <cassert>
#include "RandomAccessFile.h"

template<class T> class PersistentVector {
	RandomAccessFile m_file;
	size_t m_size;

public:
	typedef T value_type; // verwalteter Datentyp
	typedef T& reference;
	typedef const T& const_reference;

	PersistentVector(const string& fileName) : m_file(fileName), m_size(capacity()) {}

	size_t capacity() const {
		return (size_t) m_file.length() / sizeof(T);
	}

	PersistentVector(const string& fileName, size_t size, const_reference val) : m_file(fileName), m_size(size) {
		for (size_t i = 0; i < size; i++) m_file.write(val);
	}

	virtual ~PersistentVector() {
		if (m_size < capacity()) m_file.truncate(m_size * sizeof(T));
	}

	void assign(size_t size, const_reference val) {
		clear();
		for (size_t i = 0; i < size; i++) m_file.write(val);
		m_size = size;
	}

	void clear() {
		if (m_file.truncate(0)) throw RandomAccessFile::IOException("truncation failed");
		m_size = 0;
	}

	size_t size() const { return m_size; }
	bool empty() const { return m_size == 0; }
	size_t max_size() const { return SIZE_MAX; }

	T operator[](size_t pos) const {
		return read(pos);
	}

	T front() { return at(0); }
	T back() { return at(m_size - 1); }

	void push_back(const_reference val) {
		write(m_size++, val);
	}
	void pop_back() {
		if (m_size < 1) throw RandomAccessFile::IOException("bad size");
		m_size--;
	}

protected:
	T read(size_t pos) const {
		return m_file.read<T>(pos*sizeof(T));
	}

	void write(size_t pos, const_reference val) {
		m_file.write<T>(val, pos*sizeof(T));
	}

	T at(size_t pos) {
		if (pos >= m_size) throw RandomAccessFile::IOException("bad position");
		return read(pos);
	}

};