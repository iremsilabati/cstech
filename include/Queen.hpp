#ifndef QUEEN_HPP
#define QUEEN_HPP 1

#include "Piece.hpp"

class Queen : public Piece {
    public:
    Queen(Position * position, PieceColor color);
    vector<Position*> possibleMoves();
    virtual char getSymbol();
    virtual int getPoint();
};

#endif