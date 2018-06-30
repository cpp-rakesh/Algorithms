/*
  --------------------------------------------------------------------------------------
  				     THE QUEENS PROBLEM
  --------------------------------------------------------------------------------------
  A well known problem is to count the number of different ways in which eight
  queens can be placed on an 8×8 chess board without any two of them sharing the
  same row, column or diagonal.
  --------------------------------------------------------------------------------------

  Algorithm based on Backtracking using Bit Patterns and Recursion

  Author: Rakesh Kumar, cpp.rakesh@gmail.com
  Date  : Feb 2nd, 2017
 */

#include <string>

namespace algorithms {
    namespace backtracking {
        class Queens {
        public:
            Queens();
            ~Queens();

            int Total(int n);
            void ComputeAll(int n);

        private:
            int m_all;
            int m_total_count;
            std::string m_row_positions;

            void m_total(int ld, int col, int rd);
            bool m_is_valid(int queen_number, int pos) const;
            void m_compute(int k);
            void m_draw_board();
        };
    };
};
