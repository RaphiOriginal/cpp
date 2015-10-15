#pragma once

#include <memory>
#include <iostream>

class String final {
	size_t m_len;
	size_t m_start;
	std::shared_ptr<char> m_string;

public:
	String() : m_len(0), m_start(0) { }
	String(const String &string)
		: m_string(string.m_string), m_len(string.m_len), m_start(string.m_start) {
		std::cout << "copyconstructor used" << std::endl;
	}
	String(const char* string) {
		size_t count = 0;
		while (string[count] != '\0') {
			++count;
		}
		m_start = 0;
		m_len = count;
		std::unique_ptr<char[]> temp(new char{ *string });
		m_string = move(temp);
		for (size_t i = m_start; i < m_start + m_len; i++) {
			std::cout << m_string.get()[i];
		}
		std::cout << std::endl;
	}
	~String() {
		std::cout << "deconstructor used" << std::endl;
	}
	//Instanz-Methoden
	char charAt(size_t index) const;
	int compareTo(const String& s) const;
	String concat(char c) const;
	String concat(const String& s)const;
	size_t length() const;
	String substring(size_t beg, size_t end) const;
	std::unique_ptr<char[]> toCString() const;
	
	bool operator==(const String& s) const { return compareTo(s) == 0; }

	friend std::ostream& operator<<(std::ostream& os, const String& s) {
		const size_t end = s.m_start + s.m_len;
		const char* const sc = s.m_string.get();
		for (size_t i = s.m_start; i < end; i++) os << sc[i];
		return os;
	}
	
	static String valueOf(int i);
};