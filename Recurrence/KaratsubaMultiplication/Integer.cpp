#include "Integer.h"
#include <cstdio>

Integer::Integer() : m_sign(false) {}

Integer::Integer(const std::string& data) : m_sign(false) {
    int stop = 0;
    if (data[0] == '-') {
        m_sign = true;
        ++stop;
    }
    
    for (int i = data.size() - 1; i >= stop; --i)
        m_data.push_back(data[i]);
}

Integer::Integer(int data) : m_sign(false) {
    if (data < 0) {
        m_sign = true;
        data *= -1;
    }
    
    while (data) {
        m_data.push_back((data % 10) + '0');
        data /= 10;
    }
}

Integer::Integer(const Integer& rhs) {
    m_data.erase(m_data.begin(), m_data.end());
    m_sign = rhs.m_sign;
    m_data = rhs.m_data;
}

Integer& Integer::operator = (const Integer& rhs) {
    m_data.erase(m_data.begin(), m_data.end());
    m_sign = rhs.m_sign;
    m_data = rhs.m_data;
    return *this;
}

Integer Integer::operator + (const Integer& rhs) {
    if (m_sign == false && rhs.m_sign == false)
        return m_add_return(rhs);

    if (m_sign && rhs.m_sign) {
        Integer number = m_add_return(rhs);
        number.m_sign = true;
        return number;
    }

    Integer number;
    if (*this > rhs.m_data) {
        number.m_sign = m_sign;
        return m_subtract_return(m_data, rhs.m_data);
    } else if (*this < rhs.m_data) {
        number.m_sign = rhs.m_sign;
        return m_subtract_return(rhs.m_data, m_data);
    } else {
        number.m_data.push_back('0');
        return number;
    }
}

Integer Integer::operator + (const std::string& rhs) {
    bool sign = false;
    if (rhs[0] == '0')
        sign = true;
    if (m_sign == false && sign == false)
        return m_add_return(rhs, sign);

    if (m_sign && sign) {
        Integer number = m_add_return(rhs, sign);
        number.m_sign = true;
        return number;
    }

    std::string temp_rhs;
    if (sign)
        m_reverse_copy(rhs, temp_rhs, 1);
    else
        m_reverse_copy(rhs, temp_rhs, 0);

    Integer number;    
    if (*this > temp_rhs) {
        number.m_sign = m_sign;
        return m_subtract_return(m_data, temp_rhs);
    } else if (*this < temp_rhs) {
        number.m_sign = sign;
        return m_subtract_return(temp_rhs, m_data);
    } else {
        number.m_data.push_back('0');
        return number;
    }        
}

Integer Integer::operator + (int rhs) {
    int sign = false;
    if (rhs < 0) {
        sign = true;
        rhs *= -1;
    }

    if (m_sign == false && sign == false)
        return m_add_return(rhs);

    if (m_sign && sign) {
        Integer number = m_add_return(rhs);
        number.m_sign = true;
        return number;
    }

    std::string temp_rhs;
    m_convert_to_reverse_string(rhs, temp_rhs);

    Integer number;
    if (*this > temp_rhs) {
        number.m_sign = m_sign;
        return m_subtract_return(m_data, temp_rhs);
    } else if (*this < temp_rhs) {
        number.m_sign = sign;
        return m_subtract_return(temp_rhs, m_data);
    } else {
        number.m_data.push_back('0');
        return number;
    }
}

void Integer::operator += (const Integer& rhs) {
    if (m_sign == false && rhs.m_sign == false)
        return m_add(rhs);

    if (m_sign && rhs.m_sign) {
        m_sign = true;
        return m_add(rhs);
    }

    if (*this > rhs.m_data) {
        return m_subtract(m_data, rhs.m_data);
    } else if (*this < rhs.m_data) {
        std::string temp_rhs = rhs.m_data;
        m_subtract(temp_rhs, m_data);
        m_data = temp_rhs;
        m_sign = rhs.m_sign;        
    } else {
        m_data.erase(m_data.begin(), m_data.end());
        m_data.push_back('0');
        m_sign = false;
    }    
}

