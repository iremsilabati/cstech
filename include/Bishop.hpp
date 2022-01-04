#ifndef BISHOP_HPP
#define BISHOP_HPP 1

#include "Piece.hpp"

class Bishop : public Piece {
    public:
    Bishop(Position * position, PieceColor color);
    vector<Position*> possibleMoves();
    virtual char getSymbol();
    virtual int getPoint();
};

#endif