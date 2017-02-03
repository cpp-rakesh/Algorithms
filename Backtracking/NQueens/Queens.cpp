#include "Queens.h"
#include <cstdio>

namespace ab = algorithms::backtracking;

ab::Queens::Queens() {}

ab::Queens::~Queens() {}

int ab::Queens::Total(int n) {
    if (n == 0 || n == 1)
        return 1;
    
    m_total_count = 0;
    m_all = (1 << n) - 1;
    m_total(0, 0, 0);
    return m_total_count;
}

void ab::Queens::ComputeAll(int n) {    
    m_all = n;
    m_total_count = 0;
    for (int i = 0; i < n; ++i)
        m_row_positions.push_back('0');
    m_compute(0);
    printf("Total permutations found == [%d]\n", m_total_count);
}

// Algorithm based on Richard Miller, Backtracking, Bitpattern and Recursion
void ab::Queens::m_total(int ld, int col, int rd) {
    
    if (col == m_all) {
        ++m_total_count;
        return;
    }

    int pos = ~(ld | rd | col) & m_all;
    while (pos) {
        const int bit = pos & -pos;
        pos -= bit;
        m_total((ld | bit) >> 1, col | bit, (rd | bit) << 1);
    }    
}

bool ab::Queens::m_is_valid(int queen_number, int pos) const
{
    for (int i = 0; i < queen_number; ++i)
        if (m_row_positions[i] - '0' == pos|| // Same row
            m_row_positions[i] - '0' == pos - (queen_number - i) || // Same diagonal
            m_row_positions[i] - '0' == pos + (queen_number - i))   // Same diagonal
            return false;
    
    return true;
}

void ab::Queens::m_compute(int k)
{
    if (k == m_all) {
        ++m_total_count;
        m_draw_board();
    } else {
        for (int i = 0; i < m_all; ++i) {
            if (m_is_valid(k, i)) {
                m_row_positions[k] = i + '0';
                m_compute(k + 1);
            }
        }
    }
}

void ab::Queens::m_draw_board() {
    printf("--------------- Possibility [%5d] ------------------\n", m_total_count);
    for (int r = 0; r < m_all; ++r) {
        for (int c = 0; c < m_all; ++c) {
            if (r == m_row_positions[c] - '0')
                printf("| Q ");
            else
                printf("| . ");
        }
        printf("|\n");
    }
    printf("------------------------------------------------------\n");        
}