void Integer::operator += (const std::string& rhs) {
    bool sign = false;
    if (rhs[0] == '0')
        sign = true;
    if (m_sign == false && sign == false)
        return m_add(rhs, sign);

    if (m_sign && sign) {
        m_sign = true;
        return m_add(rhs, sign);;
    }-

    std::string temp_rhs;
    if (sign)
        m_reverse_copy(rhs, temp_rhs, 1);
    else
        m_reverse_copy(rhs, temp_rhs, 0);

    if (*this > temp_rhs) {
        m_subtract(m_data, temp_rhs);
    } else if (*this < temp_rhs) {
        m_subtract(temp_rhs, m_data);
        m_data = temp_rhs;
        m_sign = sign;
    } else {
        m_data.erase(m_data.begin(), m_data.end());
        m_data.push_back('0');
        m_sign = false;
    }    
}

void Integer::operator += (int rhs) {
    int sign = false;
    if (rhs < 0) {
        sign = true;
        rhs *= -1;
    }

    if (m_sign == false && sign == false)
        return m_add(rhs);

    if (m_sign && sign) {
        m_sign = true;
        return m_add(rhs);
    }

    std::string temp_rhs;
    m_convert_to_reverse_string(rhs, temp_rhs);

    if (*this > temp_rhs) {
        m_subtract(m_data, temp_rhs);
    } else if (*this < temp_rhs) {
        m_subtract(temp_rhs, m_data);
        m_data = temp_rhs;
        m_sign = sign;
    } else {
        m_data.erase(m_data.begin(), m_data.end());
        m_data.push_back('0');
        m_sign = false;
    }    
}

Integer Integer::operator - (const Integer& rhs) {
    if (m_sign == false && rhs.m_sign)
        return m_add_return(rhs);

    Integer number;
    if (*this > rhs.m_data) {
        number.m_sign = m_sign;
        return m_subtract_return(m_data, rhs.m_data);
    } else if (*this < rhs.m_data) {
        number.m_sign = rhs.m_sign;
        return m_subtract_return(rhs.m_data, m_data);
    } else {
        number.m_data.push_back('0');
        return number;
    }
}

Integer Integer::operator - (const std::string& rhs) {
    bool sign = false;
    
    if (rhs[0] == '-')
        sign = true;
    
    if (m_sign == false && sign)
        return m_add_return(rhs, true);

    std::string temp_rhs;
    if (sign)
        m_reverse_copy(rhs, temp_rhs, 1);
    else
        m_reverse_copy(rhs, temp_rhs, 0);

    Integer number;    
    if (*this > temp_rhs) {
        number.m_sign = m_sign;
        return m_subtract_return(m_data, temp_rhs);
    } else if (*this < temp_rhs) {
        number.m_sign = sign;
        return m_subtract_return(temp_rhs, m_data);
    } else {
        number.m_data.push_back('0');
        return number;
    }    
}

Integer Integer::operator - (int rhs) {
    bool sign = false;
    if (rhs < 0) {
        rhs *= -1;
        sign = true;
    }

    std::string temp_rhs;
    m_convert_to_reverse_string(rhs, temp_rhs);

    Integer number;
    if (*this > temp_rhs) {
        number.m_sign = m_sign;
        return m_subtract_return(m_data, temp_rhs);
    } else if (*this < temp_rhs) {
        number.m_sign = sign;
        return m_subtract_return(temp_rhs, m_data);
    } else {
        number.m_data.push_back('0');
        return number;
    }
}

void Integer::operator -= (const Integer& rhs) {
    if (m_sign == false && rhs.m_sign)
        return m_add(rhs);

    if (*this > rhs.m_data) {
        m_subtract(m_data, rhs.m_data);
    } else if (*this < rhs.m_data) {
        std::string temp_rhs = rhs.m_data;
        m_subtract(temp_rhs, m_data);
        m_data = temp_rhs;
        m_sign = rhs.m_sign;
    } else {
        m_data.erase(m_data.begin(), m_data.end());
        m_data.push_back('0');
        m_sign = false;
    }    
}

