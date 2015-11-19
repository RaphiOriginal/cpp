#pragma once

template<class T> class SmartPointer {
	struct Item {
		T* const m_p; // pointer to object 
		int m_rc; // reference counter

		Item(T *p) : m_p(p), m_rc(1) {}

		void Add() {
			// your implementation 
			m_rc++;
		}
		void Release() {
			// your implementation 
			if (--m_rc == 0) {
				delete m_p;
			}
		}
	} *m_pointer; // pointer to item
public:
	SmartPointer(T *p = nullptr) { Init(p); }
	~SmartPointer() { Release(); }
	// your implementations:
	// copy constructor
	SmartPointer(const SmartPointer<T>& p) { 
		m_pointer = p.m_pointer;
		m_pointer->Add(); 
	}
	// assignment operators for simple pointer and SmartPointer
	SmartPointer operator=(const SmartPointer& rhs) {
		m_pointer = rhs.m_pointer;
		m_pointer->Add();
		return *this;
	}
	// dereferencing operator *
	T& operator*() const {
		return *m_pointer->m_p;
	}
	// member access operator ->
	T& operator->() const {
		return m_pointer->m_p;
	}
	
		// predicate IsUnique() returns true for an initialized and unique pointer
private:
		void Init(T *p) { 
			// your implementation 
			m_pointer = new Item(p);
		} 
		void Release() { 
			// your implementation 
			m_pointer->Release();
			if (m_pointer->m_rc == 0) {
				delete m_pointer;
				m_pointer = nullptr;
			}
		}
};