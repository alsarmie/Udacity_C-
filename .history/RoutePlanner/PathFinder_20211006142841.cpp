#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::istringstream;

enum class State {kEmpty,kObstacle};



void PrintBoard(vector<vector<int>> board){

    for(auto row:board){
        for(auto col:row)
            cout<<col;
        cout<<endl;
    }
}

vector<int> ParseLine(string line){
    istringstream stream(line);
    vector<int> board{};
    char c;
    int n;
    while(stream>>n>>c && c == ','){

    }
}
void ReadBoardFile(string path){
    ifstream board(path);
    if(board){
        string line;
        while(getline(board,line))
            cout<<line<<endl;
    }

}

int main(){

    vector<vector<int>> board = {{0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 1, 0}};
    ReadBoardFile("1.board");
    PrintBoard(board);

}