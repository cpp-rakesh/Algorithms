#include "Integer.h"

Integer::Integer() {}

Integer::Integer(const std::string& data) {
    for (int i = data.size(); i >= 0; --i)
        m_data.push_back(data[i]);
}

Integer::Integer(const std::vector<int>& data) {
    for (int i = data.size(); i >= 0; --i)
        m_data.push_back(data[i] + '0');
}

Integer::Integer(int data) {
    if (data == 0)
        m_data.push_back('0');
    while (data) {
        m_data.push_back((data % 10) + '0');
        data /= 10;
    }
}

Integer::Integer(const Integer& rhs) {
    m_data = rhs.m_data;
}

Integer& Integer::operator = (const Integer& rhs) {
    m_data = rhs.m_data;
    return *this;
}

Integer::~Integer() {}

Integer Integer::operator + (const Integer& rhs) {
    Integer number;
    std::size_t i = 0;
    std::size_t j = 0;
    int carry = 0;

    while (i < m_data.size() && j < rhs.m_data.size()) {
        const int sum = carry + (m_data[i++] - '0' + rhs.m_data[j++] - '0');
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (i < m_data.size()) {
        const int sum = carry + (m_data[i++] - '0');
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (j < rhs.m_data.size()) {
        const int sum = carry + (rhs.m_data[j++] - '0');
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (carry) {
        number.m_data.push_back(carry% 10 + '0');
        carry /= 10;
    }

    return number;
}

Integer Integer::operator + (const int& rhs) {
    Integer number;
    int carry = 0;
    for (std::size_t i = 0; i < m_data.size(); ++i) {
        const int sum = carry + rhs + m_data[i] - '0';
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (carry) {
        number.m_data.push_back(carry% 10 + '0');
        carry /= 10;        
    }

    return number;
}

void Integer::operator += (const Integer& rhs) {
    std::size_t i = 0;
    std::size_t j = 0;
    int carry = 0;
    
    while (i < m_data.size() && j < rhs.m_data.size()) {
        const int sum = carry + (m_data[i] - '0' + rhs.m_data[j++] - '0');
        m_data[i++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    while (j < rhs.m_data.size()) {
        const int sum = carry + (rhs.m_data[j++]);
    }
}

void Integer::Print() const {
    for (int i = m_data.length() - 1; i >= 0; --i)
        printf("%c", m_data[i]);
    printf("\n");
}
