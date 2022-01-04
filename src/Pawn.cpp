#include "Pawn.hpp"

Pawn::Pawn(Position* position, PieceColor color) : Piece(position, color) {
  this->canMoveDiagonal = false;
  this->canMoveHorizontal = false;
  this->canMoveVertical = false;
}

vector<Position*> Pawn::possibleMoves() { return vector<Position*>(); }

char Pawn::getSymbol() { return 'p'; }

int Pawn::getPoint(){
    return 1;
}