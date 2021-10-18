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

enum class State {kEmpty,kObstacle};



void PrintBoard(vector<string board){

    for(auto row:board){
        for(auto col:row)
            cout<<col;
        cout<<endl;
    }
}

int main(){

    vector<vector<int>> board = {{0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 1, 0}};


}