#ifndef APPLICATION_HPP
#define APPLICATION_HPP 1
#include <fstream>
#include <sstream>
#include "Board.hpp"
#include "PieceFactory.hpp"

class Application {
 private:
	Board * board;
  Application();
  ~Application();

 public:
  int run(int argc, char* argv[]);
	bool initializeBoard(string filename);
	void analysis();

  Application(const Application&) = delete;
  Application(Application&&) = delete;
  Application& operator=(const Application&) = delete;
  Application& operator=(Application&&) = delete;

  static Application& instance() {
    static Application instance;
    return instance;
  }
};

#endif