void Integer::operator -= (const std::string& rhs) {
    bool sign = false;
    if (rhs[0] == '-')
        sign = true;
    
    if (m_sign == false && sign)
        return m_add(rhs, true);

    std::string temp_rhs;
    if (sign)
        m_reverse_copy(rhs, temp_rhs, 1);
    else
        m_reverse_copy(rhs, temp_rhs, 0);

    if (*this > rhs) {
        m_subtract(m_data, temp_rhs);
    } else if (*this < rhs) {
        m_subtract(temp_rhs, m_data);
        m_data = temp_rhs;
        m_sign = sign;
    } else {
        m_data.erase(m_data.begin(), m_data.end());        
        m_data.push_back('0');
        m_sign = false;
    }        
}

void Integer::operator -= (int rhs) {
    bool sign = false;
    if (rhs < 0) {
        sign = true;
        rhs *= -1;
    }
    
    if (m_sign == false && sign)
        return m_add(rhs);

    std::string temp_rhs;
    m_convert_to_reverse_string(rhs, temp_rhs);

    if (*this > temp_rhs) {
        m_subtract(m_data, temp_rhs);
    } else if (*this < temp_rhs) {
        m_subtract(temp_rhs, m_data);
        m_data = temp_rhs;
        m_sign = sign;
    } else {
        m_data.erase(m_data.begin(), m_data.end());
        m_data.push_back('0');
        m_sign = false;
    }    
}

Integer Integer::operator * (const Integer& rhs) {
    Integer number;
    if (m_sign || rhs.m_sign)
        number.m_sign = true;

    for (std::size_t i = 0; i < m_data.size(); ++i) {
        int carry = 0;
        Integer temp;

        // Add 0, as we do in school grade mathematics.
        // while doing mathematics.
        for (std::size_t j = 0; j < i; ++i)
            temp.m_data.push_back('0');
        
        for (std::size_t j = 0; j < rhs.m_data.size(); ++j) {
            int mul = carry + ((m_data[i] - '0') * (rhs.m_data[j] - '0'));
            temp.m_data.push_back((mul % 10) + '0');
            carry = mul / 10;
        }

        while (carry) {
            temp.m_data.push_back((carry % 10) + '0');
            carry /= 10;
        }

        number += temp;
    }

    return number;
}

Integer Integer::operator * (const std::string& rhs) {
    int stop = 0;
    Integer number;
    if (m_sign || rhs[0] == '-') {
        number.m_sign = true;
        ++stop;
    }

    for (std::size_t i = 0; i < m_data.size(); ++i) {
        int carry = 0;
        Integer temp;

        // Add 0, as we do in school grade mathematics.
        // while doing mathematics.
        for (std::size_t j = 0; j < i; ++i)
            temp.m_data.push_back('0');
        
        for (int j = rhs.size() - 1; j >= stop; --j) {
            int mul = carry + ((m_data[i] - '0') * (rhs[j] - '0'));
            temp.m_data.push_back((mul % 10) + '0');
            carry = mul / 10;
        }

        while (carry) {
            temp.m_data.push_back((carry % 10) + '0');
            carry /= 10;
        }

        number += temp;
    }

    return number;
}

Integer Integer::operator * (int rhs) {
    Integer number;
    if (m_sign || rhs < 0) {
        number.m_sign = true;

        if (rhs < 0)
            rhs *= -1;        
    }

    int carry = 0;
    for (std::size_t i = 0; i < m_data.size(); ++i) {
        int mul = carry + ((m_data[i] - '0') * rhs);
        number.m_data.push_back((mul % 10) + '0');
        carry = mul / 10;
    }

    return number;
}

void Integer::operator *= (const Integer& rhs) {
    Integer number;
    if (m_sign || rhs.m_sign)
        m_sign = true;

    for (std::size_t i = 0; i < m_data.size(); ++i) {
        int carry = 0;
        Integer temp;

        // Add 0, as we do in school grade mathematics.
        // while doing mathematics.
        for (std::size_t j = 0; j < i; ++i)
            temp.m_data.push_back('0');
        
        for (std::size_t j = 0; j < rhs.m_data.size(); ++j) {
            int mul = carry + ((m_data[i] - '0') * (rhs.m_data[j] - '0'));
            temp.m_data.push_back((mul % 10) + '0');
            carry = mul / 10;
        }

        while (carry) {
            temp.m_data.push_back((carry % 10) + '0');
            carry /= 10;
        }

        number += temp;
    }

    m_data = number.m_data;
}

