#include "Knight.hpp"

Knight::Knight(Position* position, PieceColor color) : Piece(position, color) {
  this->canMoveDiagonal = false;
  this->canMoveHorizontal = false;
  this->canMoveVertical = false;
}

vector<Position*> Knight::possibleMoves() {
  vector<Position*> result;
  int ver = this->position->getVertical();
  int hor = this->position->getHorizontal();
  result.push_back(Position::of(ver + 1, hor + 2));
  result.push_back(Position::of(ver - 1, hor + 2));
  result.push_back(Position::of(ver + 1, hor - 2));
  result.push_back(Position::of(ver - 1, hor - 2));

  result.push_back(Position::of(ver + 2, hor + 1));
  result.push_back(Position::of(ver - 2, hor + 1));
  result.push_back(Position::of(ver + 2, hor - 1));
  result.push_back(Position::of(ver - 2, hor - 1));

	return Position::valids(result);
}

char Knight::getSymbol(){
    return  'a';
}

int Knight::getPoint(){
    return 3;
}