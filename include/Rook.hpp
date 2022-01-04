#ifndef ROOK_HPP
#define ROOK_HPP 1
#include "Piece.hpp"

class Rook : public Piece {
    public:
    Rook(Position * position, PieceColor color);
    vector<Position*> possibleMoves();
    virtual char getSymbol();
    virtual int getPoint();
};

#endif