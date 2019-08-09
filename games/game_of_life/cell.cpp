#include "cell.h"

Cell::Cell() : m_state(0) {}
Cell::~Cell() {}

void Cell::state(bool s) {
    unsigned char t = s;
    t <<= 7;
    m_state <<= 1;
    m_state >>= 1;
    m_state |= t;
}

void Cell::neighbours(int n) {
    const int state = m_state & 128;
    m_state = 0;
    m_state |= n;
    m_state |= state;
}

bool Cell::state() const {
    return m_state >> 7;
}

int Cell::neighbours() const {
    return m_state & 15;
}
