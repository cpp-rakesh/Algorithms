#ifndef ALGORITHM_RECURRENCE_KARATSUBA_INTEGER_H_
#define ALGORITHM_RECURRENCE_KARATSUBA_INTEGER_H_

#include <string>

class Integer {
public:
    // Constructors
    Integer();
    Integer(const std::string& data);
    Integer(int data);

    // Copy and copy assignment constructors
    Integer(const Integer& rhs);
    Integer& operator = (const Integer& rhs);

    // Addition operators
    Integer operator + (const Integer& rhs);
    Integer operator + (const std::string& rhs);
    Integer operator + (int rhs);

    void operator += (const Integer& rhs);
    void operator += (const std::string& rhs);
    void operator += (int rhs);

    // Subtraction operators
    Integer operator - (const Integer& rhs);
    Integer operator - (const std::string& rhs);
    Integer operator - (int rhs);

    void operator -= (const Integer& rhs);
    void operator -= (const std::string& rhs);
    void operator -= (int rhs);

    // Multiplication operators
    Integer operator * (const Integer& rhs);
    Integer operator * (const std::string& rhs);
    Integer operator * (int rhs);

    void operator *= (const Integer& rhs);
    void operator *= (const std::string& rhs);
    void operator *= (int rhs);

    void Print() const;
    std::size_t Size() const;
    std::string GetReverse() const;

private:
    // It will hold the big number;
    std::string m_data;

    // This will hold the sign of the Integer
    // True  = Negative
    // False = Positve
    bool m_sign;

    // These functions will eventually add the two numbers
    Integer m_add_return(const Integer& rhs);
    Integer m_add_return(const std::string& rhs, bool is_sign);
    Integer m_add_return(int rhs);

    void m_add(const Integer& rhs);
    void m_add(const std::string& rhs, bool is_sign);
    void m_add(int rhs);

    Integer m_subtract_return(const std::string& A, const std::string& B);
    void m_subtract(std::string& A, const std::string& B);
        
    bool operator > (const std::string& rhs);
    bool operator < (const std::string& rhs);
    bool operator == (const std::string& rhs);
    bool operator != (const std::string& rhs);

    void m_reverse_copy(const std::string& data, std::string& result, int start_pos);
    void m_convert_to_reverse_string(int data, std::string& result);
};

#endif // ALGORITHM_RECURRENCE_KARATSUBA_INTEGER_H_
