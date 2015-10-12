#include "MyString.h"

char String::charAt(size_t index) const {
	int realIndex = m_start + index;
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
	const char* const temp = m_string.get();
	temp[m_start + m_len + 1] = c;
	return String(&temp[m_start]);
}
String String::concat(const String& s)const {
	const char* const temp1 = m_string.get();
	const char* const temp2 = s.m_string.get();
	temp1[m_start + m_len + 1] = temp2[s.m_start];
	return String(&temp1[m_start]);
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

}

static String valueOf(int i);