#include "Queen.hpp"

Queen::Queen(Position * position, PieceColor color) : Piece(position, color){
    this->canMoveDiagonal = true;
    this->canMoveHorizontal = true;
    this->canMoveVertical = true;
}

vector<Position*> Queen::possibleMoves(){
    return vector<Position*>();
}

char Queen::getSymbol(){
    return  'v';
}

int Queen::getPoint(){
    return 9;
}