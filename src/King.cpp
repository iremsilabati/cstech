#include "King.hpp"

King::King(Position * position, PieceColor color) : Piece(position, color){
    this->canMoveDiagonal = false;
    this->canMoveHorizontal = false;
    this->canMoveVertical = false;
}

vector<Position*> King::possibleMoves(){
    return vector<Position*>();
}

char King::getSymbol(){
    return  's';
}

int King::getPoint(){
    return 100;
}