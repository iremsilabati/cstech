#include "Position.hpp"

map<string, Position*> Position::cache;

int Position::getHorizontal() { return this->horizontal; }

int Position::getVertical() { return this->vertical; }

string Position::toString() {
  return convertString(this->vertical, this->horizontal);
}

Position::Position(string positionStr) {
  char hor = positionStr.at(0);
  char ver = positionStr.at(1);
  this->init((int)(ver - '1'), (int)(hor - 'a'));
}

Position::Position(int vertical, int horizontal) {
  this->init(vertical, horizontal);
}

void Position::init(int vertical, int horizontal) {
  this->vertical = vertical;
  this->horizontal = horizontal;
}

bool Position::isValid() {
  return this->vertical >= 0 && this->vertical < 8 && this->horizontal >= 0 &&
         this->horizontal < 8;
}
