#include "Integer.h"
#include <algorithm>

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

Integer::Integer(const std::vector<int>& data) : m_sign(false) {
    for (int i = data.size() - 1; i >= 0; --i)
        m_data.push_back(data[i] + '0');
}

Integer::Integer(int data) : m_sign(false) {
    if (data == 0) {
        m_data.push_back('0'); 
    } else if (data < 0) {
        m_sign = true;
        data = data * -1;
    }
    
    while (data) {
        m_data.push_back((data % 10) + '0');
        data /= 10;
    }
}

Integer::Integer(const Integer& rhs) {
    m_data = rhs.m_data;
    m_sign = rhs.m_sign;
}

Integer& Integer::operator = (const Integer& rhs) {
    m_data = rhs.m_data;
    m_sign = rhs.m_sign;
    
    return *this;
}

Integer::~Integer() {}

Integer Integer::operator + (const Integer& rhs) {
    Integer number;
    if (m_sign || rhs.m_sign) {
        number.m_sign = m_resultant_sign(rhs);
        if (*this == rhs) {
            return number;
        } else if (*this > rhs) {
            m_subtract(m_data, rhs.m_data, number.m_data);
            return number;
        } else {
            m_subtract(rhs.m_data, m_data, number.m_data);
            return number;            
        }
    }

    return m_add_return(rhs);
}

Integer Integer::operator + (const std::string& rhs) {
    return m_add_return(rhs);
}

Integer Integer::operator + (int rhs) {
    return m_add_return(rhs);
}

