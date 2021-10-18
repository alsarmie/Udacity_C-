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
bool Compare(vector<int> a, vector<int> b) {
  return (a[2] + a[3]) > (b[2] + b[3]);
}
void CellSort(vector<vector<int>> *v) { sort(v->begin(), v->end(), Compare); }
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist,
               vector<vector<State>> &grid) {
  vector<int> node{x, y, g, h};
  openlist.push_back(node);
  grid[x][y] = State::kClosed;
}
int Heuristic(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}

bool CheckValidCell(int x, int y,vector<vector<State>> &grid){
  bool sol ((x >= 0 && y >= 0) && (x < grid.size() && y < grid[0].size()) && grid[x][y] == State::kEmpty);
}
vector<vector<State>> Search(vector<vector<State>> grid, int start[2],
                             int goal[2]) {
  vector<vector<State>> path{};
  vector<vector<int>> open{};
  // Initialize open list for the first node
  int x = start[0];
  int y = start[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0], goal[1]);
  AddToOpen(x, y, g, h, open, grid);

  // TODO: while open vector is non empty {
  while (!open.empty()) {

    // TODO: Sort the open list using `CellSort`, and get the current node.
    CellSort(&open);
    vector<int> currentNode = open.back();
    open.pop_back();

    // TODO: Get the x and y values from the current node,
    // and set grid[x][y] to kPath.
    grid[currentNode[0]][currentNode[1]] = State::kPath;
    // TODO: Check if you've reached the goal. If so, return grid.
    if (currentNode[0] == goal[0] && currentNode[1] == goal[1])
      return grid;
    // If we're not done, expand search to current node's neighbors. This step
    // will be completed in a later quiz. ExpandNeighbors

  } // TODO: End while loop

  cout << "No path found!" << endl;
  return path;
}
void PrintVector(vector<int> v) {
  cout << "{ ";
  for (auto item : v) {
    cout << item << " ";
  }
  cout << "}"
       << "\n";
}

void PrintVectorOfVectors(vector<vector<int>> v) {
  for (auto row : v) {
    cout << "{ ";
    for (auto col : row) {
      cout << col << " ";
    }
    cout << "}"
         << "\n";
  }
}

void PrintVectorOfVectors(vector<vector<State>> v) {
  for (auto row : v) {
    cout << "{ ";
    for (auto col : row) {
      cout << CellString(col) << " ";
    }
    cout << "}"
         << "\n";
  }
}

void TestHeuristic() {
  cout << "----------------------------------------------------------"
       << "\n";
  cout << "Heuristic Function Test: ";
  if (Heuristic(1, 2, 3, 4) != 4) {
    cout << "failed"
         << "\n";
    cout << "\n"
         << "Heuristic(1, 2, 3, 4) = " << Heuristic(1, 2, 3, 4) << "\n";
    cout << "Correct result: 4"
         << "\n";
    cout << "\n";
  } else if (Heuristic(2, -1, 4, -7) != 8) {
    cout << "TestHeuristic Failed"
         << "\n";
    cout << "\n"
         << "Heuristic(2, -1, 4, -7) = " << Heuristic(2, -1, 4, -7) << "\n";
    cout << "Correct result: 8"
         << "\n";
    cout << "\n";
  } else {
    cout << "passed"
         << "\n";
  }
  return;
}

void TestAddToOpen() {
  cout << "----------------------------------------------------------"
       << "\n";
  cout << "AddToOpen Function Test: ";
  int x = 3;
  int y = 0;
  int g = 5;
  int h = 7;
  vector<vector<int>> open{{0, 0, 2, 9}, {1, 0, 2, 2}, {2, 0, 2, 4}};
  vector<vector<int>> solution_open = open;
  solution_open.push_back(vector<int>{3, 0, 5, 7});
  vector<vector<State>> grid{{State::kClosed, State::kObstacle, State::kEmpty,
                              State::kEmpty, State::kEmpty, State::kEmpty},
                             {State::kClosed, State::kObstacle, State::kEmpty,
                              State::kEmpty, State::kEmpty, State::kEmpty},
                             {State::kClosed, State::kObstacle, State::kEmpty,
                              State::kEmpty, State::kEmpty, State::kEmpty},
                             {State::kEmpty, State::kObstacle, State::kEmpty,
                              State::kEmpty, State::kEmpty, State::kEmpty},
                             {State::kEmpty, State::kEmpty, State::kEmpty,
                              State::kEmpty, State::kObstacle, State::kEmpty}};
  vector<vector<State>> solution_grid = grid;
  solution_grid[3][0] = State::kClosed;
  AddToOpen(x, y, g, h, open, grid);
  if (open != solution_open) {
    cout << "failed"
         << "\n";
    cout << "\n";
    cout << "Your open list is: "
         << "\n";
    PrintVectorOfVectors(open);
    cout << "Solution open list is: "
         << "\n";
    PrintVectorOfVectors(solution_open);
    cout << "\n";
  } else if (grid != solution_grid) {
    cout << "failed"
         << "\n";
    cout << "\n";
    cout << "Your grid is: "
         << "\n";
    PrintVectorOfVectors(grid);
    cout << "\n";
    cout << "Solution grid is: "
         << "\n";
    PrintVectorOfVectors(solution_grid);
    cout << "\n";
  } else {
    cout << "passed"
         << "\n";
  }
  return;
}

