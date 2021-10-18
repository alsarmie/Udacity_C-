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

enum class State {OK,BAD };

vector<vector<State>> ParseLine(string line)

vector<vector<State>> ReadBoard(string file){
    ifstream boardFile(file);
    vector<vector<State>> board;
    string line{};
    if (boardFile)
    {
        while(getline(boardFile,line))
            board.push_back(ParseLine(line));
    }
    return board;
}

void testing(int option) {
  
  switch (option)
  {
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