#include "Application.hpp"

int main(int argc, char *argv[]) {
  return Application::instance().run(argc, argv);
}