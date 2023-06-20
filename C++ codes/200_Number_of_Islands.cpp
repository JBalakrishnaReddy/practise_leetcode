/*Given an m x n 2D binary grid grid which represents a map of '1's (land) and
'0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands 
horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <list>

using namespace std;

class Solution1 {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<bool>>vis(rows, vector<bool>(columns, false));    // Its size should be equal to that of the grid;
        queue<pair<int,int>> q;

        for(int i=0; i< rows; i++){
            for(int j=0; j<columns; j++){
                if(vis[i][j] == false && grid[i][j] == '1'){
                    islands++;  // If we entered this means there is an island so increment it.
                    // while there are non zero neighbours continue it.
                    int row, column;
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int, int> e = q.front();
                        q.pop();
                        row = e.first;
                        column = e.second;
                        if(vis[row][column] == false && grid[row][column] == '1'){
                        // if(grid[row][column] == '1'){
                            vis[row][column] = true;
                            this->addNeighbours(vis, q, row, column, rows, columns);
                            // if(row-1>=0)    q.push({row-1, column});
                            // if(row+1 < rows)    q.push({row+1, column});
                            // if(column-1>=0)    q.push({row, column-1});
                            // if(column+1 < columns)    q.push({row, column+1});
                        }
                    }
                }
            }
        }
        return islands;
    }

    void addNeighbours(vector<vector<bool>> &vis, queue<pair<int, int>> &q, int row, int column, int rows, int columns){
        if(row-1>=0 && vis[row-1][column] == false)    q.push({row-1, column});
        if(row+1 < rows && vis[row+1][column] == false)    q.push({row+1, column});
        if(column-1>=0 && vis[row][column-1] == false)    q.push({row, column-1});
        if(column+1 < columns && vis[row][column+1] == false)    q.push({row, column+1});

        // if(row-1>=0)    q.push({row-1, column});
        // if(row+1 < rows)    q.push({row+1, column});
        // if(column-1>=0)    q.push({row, column-1});
        // if(column+1 < columns)    q.push({row, column+1});
    }

};

class Solution {
    // Credits to https://leetcode.com/problems/number-of-islands/solutions/3028461/c-easy-solution-beats-91-dfs-approach/
public:
    bool isValid(int i,int j,int n,int m,vector<vector<char>>& grid){
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]=='1')
            return true;
        return false;
    }
    void dfs(int i,int j,int n,int m,vector<vector<char>>& grid){
        grid[i][j]='0';
        if(isValid(i-1,j,n,m,grid))
            dfs(i-1,j,n,m,grid);
        if(isValid(i+1,j,n,m,grid))
            dfs(i+1,j,n,m,grid);
        if(isValid(i,j-1,n,m,grid))
            dfs(i,j-1,n,m,grid);
        if(isValid(i,j+1,n,m,grid))
            dfs(i,j+1,n,m,grid);

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        return ans;
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