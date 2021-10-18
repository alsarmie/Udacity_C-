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

void PrintBoard(vector<vector<int>> board) {

  for (auto row : board) {
    for (auto col : row)
      cout << col;
    cout << endl;
  }
}

vector<int> ParseLine(string line) {
  istringstream stream(line);
  vector<int> row{};
  char c;
  int n;
  while (stream >> n >> c && c == ',')
    row.push_back(n);
  return row;
}

vector<vector<int>> ReadBoardFile(string path) {
  ifstream board(path);
  if (board) {
    string line;
    while (getline(board, line))
      cout << line << endl;
  }
}

int main() {

  //vector<vector<int>> board = {{0, 1, 0, 0, 0, 0},
                               {0, 1, 0, 0, 0, 0},
                               {0, 1, 0, 0, 0, 0},
                               {0, 1, 0, 0, 0, 0},
                               {0, 0, 0, 0, 1, 0}};
  auto board = ReadBoardFile("1.board");
  PrintBoard(board);
}