#ifndef PIECE_HPP
#define PIECE_HPP 1
#include "Position.hpp"

enum PieceColor { EMPTY, WHITE, BLACK };
enum MoveDirection { HORIZONTAL, VERTICAL, DIAGONAL };

class Piece {
 protected:
  Position* position;
  PieceColor color;
  bool canMoveHorizontal;
  bool canMoveVertical;
  bool canMoveDiagonal;

 public:
  Piece(Position* position, PieceColor color);
  Position* getPosition();
  virtual ~Piece();
  void setPosition(Position* position);
  PieceColor getPieceColor();
  void setPieceColor(PieceColor color);
  bool canMove(MoveDirection direction);
  virtual vector<Position*> possibleMoves();
  virtual char getSymbol();
  virtual int getPoint();
};

#endif