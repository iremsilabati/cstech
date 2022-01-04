#ifndef KNIGHT_HPP
#define KNIGHT_HPP 1

#include "Piece.hpp"

class Knight : public Piece {
    public:
    Knight(Position * position, PieceColor color);
    vector<Position*> possibleMoves();
    virtual char getSymbol();
    virtual int getPoint();
};

#endif