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

void showq(queue<pair<int, int>> gq)
{
    queue<pair<int, int>> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front().first << "  " << g.front().second;
        g.pop();
    }
    cout << '\n';
}

//Find first island to convert it to 2
void convert_first_island(vector<vector<int>>& grid) {
    queue<pair<int, int>> mQueue;
    for(int y = 0; y < grid.size(); y++) {
        for(int x = 0; x < grid[y].size(); x++ ) {
            if(grid[y][x] == 1) {
                cout << endl;
                cout << "push " << "{" << y << "," << x << "}" << endl;

                mQueue.push({y, x});
                while(!mQueue.empty()) {
                    int r = mQueue.front().first;
                    int c = mQueue.front().second;
                    cout << "pop: {" << r << " " << c << "}"<< endl;
                    mQueue.pop();

                    if(((r >= 0) && (r < grid.size())) && ((c >= 0) && (c < grid[r].size())) && (grid[r][c] == 1)) {
                        //convert
                        cout << "convert " << "{" << r << "," << c << "} to 2" << endl;
                        grid[r][c] = 2;
                        //Add neighbors
                        mQueue.push({r, c - 1});
                        mQueue.push({r , c + 1});
                        mQueue.push({r - 1, c});
                        mQueue.push({r + 1, c});

                        showq(mQueue);
                    }
                }
                break;
            }
            break;
        }
    }
}


int main()
{
    int rows = 5;
    int cols = 5;
    vector<vector<int>> grid(rows, vector<int>(cols));

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }

    grid[0][0] = 1;
    grid[0][1] = 1;
    grid[1][2] = 1;
    grid[1][1] = 1;
    grid[2][2] = 1;

    for(int i = 0; i < rows; i++) {
        grid[i][4] = 1;
    }
    showMatrix(grid);

    cout << "after converting first island---------------" << endl << endl;
    convert_first_island(grid);

    showMatrix(grid);


    return 0;
}

//length of shortest brigde
//number of shortest bridges

