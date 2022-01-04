#ifndef BOARD_HPP
#define BOARD_HPP 1
#include <set>
#include "Piece.hpp"

class Board {
    private:
    vector<Position*> movesWithDir(Piece * piece, int verDir, int horDir);
    Piece * pieces[8][8];
    public:
    Board();
    void add(Piece * piece);
    Piece * get(Position * p);
    vector<Position*> moves(Piece * piece);
    void calculate();
};

#endif