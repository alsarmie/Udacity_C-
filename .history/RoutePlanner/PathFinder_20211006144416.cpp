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

enum class State { kEmpty, kObstacle };

string CellString(State cell) {
  return (cell == State::kEmpty) ? "0 " : "⛰️ ";
}

vector<int> ParseLine(string line) {
  istringstream stream(line);
  vector<int> row{};
  char c;
  int n;
  while (stream >> n >> c && c == ',')
    (!n)?row.push_back();
  return row;
}

vector<vector<int>> ReadBoardFile(string path) {
  ifstream file(path);
  vector<vector<int>> board{};
  if (file) {
    string line;
    while (getline(file, line))
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

int main() {

  // vector<vector<int>> board = {{0, 1, 0, 0, 0, 0},
  //                             {0, 1, 0, 0, 0, 0},
  //                             {0, 1, 0, 0, 0, 0},
  //                             {0, 1, 0, 0, 0, 0},
  //                             {0, 0, 0, 0, 1, 0}};
  auto board = ReadBoardFile("1.board");
  PrintBoard(board);
}