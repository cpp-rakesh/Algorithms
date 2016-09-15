#ifndef ALGORITHMS_RECURRENCE_INTEGER_H_
#define ALGORITHMS_RECURRENCE_INTEGER_H_

/*
  A Big integer implementation for Basic Arthematic operations.
  As c++ can't store big numbers why not to implement our own.
  Author: Rakesh Kumar cpp.rakesh@gmail.com
  Date: Sep 9th, 2016
*/

#include <cstdio>
#include <string>
#include <vector>

class Integer {
public:
    // Default Initialization
    Integer();

    // Initialize with std::string
    Integer(const std::string& data);

    // Initialization std::vector<int>
    Integer(const std::vector<int>& data);

    // Intitialization with int.
    Integer(int data);

    // Copy constructor
    Integer(const Integer& rhs);

    // Copy assignment operator
    Integer& operator = (const Integer& rhs);

    ~Integer();

    // Addition functions
    Integer operator + (const Integer& rhs);
    Integer operator + (const std::string& rhs);
    Integer operator + (int rhs);

    // += functions
    void operator += (const Integer& rhs);
    void operator += (const std::string& rhs);
    void operator += (int rhs);

    // Subtraction functions
    Integer operator - (const Integer& rhs);
    Integer operator - (const std::string& rhs);
    Integer operator - (int rhs);

    // -= functions
    void operator -= (const Integer& rhs);
    void operator -= (const std::string& rhs);
    void operator -= (int rhs);

    // Multiplication functions
    Integer operator * (const Integer& rhs);
    Integer operator * (const std::string& rhs);
    Integer operator * (int rhs);

    // *= functions
    void operator *= (const Integer& rhs);
    void operator *= (const std::string& rhs);
    void operator *= (int rhs);

    // Comparission operators
    bool operator < (const Integer& rhs);
    bool operator > (const Integer& rhs);
    bool operator == (const Integer& rhs);

    std::size_t Size() const;
    void Print() const;
    std::string Get() const;
    std::string GetReverse() const;

private:
    bool        m_sign;
    std::string m_data;

    Integer m_add_return(const Integer& rhs);
    Integer m_add_return(const std::string& rhs);
    Integer m_add_return(int rhs);

    void m_add(const Integer& rhs);
    void m_add(const std::string& rhs);
    void m_add(int rhs);

    // This function will do the actual subtraction of the data.
    // When operator -= has been called.
    void m_subtract(std::string& lhs, const std::string& rhs);
    // This function will perform the subtraction of the data.
    // When operator - has been called.
    void m_subtract(const std::string& A, const std::string& B, std::string& R);

    // Let get the sign of the big of two Integers.
    // It will return true if the number will be negative.
    // However it will return false, which means it result of the number will be positive
    bool m_resultant_sign(const Integer& rhs);
};

#endif // ALGORITHMS_RECURRENCE_INTEGER_H_
