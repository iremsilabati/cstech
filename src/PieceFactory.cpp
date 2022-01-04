#include "PieceFactory.hpp"

PieceFactory::PieceFactory(){}
PieceFactory::~PieceFactory(){}

Piece * PieceFactory::getPiece(char symbol, char colorCh){
    PieceColor color = colorCh == 's' ? PieceColor::BLACK : colorCh == 'b' ? PieceColor::WHITE : PieceColor::EMPTY;
    Position * p = Position::of(0,0);
    switch(symbol){
        case 'k':
        return new Rook(p, color);
        case 'a':
        return new Knight(p, color);
        case 'f':
        return new Bishop(p, color);
        case 's':
        return new King(p, color);
        case 'v':
        return new Queen(p, color);
        case 'p':
        return new Pawn(p, color);
    }
    return new Piece(p, color);
}