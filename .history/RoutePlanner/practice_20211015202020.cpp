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

string CellString(State cell) {
  return (cell == State::kEmpty) ? "0 " : "⛰️ ";
}
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
void PrintBoard(vector<vector<State>> board) {
  for (auto row : board) {
    for (auto col : row)
      cout << CellString(col);
    cout << endl;
  }
}
/*************************************************************************
****************************A* Functions**********************************
**************************************************************************/









int main() {
  auto board = ReadBoard("1.board");
  
  PrintBoard(board);
};
