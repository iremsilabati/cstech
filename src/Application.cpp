#include "Application.hpp"

Application::Application() {
	this->board = new Board();
}
Application::~Application() {}

vector<string> split(const string& s, char delim) {
  vector<string> result;
  stringstream ss(s);
  string item;

  while (getline(ss, item, delim)) {
    result.push_back(item);
  }

  return result;
}

bool Application::initializeBoard(string filename) {
  std::ifstream file(filename);
  if (file.is_open()) {
    std::string line;
		int ver = 7;
    while (std::getline(file, line)) {
			vector<string> row = split(line, ' ');
			int hor = 0;
			for(string e: row){
				Piece * piece = PieceFactory::instance().getPiece(e.at(0), e.at(1));
				piece->setPosition(Position::of(ver, hor));
				this->board->add(piece);
				hor++;
			}
			ver--;
    }
    file.close();
    return true;
  } else {
    cout << "File (" << filename << ") not found" << endl;
    return false;
  }
}

int Application::run(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Usage: ./app <file_name>" << endl;
    return 1;
  }
  if (!this->initializeBoard(argv[1])) {
    return 1;
  }
	this->analysis();
  return 0;
}

void Application::analysis() {
	this->board->calculate();
}