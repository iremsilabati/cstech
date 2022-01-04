#ifndef POSITION_HPP
#define POSITION_HPP 1
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Position {
 private:
  static map<string, Position *> cache;
  Position(string positionStr);
  Position(int vertical, int horizontal);
  void init(int vertical, int horizontal);
  int vertical = 0;
  int horizontal = 0;

 public:
  int getVertical();
  int getHorizontal();
  string toString();
  bool isValid();
  static string convertString(int vertical, int horizontal) {
    return string() + ((char)(horizontal + 'a')) + ((char)(vertical + '1'));
  }
  static Position *of(string positionStr) {
    map<string, Position *>::iterator it = Position::cache.find(positionStr);
    if (Position::cache.end() == it) {
      Position *p = new Position(positionStr);
      Position::cache.insert(make_pair(positionStr, p));
      return p;
    } else {
      return it->second;
    }
  }
  static Position *of(int vertical, int horizontal) {
    return of(convertString(vertical, horizontal));
  }
  static vector<Position*> valids(vector<Position*> positions){
      vector<Position*> result;
      for(Position * p: positions){
          if(p->isValid()){
              result.push_back(p);
          }
      }
      return result;
  }
};

#endif