void TestCompare() {
  cout << "----------------------------------------------------------"
       << "\n";
  cout << "Compare Function Test: ";
  vector<int> test_1{1, 2, 5, 6};
  vector<int> test_2{1, 3, 5, 7};
  vector<int> test_3{1, 2, 5, 8};
  vector<int> test_4{1, 3, 5, 7};
  if (Compare(test_1, test_2)) {
    cout << "failed"
         << "\n";
    cout << "\n"
         << "a = ";
    PrintVector(test_1);
    cout << "b = ";
    PrintVector(test_2);
    cout << "Compare(a, b): " << Compare(test_1, test_2) << "\n";
    cout << "Correct answer: 0"
         << "\n";
    cout << "\n";
  } else if (!Compare(test_3, test_4)) {
    cout << "failed"
         << "\n";
    cout << "\n"
         << "a = ";
    PrintVector(test_3);
    cout << "b = ";
    PrintVector(test_4);
    cout << "Compare(a, b): " << Compare(test_3, test_4) << "\n";
    cout << "Correct answer: 1"
         << "\n";
    cout << "\n";
  } else {
    cout << "passed"
         << "\n";
  }
  return;
}

void TestSearch() {
  cout << "----------------------------------------------------------"
       << "\n";
  cout << "Search Function Test (Partial): ";
  int goal[2]{4, 5};
  auto board = ReadBoardFile("1.board");

  std::cout.setstate(std::ios_base::failbit); // Disable cout
  auto output = Search(board, goal, goal);
  std::cout.clear(); // Enable cout

  vector<vector<State>> solution{
      {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty,
       State::kEmpty, State::kEmpty},
      {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty,
       State::kEmpty, State::kEmpty},
      {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty,
       State::kEmpty, State::kEmpty},
      {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty,
       State::kEmpty, State::kEmpty},
      {State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty,
       State::kObstacle, State::kPath}};

  if (output != solution) {
    cout << "failed"
         << "\n";
    cout << "Search(board, {4,5}, {4,5})"
         << "\n";
    cout << "Solution board: "
         << "\n";
    PrintVectorOfVectors(solution);
    cout << "Your board: "
         << "\n";
    PrintVectorOfVectors(output);
    cout << "\n";
  } else {
    cout << "passed"
         << "\n";
  }
  return;
}

void TestCheckValidCell() {
  cout << "----------------------------------------------------------"
       << "\n";
  cout << "CheckValidCell Function Test: ";
  vector<vector<State>> grid{{State::kClosed, State::kObstacle, State::kEmpty,
                              State::kEmpty, State::kEmpty, State::kEmpty},
                             {State::kClosed, State::kObstacle, State::kEmpty,
                              State::kEmpty, State::kEmpty, State::kEmpty},
                             {State::kClosed, State::kObstacle, State::kEmpty,
                              State::kEmpty, State::kEmpty, State::kEmpty},
                             {State::kClosed, State::kObstacle, State::kEmpty,
                              State::kEmpty, State::kEmpty, State::kEmpty},
                             {State::kClosed, State::kClosed, State::kEmpty,
                              State::kEmpty, State::kObstacle, State::kEmpty}};

  if (CheckValidCell(0, 0, grid)) {
    cout << "failed"
         << "\n";
    cout << "\n"
         << "Test grid is: "
         << "\n";
    PrintVectorOfVectors(grid);
    cout << "Cell checked: (0, 0)"
         << "\n";
    cout << "\n";
  } else if (!CheckValidCell(4, 2, grid)) {
    cout << "failed"
         << "\n";
    cout << "\n"
         << "Test grid is: "
         << "\n";
    PrintVectorOfVectors(grid);
    cout << "Cell checked: (4, 2)"
         << "\n";
    cout << "\n";
  } else {
    cout << "passed"
         << "\n";
  }
  cout << "----------------------------------------------------------"
       << "\n";
}









int main() {

  // vector<vector<int>> board = {{0, 1, 0, 0, 0, 0},
  //                             {0, 1, 0, 0, 0, 0},
  //                             {0, 1, 0, 0, 0, 0},
  //                             {0, 1, 0, 0, 0, 0},
  //                             {0, 0, 0, 0, 1, 0}};
  auto board = ReadBoardFile("1.board");
  // PrintBoard(board);
  int start[2]{0, 0};
  int goal[2]{4, 5};
  auto solution = Search(board, start, goal);
  PrintBoard(solution);
  TestHeuristic();
  TestAddToOpen();
  TestCompare();
  TestSearch();
  TestCheckValidCell();

}