#include "Piece.hpp"

Piece::~Piece() {}

Piece::Piece(Position* position, PieceColor color) {
  this->setPosition(position);
  this->setPieceColor(color);
}

Position* Piece::getPosition() { return this->position; }

void Piece::setPosition(Position* position) { this->position = position; }

PieceColor Piece::getPieceColor() { return this->color; }

void Piece::setPieceColor(PieceColor color) { this->color = color; }

vector<Position*> Piece::possibleMoves() { return vector<Position*>(); }

bool Piece::canMove(MoveDirection direction) {
  return (direction == MoveDirection::VERTICAL && this->canMoveVertical) ||
         (direction == MoveDirection::HORIZONTAL && this->canMoveHorizontal) ||
         (direction == MoveDirection::DIAGONAL && this->canMoveDiagonal);
}

char Piece::getSymbol(){
    return  '-';
}

int Piece::getPoint(){
    return 0;
}