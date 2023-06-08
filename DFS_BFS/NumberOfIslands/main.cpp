#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void showMatrix(vector<vector<int>> &grid) {
    for(auto row_ele : grid) {
        for(auto col_ele : row_ele) {
            cout << col_ele << " ";
        }
        cout << endl;
    }
}

////DFS
//void sink_island_DFS(vector<vector<int>> &grid, const int &r, const int &c) {
//    if(((r >= 0) && (r < grid.size())) && ((c >= 0) && (c < grid[0].size())) && (grid[r][c] == 1)) {//check == 1 for recursion
//        cout << r << " " << c << endl;
//        grid[r][c] = 0;//mark visited
//        //Check neighbors
//        sink_island_DFS(grid, r, c - 1);//left
//        sink_island_DFS(grid, r, c + 1);//right
//        sink_island_DFS(grid, r - 1, c);//up
//        sink_island_DFS(grid, r + 1, c);//down
//    }

//}


//BFS
void sink_island_BFS(vector<vector<int>> &grid, const int &r, const int &c) {
    queue<pair<int, int>> myQueue;
    myQueue.push({r, c});

    while(!myQueue.empty()) {
        myQueue.pop();
        if(((r > 0) && (r < grid.size()) && ((c > 0) && (c < grid[0].size())) && (grid[r][c] == 1))) {
            grid[r][c] = 0;//mark
            //Add neighbors
            myQueue.push({r, c - 1});//left
            myQueue.push({r, c + 1});//right
            myQueue.push({r - 1, c});//up
            myQueue.push({r + 1, c});//down
        }
    }
}

int numberOfIsland(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    //loop all
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1) {
                //mark land visited
                cout << "numberOfIsland " << i << " " << j << endl;
                sink_island_BFS(grid, i, j);
                ++count;
            }
        }
    }
    return count;
}


int main()
{
    int rows = 3;
    int  cols = 4;
    vector<vector<int>> grid(rows, vector<int>(cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }
    grid[0][0] = 1;
    grid[0][1] = 1;
    grid[1][0] = 1;
    grid[1][1] = 1;
    grid[2][3] = 1;

    showMatrix(grid);

    cout << numberOfIsland(grid) << endl;

    return 0;
}
