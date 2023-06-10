#include <iostream>
#include <vector>
#include <queue>
#include <list>
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

void showq(queue<pair<int, int>> gq)
{
    queue<pair<int, int>> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front().first << "  " << g.front().second;
        g.pop();
    }
    cout << '\n';
}


//BFS
void sink_island_BFS(vector<vector<int>> &grid, const int &r, const int &c, queue<pair<int, int>> myQueue) {

    myQueue.push({r, c});
    cout << "push Queue: " << r << "  " << c << endl;

    while(!myQueue.empty()) {
        int x = myQueue.front().first;
        int y = myQueue.front().second;
        cout << "front " << x << " " << y << endl;
        myQueue.pop();

        if(((x >= 0) && (x < grid.size()) && ((y >= 0) && (y < grid[0].size())) && (grid[x][y] == 1))) {
            cout << "neighbor: " << x << " " << y << endl;
            grid[x][y] = 0;//mark
            //Add neighbors
            myQueue.push({x, y - 1});//left
            myQueue.push({x, y + 1});//right
            myQueue.push({x - 1, y});//up
            myQueue.push({x + 1, y});//down

            showq(myQueue);
        }


    }
}

int numberOfIsland(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    queue<pair<int, int>> myQueue;

    //loop all
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1) {
                //mark land visited
                cout << "numberOfIsland " << i << " " << j << endl;
                sink_island_BFS(grid, i, j, myQueue);
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
    grid[0][3] = 1;


    showMatrix(grid);

    cout << numberOfIsland(grid) << endl;

    return 0;
}
