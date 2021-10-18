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

vector<State> ParseLine(string line) {
  istringstream stream(line);
  vector<State> row{};
  char c;
  int n;
  while (stream >> n >> c && c == ',')
    (!n) ? row.push_back(State::kEmpty) : row.push_back(State::kObstacle);
  return row;
}

vector<vector<State>> ReadBoardFile(string path) {
  ifstream file(path);
  vector<vector<State>> board{};
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

/*******************************************************
 A* functions
*******************************************************/
vector<vector<State>> Search(vector<vector<State>> grid, vector<int> start,
                             vector<int> goal) {
  vector<vector<State>> path{};
  cout << "No path found!" << endl;
  return path;
}

int main() {

  // vector<vector<int>> board = {{0, 1, 0, 0, 0, 0},
  //                             {0, 1, 0, 0, 0, 0},
  //                             {0, 1, 0, 0, 0, 0},
  //                             {0, 1, 0, 0, 0, 0},
  //                             {0, 0, 0, 0, 1, 0}};
  auto board = ReadBoardFile("1.board");
  // PrintBoard(board);
  vector<int> start{0, 0};
  vector<int> goal{4, 5};
  auto solution = Search(board,start,goal);
  PrintBoard(board);
}