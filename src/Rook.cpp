#include "Rook.hpp"

Rook::Rook(Position * position, PieceColor color) : Piece(position, color){
    this->canMoveDiagonal = false;
    this->canMoveHorizontal = true;
    this->canMoveVertical = true;
}

vector<Position*> Rook::possibleMoves(){
    return vector<Position*>();
}

char Rook::getSymbol(){
    return  'k';
}

int Rook::getPoint(){
    return 5;
}