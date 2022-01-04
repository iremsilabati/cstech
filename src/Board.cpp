#include "Board.hpp"

Board::Board() {}

void Board::add(Piece* piece) {
  Position* p = piece->getPosition();
  this->pieces[p->getVertical()][p->getHorizontal()] = piece;
}

Piece* Board::get(Position* p) {
  return this->pieces[p->getVertical()][p->getHorizontal()];
}

vector<Position*> Board::movesWithDir(Piece* piece, int verDir, int horDir) {
  int ver = piece->getPosition()->getVertical();
  int hor = piece->getPosition()->getHorizontal();

  int v = ver + verDir;
  int h = hor + horDir;

  vector<Position*> result;

  while (Position::of(v, h)->isValid()) {
    Piece* other = this->get(Position::of(v, h));
    if (other->getPieceColor() == PieceColor::EMPTY) {
      result.push_back(Position::of(v, h));
    } else if (other->getPieceColor() == piece->getPieceColor()) {
      break;
    } else if (other->getPieceColor() != piece->getPieceColor()) {
      result.push_back(Position::of(v, h));
      break;
    }
    v += verDir;
    h += horDir;
  }

  return result;
}

vector<Position*> Board::moves(Piece* piece) {
  if (piece->getPieceColor() == PieceColor::EMPTY) {
    return vector<Position*>();
  }
  PieceColor color = piece->getPieceColor();
  PieceColor enemy =
      color == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE;

  Position* position = piece->getPosition();
  int ver = position->getVertical();
  int hor = position->getHorizontal();
  vector<Position*> additionalMoves = piece->possibleMoves();

  if (piece->getSymbol() == 'p') {
    int verDir = color == PieceColor::WHITE ? 1 : -1;
    Position* forward = Position::of(ver + verDir, hor);
    Position* left = Position::of(ver + verDir, hor - 1);
    Position* right = Position::of(ver + verDir, hor + 1);
    if (left->isValid() && this->get(left)->getPieceColor() == enemy) {
      additionalMoves.push_back(left);
    }
    if (right->isValid() && this->get(right)->getPieceColor() == enemy) {
      additionalMoves.push_back(right);
    }
    if (forward->isValid() &&
        this->get(forward)->getPieceColor() == PieceColor::EMPTY) {
      additionalMoves.push_back(forward);
    }
  }

  vector<Position*> filtered;

  for (Position* p : additionalMoves) {
    Piece* other = this->get(p);
    if (other->getPieceColor() != color) {
      filtered.push_back(p);
    }
  }

  if (piece->canMove(MoveDirection::HORIZONTAL)) {
    vector<Position*> left = this->movesWithDir(piece, 0, -1);
    vector<Position*> right = this->movesWithDir(piece, 0, 1);
    filtered.insert(filtered.end(), left.begin(), left.end());
    filtered.insert(filtered.end(), right.begin(), right.end());
  }

  if (piece->canMove(MoveDirection::VERTICAL)) {
    vector<Position*> up = this->movesWithDir(piece, -1, 0);
    vector<Position*> down = this->movesWithDir(piece, 1, 0);
    filtered.insert(filtered.end(), up.begin(), up.end());
    filtered.insert(filtered.end(), down.begin(), down.end());
  }

  if (piece->canMove(MoveDirection::DIAGONAL)) {
    vector<Position*> upleft = this->movesWithDir(piece, -1, -1);
    vector<Position*> upright = this->movesWithDir(piece, -1, 1);
    vector<Position*> downleft = this->movesWithDir(piece, 1, -1);
    vector<Position*> downright = this->movesWithDir(piece, 1, 1);
    filtered.insert(filtered.end(), upleft.begin(), upleft.end());
    filtered.insert(filtered.end(), upright.begin(), upright.end());
    filtered.insert(filtered.end(), downleft.begin(), downleft.end());
    filtered.insert(filtered.end(), downright.begin(), downright.end());
  }
  return filtered;
}

void Board::calculate() {
  set<Position*> whiteThreat;
  set<Position*> blackThreat;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      Piece* piece = this->pieces[i][j];
      vector<Position*> positions = this->moves(piece);

      for (Position* p : positions) {
        if (piece->getPieceColor() == PieceColor::WHITE) {
          blackThreat.insert(p);
        } else if (piece->getPieceColor() == PieceColor::BLACK) {
          whiteThreat.insert(p);
        }
      }
    }
  }

  double whiteScore = 0;
  double blackScore = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      Piece* piece = this->pieces[i][j];
      PieceColor color = piece->getPieceColor();
      double point = (double)piece->getPoint();
      if ((color == PieceColor::WHITE &&
           whiteThreat.find(piece->getPosition()) != whiteThreat.end()) ||
          (color == PieceColor::BLACK &&
           blackThreat.find(piece->getPosition()) != blackThreat.end())) {
        point = point / 2.0;
      }
      if (color == PieceColor::WHITE) {
        whiteScore += point;
      } else if (color == PieceColor::BLACK) {
        blackScore += point;
      }
    }
  }

  cout << "Siyah:" << blackScore << "\t"
       << "Beyaz:" << whiteScore << endl;
}