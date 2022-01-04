#ifndef PAWN_HPP
#define PAWN_HPP 1

#include "Piece.hpp"

class Pawn : public Piece {
    public:
    Pawn(Position * position, PieceColor color);
    vector<Position*> possibleMoves();
    virtual char getSymbol();
    virtual int getPoint();
};

#endif