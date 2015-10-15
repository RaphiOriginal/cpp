#include "MyString.h"

char String::charAt(size_t index) const {
	size_t realIndex = m_start + index;
	const char* const temp = m_string.get();
	return temp[realIndex];
}
int String::compareTo(const String& s) const {
	int result = 0;
	int i = 0;
	while (i < m_len || i < s.m_len || result != 0) {
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
	String newString = String(*this);
	newString.m_len = newString.m_len + 1;
	char* temp = newString.m_string.get();
	temp[newString.m_start + newString.m_len] = c;
	return newString;
}
String String::concat(const String& s)const {
	String s1 = String(*this);
	String s2 = String(s);
	char* temp1 = s1.m_string.get();
	char*temp2 = s2.m_string.get();
	temp1[m_start + m_len + 1] = temp2[s.m_start];
	return s1;
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
	String s = String();
	const char* c = (char*)i;
	return s;
}