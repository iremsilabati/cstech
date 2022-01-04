#ifndef KING_HPP
#define KING_HPP 1

#include "Piece.hpp"

class King : public Piece {
    public:
    King(Position * position, PieceColor color);
    vector<Position*> possibleMoves();
    virtual char getSymbol();
    virtual int getPoint();
};

#endif