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
    // Default constructor
    Integer();

    // This constructor will take the input string as we see the
    // number in 12345 order, because we need to add from the last
    // number, we can save reverse, and when adding carry value it will be
    // always at back, which will easily save the shift cost.
    Integer(const std::string& data);

    // This construction will take the input as std::vector<int> type.
    // Normal way
    Integer(const std::vector<int>& data);

    // Normal Integer value intial
    Integer(int data);

    // Copy constructor
    Integer(const Integer& rhs);

    // Copy assignment operator
    Integer& operator = (const Integer& rhs);

    ~Integer();

    Integer operator + (const Integer& rhs);
    Integer operator + (const int& rhs);

    void operator += (const Integer& rhs);
    void operator += (const int& rhs);

    void Print() const;

private:
    std::string m_data;  
};

#endif // ALGORITHMS_RECURRENCE_INTEGER_H_
