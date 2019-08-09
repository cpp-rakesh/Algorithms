#ifndef ALGORITHMS_GAMES_GAME_OF_LIFE_CELL_H_
#define ALGORITHMS_GAMES_GAME_OF_LIFE_CELL_H_

class Cell {
public:
    Cell();
    ~Cell();

    void state(bool s);
    void neighbours(int n);

    bool state() const;
    int neighbours() const;

private:
    unsigned char m_state;
};

#endif // ALGORITHMS_GAMES_GAME_OF_LIFE_CELL_H_