void Integer::operator *= (const std::string& rhs) {
    int stop = 0;
    Integer number;
    if (m_sign || rhs[0] == '-') {
        number.m_sign = true;
        ++stop;
    }

    for (std::size_t i = 0; i < m_data.size(); ++i) {
        int carry = 0;
        Integer temp;

        // Add 0, as we do in school grade mathematics.
        // while doing mathematics.
        for (std::size_t j = 0; j < i; ++i)
            temp.m_data.push_back('0');
        
        for (int j = rhs.size() - 1; j >= stop; --j) {
            int mul = carry + ((m_data[i] - '0') * (rhs[j] - '0'));
            temp.m_data.push_back((mul % 10) + '0');
            carry = mul / 10;
        }

        while (carry) {
            temp.m_data.push_back((carry % 10) + '0');
            carry /= 10;
        }

        number += temp;
    }

    m_data = number.m_data;
}

void Integer::operator *= (int rhs) {
    if (rhs < 0) {
        m_sign = true;
        rhs *= -1;
    }

    int carry = 0;
    for (std::size_t i = 0; i < m_data.size(); ++i) {
        const int mul = carry + ((m_data[i] - '0') * rhs);
        m_data[i] = (mul % 10) + '0';
        carry = mul / 10;
    }

    while (carry) {
        m_data.push_back((carry % 10) + '0');
        carry /= 10;
    }
}

void Integer::Print() const {
    if (m_sign)
        printf("-");
    for (int i = m_data.size() - 1; i >= 0; --i)
        printf("%c", m_data[i]);
    printf("\n");
}

std::size_t Integer::Size() const {
    return m_data.size();
}

std::string Integer::GetReverse() const {
    return m_data;
}

Integer Integer::m_add_return(const Integer& rhs) {
    Integer number;
    std::size_t i = 0;
    std::size_t j = 0;

    int carry = 0;
    while (i < m_data.size() && j < rhs.m_data.size()) {
        const int sum = carry + (m_data[i++] - '0') + (rhs.m_data[j++] - '0');
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
        number.m_data.push_back((carry % 10) + '0');
        carry /= 10;
    }

    return number;
}

