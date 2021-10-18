#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::sort;
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

int Heuristic(int x1, int y1, int x2, int y2) {
  // Manhattan distance
  return abs(x2 - x1) + abs(y2 - y1);
}

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &open,
               vector<vector<State>> board) {
  vector<int> node{x, y, g, h};
  open.push_back(node);
  board[x][y] = State::kClosed;
}

bool Compare(vector<int> a, vector<int> b) {
  return (a[2] + a[3]) > (b[2] + b[3]);
}

void CellSort(vector<vector<int>> *v) {}
vector<vector<State>> Search(vector<vector<State>> board, int start[2],
                             int goal[2]) {

  // Initialize node list
  vector<vector<int>> openList{};
  vector<vector<State>> path{};
  // First Node
  int x = start[0];
  int y = start[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0], goal[1]);
  AddToOpen(x, y, g, h, openList, board);
  while (!openList.empty()) {
    // Sort the nodes

    // Pop the lowest f value node

    // Check neighbors, if valid, add them to the open list
  }

  return path;
}

int main() {
  auto board = ReadBoard("1.board");
  int start[2]{0, 0};
  int goal[2]{4, 5};
  auto solution = Search(board, start, goal);
  PrintBoard(board);
};
