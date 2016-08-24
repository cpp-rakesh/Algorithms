#ifndef ALGORITHMS_RECURRENCE_TOWER_H_
#define ALGORITHMS_RECURRENCE_TOWER_H_

#include <deque>
#include <iostream>

/*
  This is the tower class, which holds the data.
  Data like what type of tower it is.
  How many rings the tower has.
 */

enum TOWER_TYPE {
	SOURCE = 0x0000,
	TEMP   = 0x0001,
	TARGET = 0x0002
};

namespace RECURRENCE {	
	template <typename T>
	class Tower {
	public:
		Tower(const TOWER_TYPE& type);
		Tower(const Tower& rhs);
		Tower& operator = (const Tower& rhs);
		~Tower();

		void Front(const T& data);
		T Front();

		void Back(const T& data);
		T Back();

		T First() const;
		T Last() const;
		
		TOWER_TYPE Type() const;
		void Print() const;
		void PrintR() const;
		int Size() const;

	private:
		TOWER_TYPE m_type;
		std::deque<T> m_queue;
	};
};

template <typename T>
RECURRENCE::Tower<T>::Tower(const TOWER_TYPE& type) : m_type(type) {}

template <typename T>
RECURRENCE::Tower<T>::Tower(const Tower& rhs) {
	m_type = rhs.m_type;
	m_queue.erase(m_queue.begin(), m_queue.end());
	for (std::size_t i = 0; i < rhs.m_queue.size(); ++i)
		m_queue.push_front(rhs.m_queue[i]);
}

template <typename T>
RECURRENCE::Tower<T>& RECURRENCE::Tower<T>::operator = (const Tower& rhs) {
	m_type = rhs.m_type;
	m_queue.erase(m_queue.begin(), m_queue.end());
	for (std::size_t i = 0; i < rhs.m_queue.size(); ++i)
		m_queue.push_front(rhs.m_queue[i]);
	return *this;
}

template <typename T>
RECURRENCE::Tower<T>::~Tower() {}

template <typename T>
void RECURRENCE::Tower<T>::Front(const T& data) {
	m_queue.push_front(data);
}

template <typename T>
T RECURRENCE::Tower<T>::Front() {
	const T data = m_queue.front();
	m_queue.erase(m_queue.begin());
	return data;
}

template <typename T>
void RECURRENCE::Tower<T>::Back(const T& data) {
	m_queue.push_back(data);
}

template <typename T>
T RECURRENCE::Tower<T>::Back() {
	const T data = m_queue.back();
	m_queue.erase(m_queue.begin() + m_queue.size() - 1);
	return data;
}

template <typename T>
T RECURRENCE::Tower<T>::First() const {
	return m_queue.front();
}

template <typename T>
T RECURRENCE::Tower<T>::Last() const {
	return m_queue.back();
}

template <typename T>
TOWER_TYPE RECURRENCE::Tower<T>::Type() const {
	return m_type;
}

template <typename T>
void RECURRENCE::Tower<T>::Print() const {
	const std::size_t size = m_queue.size();
	if (size)
		for (std::size_t i = 0; i < size; ++i)
			std::cout << m_queue[i] << "  ";
}

template <typename T>
void RECURRENCE::Tower<T>::PrintR() const {
	const int size = m_queue.size();
	if (size)
		for (int i = size - 1; i >= 0; --i)
			std::cout << m_queue[i] << "  ";
}

template <typename T>
int RECURRENCE::Tower<T>::Size() const {
	return m_queue.size();
}

#endif // ALGORITHMS_RECURRENCE_TOWER_H_
