#ifndef ALGORITHMS_GAMES_GAME_OF_LIFE_UNIVERSE_H_
#define ALGORITHMS_GAMES_GAME_OF_LIFE_UNIVERSE_H_

#include "cell.h"
#include <vector>

using V = std::vector<std::vector<Cell>>;

class Universe {
public:
    Universe();
    Universe(int n);
    ~Universe();

    void generate();
    void print() const;

private:
    bool m_random() const;
    int m_neighbours(int r, int c) const;
    bool m_apply(bool state, int n) const;

    V m_universe;
};

#endif // ALGORITHMS_GAMES_GAME_OF_LIFE_UNIVERSE_H_
