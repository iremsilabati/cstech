#ifndef PIECE_FACTOY_HPP
#define PIECE_FACTOY_HPP 1
#include "Bishop.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"

class PieceFactory {
 private:
  PieceFactory();
  ~PieceFactory();

 public:
  PieceFactory(const PieceFactory&) = delete;
  PieceFactory(PieceFactory&&) = delete;
  PieceFactory& operator=(const PieceFactory&) = delete;
  PieceFactory& operator=(PieceFactory&&) = delete;
  
  static PieceFactory& instance() {
    static PieceFactory instance;
    return instance;
  }
  Piece* getPiece(char symbol, char color);
};

#endif