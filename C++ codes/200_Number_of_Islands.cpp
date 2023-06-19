/*Given an m x n 2D binary grid grid which represents a map of '1's (land) and
'0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands 
horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>


using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<bool>>vis(rows, vector<bool>(columns, false));    // Its size should be equal to that of the grid;
        queue<pair<int,int>> q;

        for(int i=0; i< rows; i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j] == '1' && vis[i][j] == false){
                    islands++;  // If we entered this means there is an island so increment it.
                    this->addNeighbours(q, i, j, rows, columns);
                    // cout << i << j << endl;
                    this->bfs(grid, vis, q, i, j, rows, columns);
                }
            }
        }
        return islands;
    }

    void addNeighbours(queue<pair<int, int>> &q, int row, int column, int rows, int columns){
        if(row-1>=0)    q.push({row-1, column});
        if(row+1 < rows)    q.push({row+1, column});
        if(column-1>=0)    q.push({row, column-1});
        if(column+1 < columns)    q.push({row, column+1});
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, queue<pair<int, int>> &q, int row, int column, int rows, int columns){
        vis[row][column] = true;
        // while there are non zero neighbours continue it.
        while(!q.empty()){
            pair<int, int> e = q.front();
            q.pop();
            row = e.first;
            column = e.second;
            if(grid[row][column] == '1' && vis[row][column] == false){
                vis[row][column] = true;
                this->addNeighbours(q, row, column, rows, columns);
                // this->bfs(grid, vis, q, row, column, rows, columns);
            }
        }
    }
};

int main(int argc, char* argv[]){
    vector<vector<char>> grid1{
                            {'1','1','1','1','0'},
                            {'1','1','0','1','0'},
                            {'1','1','0','1','0'},
                            {'0','0','0','0','0'}
                            };                  // output is 1
    vector<vector<char>> grid2{
                            {'1','1','0','0','0'},
                            {'1','1','0','0','0'},
                            {'0','0','1','0','0'},
                            {'0','0','0','1','1'}};       // output is 3


    Solution sol;
    cout << sol.numIslands(grid1) << endl;
    cout << sol.numIslands(grid2) << endl;
    return 0;
}