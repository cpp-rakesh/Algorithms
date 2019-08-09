#include "universe.h"
#include <bits/stdc++.h>

Universe::Universe() {}

Universe::~Universe() {}

Universe::Universe(int n) {
    for (int r = 0; r < n; ++r) {
        std::vector<Cell> cells;
        for (int c = 0; c < n; ++c) {
            Cell cell;
            cell.state(m_random());
            cells.push_back(cell);
        }
        m_universe.push_back(cells);
    }
}

void Universe::generate() {
    for (std::size_t r = 0; r < m_universe.size(); ++r)
        for (std::size_t c = 0; c < m_universe[r].size(); ++c)
            m_universe[r][c].neighbours(m_neighbours(r, c));

    for (std::size_t r = 0; r < m_universe.size(); ++r) {
        for (std::size_t c = 0; c < m_universe[r].size(); ++c) {
            const bool s = m_apply(m_universe[r][c].state(), m_universe[r][c].neighbours());
            m_universe[r][c].state(s);
        }
    }
}

void Universe::print() const {
    printf("-----------------------------------------------------------\n");
    for (std::size_t r = 0; r < m_universe.size(); ++r) {
        for (std::size_t c = 0; c < m_universe[r].size(); ++c)
            printf("%c ", m_universe[r][c].state() ? 'O' : '.');
        printf("\n");
    }
    printf("-----------------------------------------------------------\n");
}

bool Universe::m_random() const {
    std::random_device rd;
    std::uniform_int_distribution<> dt(0, 1);
    return dt(rd);
}

int Universe::m_neighbours(int r, int c) const {
    int n = 0;
    for (int i = r - 1; i <= r + 1; ++i) {
        for (int j = c - 1; j <= c + 1; ++j) {
            if (i != j) {
                if (i >= 0 && i < m_universe.size() &&
                    j >= 0 && j < m_universe[i].size()) {
                    if (m_universe[i][j].state())
                        ++n;
                }
            }
        }
    }
    return n;
}

bool Universe::m_apply(bool state, int n) const {
    bool result = false;
    if (state == true) {
        if (n >=2 && n <= 3)
            result = true;
    } else {
        if (n == 3)
            result = true;
    }

    //printf("%d %d %d\n", state, n, result);
    return result;
}
