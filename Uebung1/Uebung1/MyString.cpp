#include "MyString.h"
#include <string>
#include <stdexcept>

char String::charAt(size_t index) const {
	if (index < 0 || index >= m_len) {
		throw std::out_of_range("index not in range!");
	}
	size_t realIndex = m_start + index;
	const char* const temp = m_string.get();
	return temp[realIndex];
}
int String::compareTo(const String& s) const {
	size_t i = 0;
	while (i < m_len && i < s.m_len) {
		if (s.m_string.get()[i + s.m_start] > m_string.get()[m_start + i]) {
			return -1;
		}
		else if (s.m_string.get()[i + s.m_start] < m_string.get()[m_start + i]) {
			return 1;
		}
		++i;
	}
	if (m_len < s.m_len) { return -1; }
	else if (m_len > s.m_len) { return 1; }
	return 0;
}
String String::concat(char c) const {
	String ns;
	ns.m_start = 0;
	ns.m_len = m_len + 1;
	std::unique_ptr<char[]> temp(new char[m_len + 1]);
	for (size_t i = 0; i < m_len; i++) {
		temp[i] = m_string.get()[m_start + i];
	}
	temp[m_len] = c;
	ns.m_string = move(temp);
	return ns;
}
/*
//alte Variante vor Move-Semantik
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
*/
String String::concat(const String& s) const {
	String ns;
	ns.m_len = s.m_len + m_len;
	ns.m_start = 0;
	std::unique_ptr<char[]> temp(new char[m_len + s.m_len]);
	for (size_t i = 0; i < m_len; i++) {
		temp[i] = m_string.get()[m_start + i];
	}
	for (size_t i = 0; i <s.m_len; i++) {
		temp[m_len + i] = s.m_string.get()[m_start + i];
	}
	ns.m_string = move(temp);
	return ns;
}
//überladen für Move-Semantik
String String::concat(String&& s) {
	std::cout << "concat RR" << std::endl;
	std::unique_ptr<char[]> temp(new char[m_len + s.m_len]);
	for (size_t i = 0; i < m_len; i++) {
		temp[i] = m_string.get()[m_start + i];
	}
	for (size_t i = 0; i <s.m_len; i++) {
		temp[m_len + i] = s.m_string.get()[m_start + i];
	}
	s.m_len = s.m_len + m_len;
	s.m_start = 0;
	s.m_string = move(temp);
	return s;
}
size_t String::length() const {
	return m_len;
}
String String::substring(size_t beg, size_t end) const {
	if (beg >= m_len || end <= beg) return String("");
	if (end > m_len) throw std::out_of_range("end index is out of range!");
	String s;
	s.m_start = m_start + beg;
	s.m_len = end - beg + 1;
	s.m_string = m_string;
	return s;
}
String String::valueOf(int i)
{
	String res;
	res.m_start = 0;
	long long value = i;
	const int factor = 10;
	size_t size = 1;
	if (i < 0) {
		value = value * -1;
		size++;
	}
	long long copy = value;
	while (copy / factor > 0) {
		size++;
		copy = copy / factor;
	}
	res.m_len = size;
	size_t index = size - 1;
	std::unique_ptr<char[]> result(new char[size]);
	result[index] = '0';
	if (i < 0) result[0] = '-';
	while (value % factor != 0) {
		int check = value % factor;
		result[index] = '0' + check;
		index--;
		value = value / factor;
	}
	res.m_string = move(result);
	return res;
}