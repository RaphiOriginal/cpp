#pragma once

#include <memory>
#include <iostream>

class String final {
	size_t m_len;
	size_t m_start;
	std::shared_ptr<char> m_string;

public:
	String() : m_len(0), m_start(0) {
		std::cout << "standart-constructor" << std::endl;
	}
	String(const String &string)
		: m_string(string.m_string), m_len(string.m_len), m_start(string.m_start) {
		std::cout << "copy-constructor: " << string << std::endl;
	}
	String(const char* string) : m_start(0), m_len(0) {
		while (string[m_len] != '\0') {
			++m_len;
		}
		std::unique_ptr<char[]> temp(new char[m_len]);
		for (size_t i = 0; i < m_len; i++) {
			temp[i] = string[i];
		}
		m_string = move(temp);
		std::cout << "convert-constructor: " << string << std::endl;
	}
	String(String&& s) : m_len(s.m_len), m_start(s.m_start), m_string(move(s.m_string)) {
		s.m_len = 0;
		s.m_start = 0;
		std::cout << "verschiebekonstruktor: " << *this << std::endl;
	}
	String& operator=(String&& s) {
		m_len = s.m_len; s.m_len = 0;
		m_start = s.m_start; s.m_start = 0;
		m_string = s.m_string; s.m_string = nullptr;
		return *this;
	}
	~String() {
		std::cout << "destructor: " << *this << std::endl;
	}
	//Instanz-Methoden
	char charAt(size_t index) const;
	int compareTo(const String& s) const;
	String concat(char c) const;
	String concat(const String& s)const;
	String concat(String&& s);

	size_t length() const;
	String substring(size_t beg, size_t end) const;
	std::unique_ptr<char[]> toCString() const {
		std::unique_ptr<char[]> r = std::unique_ptr<char[]>(new char[m_len + 1]);
		const char * const tc = m_string.get();

		memcpy(r.get(), tc + m_start, m_len);
		r[m_len] = '\0';

		return move(r);
	}
	
	bool operator==(const String& s) const { return compareTo(s) == 0; }

	friend std::ostream& operator<<(std::ostream& os, const String& s) {
		const size_t end = s.m_start + s.m_len;
		const char* const sc = s.m_string.get();
		for (size_t i = s.m_start; i < end; i++) os << sc[i];
		return os;
	}
	
	static String valueOf(int i);
};