Integer Integer::m_add_return(const std::string& rhs, bool is_sign) {
    Integer number;
    int stop = 0;
    if (is_sign)
        ++stop;

    std::size_t i = 0;
    int j = rhs.size() - 1;

    int carry = 0;
    while (i < m_data.size() && j >= stop) {
        const int sum = carry + (m_data[i++] - '0') + (rhs[j--] - '0');
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (i < m_data.size()) {
        const int sum = carry + (m_data[i++]);
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (j >= stop) {
        const int sum = carry + (rhs[j--] - '0');
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (carry) {
        number.m_data.push_back((carry % 10) + '0');
        carry /= 10;
    }

    return number;
}

Integer Integer::m_add_return(int rhs) {
    Integer number;
    int carry = rhs;

    for (std::size_t i = 0; i < m_data.size(); ++i) {
        const int sum = carry + (m_data[i] - '0');
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (carry) {
        number.m_data.push_back((carry % 10) + '0');
        carry /= 10;
    }
    
    return number;
}

void Integer::m_add(const Integer& rhs) {
    std::size_t i = 0;
    std::size_t j = 0;

    int carry = 0;
    while (i < m_data.size() && j < rhs.m_data.size()) {
        const int sum = carry + (m_data[i] - '0') + (rhs.m_data[j++] - '0');
        m_data[i++] = ((sum % 10) + '0');
        carry = sum / 10;
    }

    while (i < m_data.size()) {
        const int sum = carry + (m_data[i] - '0');
        m_data[i++] = ((sum % 10) + '0');
        carry = sum / 10;
    }

    while (j < rhs.m_data.size()) {
        const int sum = carry + (rhs.m_data[j++] - '0');
        m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (carry) {
        m_data.push_back((carry % 10) + '0');
        carry /= 10;
    }
}

void Integer::m_add(const std::string& rhs, bool is_sign) {
    int stop = 0;
    std::size_t i = 0;
    int j = rhs.size() - 1;

    if (is_sign)
        ++stop;

    int carry = 0;
    
    while (i < m_data.size() && j >= stop) {
        const int sum = carry + (m_data[i] - '0') + (rhs[j--] - '0');
        m_data[i++] = ((sum % 10) + '0');
        carry = sum / 10;
    }

    while (i < m_data.size()) {
        const int sum = carry + (m_data[i] - '0');
        m_data[i++] = ((sum % 10) + '0');
        carry = sum / 10;
    }

    while (j >= stop) {
        const int sum = carry + (rhs[j--] - '0');
        m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (carry) {
        m_data.push_back((carry % 10) + '0');
        carry /= 10;
    }
}

void Integer::m_add(int rhs) {
    int carry = rhs;
    for (std::size_t i = 0; i < m_data.size(); ++i) {
        const int sum = carry + (m_data[i] - '0');
        m_data[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    while (carry) {
        m_data.push_back((carry % 10) + '0');
        carry /= 10;
    }
}

Integer Integer::m_subtract_return(const std::string& A, const std::string& B) {
    Integer number;
    std::string TA = A;

    std::size_t i = 0;

    while (i < TA.size() && i < B.size()) {
        if (TA[i] >= B[i]) {
            number.m_data.push_back((TA[i] - '0') - (B[i] - '0') + '0');
        } else {
            number.m_data.push_back((10 + (TA[i] - '0') - (B[i] - '0')) + '0');

            std::size_t j = i + 1;
            while (TA[j] == '0')
                TA[j++] = '9';

            if (j == TA.size() - 1)
                TA.erase(j);

            --TA[j];
        }
        ++i;
    }

    while (i < TA.size()) {
        number.m_data.push_back(TA[i++]);
    }

    return number;
}

void Integer::m_subtract(std::string& A, const std::string& B) {
    std::size_t i = 0;

    while (i < A.size() && i < B.size()) {
        if (A[i] >= B[i]) {
            A[i] = ((A[i] - '0') - (B[i] - '0') + '0');
        } else {
            A[i] = 10 + ((A[i] - '0') - (B[i] - '0') + '0');

            std::size_t j = i + 1;
            while (A[j] == '0')
                A[j++] = '9';

            if (j == A.size() - 1)
                A.erase(j);

            --A[j];
        }
        ++i;
    }
}

bool Integer::operator > (const std::string& rhs) {
    if (m_data.size() > rhs.size()) {
        return true;
    } else if (m_data.size() < rhs.size()) {
        return false;
    } else {
        for (int i = m_data.size() - 1; i >= 0; --i)
            if (m_data[i] > rhs[i])
                return true;
    }
    
    return false;
}

bool Integer::operator < (const std::string& rhs) {
    if (m_data.size() < rhs.size()) {
        return true;
    } else if (m_data.size() > rhs.size()) {
        return false;
    } else {
        for (int i = m_data.size() - 1; i >= 0; --i)
            if (m_data[i] < rhs[i])
                return true;        
    }

    return false;
}

bool Integer::operator == (const std::string& rhs) {
    if (m_data.size() != rhs.size())
        return false;
    for (std::size_t i = 0; i < m_data.size(); ++i)
        if (m_data[i] != rhs[i])
            return false;
    
    return true;
}

bool Integer::operator != (const std::string& rhs) {
    if (m_data.size() != rhs.size())
        return true;

    for (std::size_t i = 0; i < m_data.size(); ++i)
        if (m_data[i] == rhs[i])
            return false;

    return true;
}

void Integer::m_reverse_copy(const std::string& data, std::string& result, int start_pos) {
    for (int i = data.size() - 1; i >= start_pos; --i)
        result.push_back(data[i]);
}

void Integer::m_convert_to_reverse_string(int data, std::string& result) {
    while (data) {
        result.push_back((data % 10) + '0');
        data /= 10;
    }
}
