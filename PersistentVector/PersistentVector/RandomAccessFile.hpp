#pragma once
#include "RandomAccessFile.h"

//generic methods
template<class T> T RandomAccessFile::read(streampos pos /*= -1*/) const {
	if (pos >= 0) {
		//random access read
		m_file.seekg(pos);
		if (!m_file) throw IOException("read error");
	}

	T data;

	m_file.read(reinterpret_cast<char*>(&data), sizeof(T));
	if (!m_file) throw IOException("read error");
	return data;
}

template<class T> void RandomAccessFile::write(const T& data, streampos pos /*= -1*/) {
	if (pos >= 0) {
		//random access read
		m_file.seekp(pos);
		if (!m_file) throw IOException("write error");
	}

	m_file.write(reinterpret_cast<const char*>(&data), sizeof(T));
	if (!m_file) throw IOException("write error");
}