void Integer::operator += (const Integer& rhs) {
    if (m_sign || rhs.m_sign) {
        m_sign = m_resultant_sign(rhs);
        if (*this == rhs) {
            m_data.erase(m_data.begin(), m_data.end());
            m_sign = false;
            m_data.push_back('0');
        } else if (*this > rhs) {
            m_subtract(m_data, rhs.m_data);
        } else {
            std::string temp_rhs = rhs.m_data;
            m_subtract(temp_rhs, m_data);
            m_data = temp_rhs;
        }
    }
    
    std::size_t i = 0;
    std::size_t j = 0;
    int carry = 0;

    while (i < m_data.size() && j < rhs.m_data.size()) {
        const int sum = carry + (m_data[i] - '0') + (rhs.m_data[j++] - '0');
        m_data[i++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    while (i < m_data.size()) {
        const int sum = carry + (m_data[i] - '0');
        m_data[i++] = (sum % 10) + '0';
        carry = sum / 10;

        if (carry == 0)
            break;
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

void Integer::operator += (const std::string& rhs) {
    std::size_t i = 0;
    int j = rhs.size() - 1;
    int carry = 0;

    while (i < m_data.size() && j >= 0) {
        const int sum = carry + (m_data[i] - '0') + (rhs[j--] - '0');
        m_data[i++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    while (i < m_data.size()) {
        const int sum = carry + (m_data[i] - '0');
        m_data[i++] = (sum % 10) + '0';
        carry = sum / 10;

        if (carry == 0)
            break;
    }

    while (j >= 0) {
        const int sum = carry + (rhs[j--] - '0');
        m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (carry) {
        m_data.push_back((carry % 10) + '0');
        carry /= 10;
    }
}

void Integer::operator += (int rhs) {
    int carry = rhs;

    for (std::size_t i = 0; i < m_data.size(); ++i) {
        const int sum = carry + m_data[i] - '0';
        m_data[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    while (carry) {
        m_data.push_back((carry % 10) + '0');
        carry /= 10;
    }
}

Integer Integer::operator - (const Integer& rhs) {
    // As the data of the string always stored in the reverse order.
    // For school grade natural arethmatic operations.
    // We need to use string comparission in oposite way.

    Integer number;
    number.m_sign = m_resultant_sign(rhs);
    // This will be normal subtraction.
    if ((m_sign && rhs.m_sign) ||
        (m_sign == false && rhs.m_sign == false)) {
        if (*this == rhs) {
            number.m_data.push_back('0');
            number.m_sign = false;
            return number;
        } else if (*this < rhs) {
            m_subtract(rhs.m_data, m_data, number.m_data);
            return number;
        } else {
            m_subtract(m_data, rhs.m_data, number.m_data);
            return number;
        }
    } else {
        printf("m_sign == [%d]\n", m_sign);
        // This will be addition
        number = m_add_return(rhs);
        return number;
    }
}

Integer Integer::operator - (const std::string& rhs) {
}

Integer Integer::operator - (int rhs) {
}

void Integer::operator -= (const Integer& rhs) {
}

void Integer::operator -= (const std::string& rhs) {
}

void Integer::operator -= (int rhs) {
}

Integer Integer::operator * (const Integer& rhs) {
    Integer number;

    if (m_sign && rhs.m_sign)
        number.m_sign = false;
    else if (m_sign || rhs.m_sign)
        number.m_sign = true;
    
    for (std::size_t i = 0; i < m_data.size(); ++i) {
        std::string result;

        for (std::size_t j = 0; j < i; ++j)
            result.push_back('0');

        int carry = 0;

        for (std::size_t j = 0; j < rhs.m_data.size(); ++j) {
            const int sum = carry + ((m_data[i] - '0') * (rhs.m_data[j] - '0'));
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        while (carry) {
            result.push_back((carry % 10) + '0');
            carry /= 10;
        }

        std::reverse(result.begin(), result.end());
        number += result;
    }

    return number;
}

Integer Integer::operator * (const std::string& rhs) {
    Integer number;
    int stop = 0;
    bool sign = false;

    if (rhs[0] == '0') {
        sign = true;
        ++stop;
    }

    if (m_sign && sign)
        m_sign = false;
    else if (m_sign || sign)
        m_sign = true;
    
    for (std::size_t i = 0; i < m_data.size(); ++i) {
        std::string result;

        for (std::size_t j = 0; j < i; ++j)
            result.push_back('0');

        int carry = 0;

        for (int j = rhs.size() - 1; j >= stop; --j) {
            const int sum = carry + ((m_data[i] - '0') * (rhs[j] - '0'));
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        while (carry) {
            result.push_back((carry % 10) + '0');
            carry /= 10;
        }

        std::reverse(result.begin(), result.end());
        number += result;
    }

    return number;
}

Integer Integer::operator * (int rhs) {
    Integer number;
    bool sign = false;

    if (rhs < 0) {
        sign = true;
        rhs *= -1;
    }

    if (m_sign && sign)
        m_sign = false;
    else if (m_sign || sign)
        m_sign = true;
    
    for (std::size_t i = 0; i < m_data.size(); ++i) {
        std::string result;

        for (std::size_t j = 0; j < i; ++j)
            result.push_back('0');

        int carry = 0;

        const int sum = carry + ((m_data[i] - '0') * rhs);
        result.push_back((sum % 10) + '0');
        carry = sum / 10;

        while (carry) {
            result.push_back((carry % 10) + '0');
            carry /= 10;
        }

        std::reverse(result.begin(), result.end());
        number += result;
    }

    return number;
}

void Integer::operator *= (const Integer& rhs) {
}

void Integer::operator *= (const std::string& rhs) {
}

void Integer::operator *= (int rhs) {
}

bool Integer::operator < (const Integer& rhs) {
    if (m_data.size() < rhs.m_data.size()) {
        return true;
    } else if (m_data.size() > rhs.m_data.size()) {
        return false;
    } else {
        for (int i = m_data.size() - 1; i >= 0; --i)
            if (m_data[i] != rhs.m_data[i])
                if (m_data[i] < rhs.m_data[i])
                    return true;
                else
                    return false;
    }
}

bool Integer::operator > (const Integer& rhs) {
    if (m_data.size() > rhs.m_data.size()) {
        return true;
    } else if (m_data.size() < rhs.m_data.size()) {
        return false;
    } else {
        for (int i = m_data.size() - 1; i >= 0; --i)
            if (m_data[i] != rhs.m_data[i])
                if (m_data[i] > rhs.m_data[i])
                    return true;
                else
                    return false;
    }
}

bool Integer::operator == (const Integer& rhs) {
    if (m_sign != rhs.m_sign)
        return false;
    if (m_data.size() != rhs.m_data.size()) {
        return false;
    } else {
        for (std::size_t i = 0; i < m_data.size(); ++i)
            if (m_data[i] != rhs.m_data[i])
                return false;
    }

    return true;
}

std::size_t Integer::Size() const {
    return m_data.size();
}

void Integer::Print() const {
    if (m_sign)
        printf("-");
    for (int i = m_data.length() - 1; i >= 0; --i)
        printf("%c", m_data[i]);
    printf("\n");
}

std::string Integer::Get() const {
    std::string data = m_data;
    std::reverse(data.begin(), data.end());
    return data;
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
        const int sum = carry + (m_data[i++] - '0' + rhs.m_data[j++] - '0');
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (i < m_data.size()) {
        const int sum = carry + (m_data[i++] - '0');
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
        if (carry == 0)
            break;
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

Integer Integer::m_add_return(const std::string& rhs) {
    Integer number;
    std::size_t i = 0;
    int j = rhs.size() - 1;
    int carry = 0;

    while (i < m_data.size() && j >= 0) {
        const int sum = carry + (m_data[i++] - '0') + (rhs[j--]);
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (i < m_data.size()) {
        const int sum = carry + (m_data[i++] - '0');
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;

        if (carry == 0)
            break;
    }

    while (j >= 0) {
        const int sum = carry + (rhs[j--] - '0');
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;        
    }

    while (carry) {
        number.m_data.push_back((carry % 10) + '0');
        carry /= 10;
    }    
}

Integer Integer::m_add_return(int rhs) {
    Integer number;
    int carry = rhs;
    for (std::size_t i = 0; i < m_data.size(); ++i) {
        const int sum = carry +  m_data[i] - '0';
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (carry) {
        number.m_data.push_back(carry% 10 + '0');
        carry /= 10;        
    }

    return number;    
}

void Integer::m_subtract(std::string& A, const std::string& B) {
    std::size_t i = 0;

    while (i < A.size() && i < B.size()) {
        if (A[i] < B[i]) {
            if (A[i + 1] != '0') {
                --A[i + 1];
            } else {
                std::size_t k = i + 1;
                while (A[k] == '0' && k < A.size())
                    --A[k++] = '9';
                if (A[k] == '1' && A.size() - 1 == k)
                    A.erase(k);
                else
                    --A[k];
            }
            const int diff = (10 + A[i] - '0') - (B[i] - '0');
            A[i] = diff + '0';
        } else {
            const int diff = (A[i] - '0') - (B[i] - '0');
            A[i] = diff + '0';
        }
        
        ++i;
    }
}

void Integer::m_subtract(const std::string& A, const std::string& B, std::string& R) {
    std::string TA = A;
    std::size_t i = 0;

    while (i < TA.size() && i < B.size()) {
        if (TA[i] < B[i]) {
            if (TA[i + 1] != '0') {
                --TA[i + 1];
            } else {
                std::size_t k = i + 1;
                while (TA[k] == '0' && k < TA.size())
                    --TA[k++] = '9';
                if (TA[k] == '1' && TA.size() - 1 == k)
                    TA.erase(k);
                else
                    --TA[k];
            }
            const int diff = (10 + TA[i] - '0') - (B[i] - '0');
            R.push_back(diff + '0');
        } else {
            const int diff = (TA[i] - '0') - (B[i] - '0');
            R.push_back(diff + '0');
        }
        
        ++i;
    }

    while (i < TA.size())
        R.push_back(TA[i++]);
}

bool Integer::m_resultant_sign(const Integer& rhs) {
    if (m_sign && rhs.m_sign)
        return true;

    if (m_sign == false && rhs.m_sign == false)
        return false;

    if (*this > rhs)
        return m_sign;
    else if (*this < rhs)
        return rhs.m_sign;
}
