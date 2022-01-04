#include "Bishop.hpp"

Bishop::Bishop(Position * position, PieceColor color) : Piece(position, color){
    this->canMoveDiagonal = true;
    this->canMoveHorizontal = false;
    this->canMoveVertical = false;
}

vector<Position*> Bishop::possibleMoves(){
    return vector<Position*>();
}

char Bishop::getSymbol(){
    return  'f';
}

int Bishop::getPoint(){
    return 3;
}