#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State { kEmpty, kObstacle, kClosed, kPath };





vector<State> ParseLine(string line) {
  /* Parses a line from a file
   */
  vector<State> row{};
  istringstream stream(line);
  int n{};
  char c{};

  while (stream >> n >> c && c == ',')
    (!n) ? row.push_back(State::kEmpty) : row.push_back(State::kObstacle);

  return row;
}

vector<vector<State>> ReadBoard(string file) {
  ifstream boardFile(file);
  vector<vector<State>> board;
  string line{};
  if (boardFile) {
    while (getline(boardFile, line))
      board.push_back(ParseLine(line));
  }
  return board;
}
void PrintBoard(vector<vector<State>> board){
    for( auto(row:board)


}
void testing(int option) {

  switch (option) {
  case 0:
    // Test to write out to terminal
    cout << "Hello world!" << endl;

    break;
  case 1:
    // Test to read a file

    break;
  case 2:
    // Test to read a line
    break;
  case 3:

    // Test to parse a line
    break;
  }
}

int main() { testing(0); }