#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

//total ways = bottom_ways + right_ways
//stoping condition: out boundary || meet obstacle || meet destination

int robotWays(vector<vector<int>> &grid, const int &i, const int &j) {
    map<pair<int, int>, int> mem;
    //get bound of matrix
    int rows = grid.size() - 1;//access grid[i][j] from 0
    int cols = grid[0].size() - 1;

    //cong thuc truy hoi + stoping condition
    if((i > cols) || (j > rows)) return 0;
    if(grid[i][j] == 1) return 0;
    if((i == cols) && (j == rows) && (grid[i][j] == 0)) return 1;


//    cout << " i = " << i << " j = " << j << endl;

    if(mem.find({i, j}) == mem.end()) {
        mem[{i, j}] = (robotWays(grid, i+1, j) + robotWays(grid, i, j+1));
    }

//    cout << "mem[{i, j}] = " << mem[{i, j}];

    return mem[{i, j}];

}

void showMatrix(vector<vector<int>> &grid) {
    for(auto row_ele : grid) {
        for(auto col_ele : row_ele) {
            cout << col_ele << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rows = 3;
    int  cols = 3;
    vector<vector<int>> grid(rows, vector<int>(cols));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            grid[i][j] = 0;
        }
    }
//    grid[1][1] = 1;
    grid[1][2] = 1;
    grid[2][1] = 1;


    showMatrix(grid);

    cout << robotWays(grid, 0, 0) << endl;

    return 0;
}
