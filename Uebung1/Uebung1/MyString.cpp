#include "MyString.h"
#include <string>

char String::charAt(size_t index) const {
	size_t realIndex = m_start + index;
	const char* const temp = m_string.get();
	return temp[realIndex];
}
int String::compareTo(const String& s) const {
	int result = 0;
	size_t i = 0;
	while (i < m_len && i < s.m_len && result == 0) {
		if (s.m_string.get()[i + s.m_start] > m_string.get()[m_start + i]) {
			result = -1;
		}
		else if (s.m_string.get()[i + s.m_start] < m_string.get()[m_start + i]) {
			result = 1;
		}
		++i;
	}
	return result;
}
String String::concat(char c) const {
	char* temp = new char[m_len + 1];
	for (size_t i = 0; i < m_len; i++) {
		temp[i] = m_string.get()[m_start + i];
	}
	temp[m_len] = c;
	temp[m_len + 1] = '\0';
	return String(temp);
}
String String::concat(const String& s)const {
	char* temp = new char[m_len + s.m_len];
	for (size_t i = 0; i < m_len; i++) {
		temp[i] = m_string.get()[m_start + i];
	}
	for (size_t i = 0; i <s.m_len; i++) {
		temp[m_len + i] = s.m_string.get()[m_start + i];
	}
	temp[m_len + s.m_len] = '\0';
	return String(temp);
}
size_t String::length() const {
	return m_len;
}
String String::substring(size_t beg, size_t end) const {
	String s = String();
	s.m_start = m_start + beg;
	s.m_len = end - beg;
	s.m_string = m_string;
	return s;
}
std::unique_ptr<char[]> String::toCString() const {
	std::unique_ptr<char[]> r = std::unique_ptr<char[]>(new char[m_len + 1]);
	const char * const tc = m_string.get();

	memcpy(r.get(), tc + m_start, m_len);
	r[m_len] = '\0';

	return move(r);
}

String String::valueOf(int i)
{
	int value = i;
	int factor = 10;
	size_t size = 1;
	if (i < 0) {
		value = value * -1;
		size++;
	}
	while (value / factor != 0) {
		size++;
		factor = factor * 10;
	}
	factor = 10;
	size_t index = size - 1;
	char* result = new char[size];
	if (i < 0) result[0] = '-';
	while (value % factor != 0) {
		int check = value % factor;
		switch (check) {
		case 0:
			result[index] = '0';
			break;
		case 1:
			result[index] = '1';
			break;
		case 2:
			result[index] = '2';
			break;
		case 3:
			result[index] = '3';
			break;
		case 4:
			result[index] = '4';
			break;
		case 5:
			result[index] = '5';
			break;
		case 6:
			result[index] = '6';
			break;
		case 7:
			result[index] = '7';
			break;
		case 8:
			result[index] = '8';
			break;
		case 9:
			result[index] = '9';
			break;
		}
		index--;
		value = value / factor;
	}
	result[size] = '\0';
	return String(result);
}