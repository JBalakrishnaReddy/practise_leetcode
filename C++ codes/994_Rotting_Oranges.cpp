#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>

#include "tr_essentials.cpp"

using namespace std;

void print_grid(vector<vector<int>> &grid, string msg=""){
    cout << msg << endl;
    for(auto i: grid){
        for(auto j:i) cout << j << ", ";
        cout << endl;
    }
    cout << endl;
}

class Solution_first{
    // This is the first working code and is bit inefficient
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        int m = grid.size();        // m => rows
        int n = grid[0].size();     // n => columns
        // vector<vector<bool>> visited (grid.size(), vector<int>(grid[0].size(), false));
        // We have a total of m*n number of elements, the elements are starting from 0 and ends at m*n-1
        vector<vector<bool>> visited;
        visited.resize(m);
        for(int i=0; i < visited.size(); i++)   visited[i].resize(n);
        vector<pair<int, int>> rottenOranges = findRottenOranges(grid);
        // print_vector(rottenOranges, "rotten oranges: ");
        pair<int, int> firstUnRottenOrange = findUnRottenOrange(grid);
        if(rottenOranges.empty() ){
            if(firstUnRottenOrange.first == -1) return 0;
            else return -1;
        }
        vector<pair<int, int>>neighbours, temp;
        for(auto e: rottenOranges){
            temp = getNeighbours(e, m, n);
            neighbours.insert(neighbours.end(), temp.begin(), temp.end());
            // print_vector(neighbours, "first time:");
        }
        // return 0;
        deque <pair<int,int>> dq(neighbours.begin(), neighbours.end());
        neighbours.clear();
        queue<pair<int,int>> q(dq);
        bool newOrangeRotten = false;
        while(! q.empty()){
            pair<int,int> i = q.front();
            q.pop();
            if(visited[i.first][i.second] == false){
                visited[i.first][i.second] = true;
                if(grid[i.first][i.second] == 1){
                    grid[i.first][i.second] = 2;
                    temp = getNeighbours(make_pair(i.first, i.second), m, n);
                    neighbours.insert(neighbours.end(), temp.begin(), temp.end());
                    // print_vector(neighbours, "new neighbours");
                    newOrangeRotten = true;
                }
            }
            if(q.empty()){
                if(! newOrangeRotten){
                    // this implies no new elements were discovered so we can stop searching
                    break;
                }
                count++;
                // cout << "count increased: " << count << endl;
                // print_grid(grid);
                for(auto e: neighbours){
                    if(!visited[e.first][e.second]) q.push(e);
                }
                
                newOrangeRotten = false;
            }
        }
        // cout << "time: " <<count << endl;
        pair<int,int> temp2 = findUnRottenOrange(grid);
        if( temp2.first == -1){
            // cout << "time: " << count << endl;
            return count;
        }
        // cout << "time: " << -1 << endl;
        return -1;
    }

    inline bool rottenDoesExist(pair<int,int> & rottenOrange){
        return rottenOrange.first >= 0? true:false;
    }
    inline bool UnrottenDoesExist(pair<int,int> & unrottenOrange){
        return unrottenOrange.first >= 0? true:false;
    }

    vector<pair<int, int>> findRottenOranges(vector<vector<int>>& grid){
        vector<pair<int, int>> vec;
        for(int i=0; i< grid.size(); i++){
            for (int j=0; j< grid[i].size(); j++){
                if(grid[i][j] == 2){
                    vec.push_back(make_pair(i,j));  // this is equal to sending an ordered set or (i,j);
                }
            }
        }
        return vec;
        // return make_pair(-1, -1);
    }

    pair<int, int> findUnRottenOrange(vector<vector<int>>& grid){
        for(int i=0; i< grid.size(); i++){
            for (int j=0; j< grid[i].size(); j++){
                if(grid[i][j] == 1){
                    return make_pair(i,j);  // this is equal to sending an ordered set or (i,j);
                }
            }
        }
        return make_pair(-1, -1);
    }

    vector<pair<int, int>> getNeighbours(pair<int, int> pos, int m, int n){
        vector<pair<int, int>> vec;
        int temp;
        if( pos.first > 0)
            vec.push_back(make_pair(pos.first-1, pos.second));
        if( !(pos.second%n == 0)  && pos.second-1 >= 0)
            vec.push_back(make_pair(pos.first, pos.second-1));
        if( !((pos.second+1)%n == 0 ) && pos.second+1 < n)
            vec.push_back(make_pair(pos.first, pos.second+1));
        if( pos.first < m-1)
            vec.push_back(make_pair(pos.first+1, pos.second));
        return vec;
    }

};

class Solution{
private:
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>> rottenOranges, int rows, int columns){
        int time = 0;
        bool newOrangeRotten = false;
        while(!rottenOranges.empty()){
            newOrangeRotten = false;
            int len = rottenOranges.size();
            for(int i=0;i<len; i++){
                pair<int, int> e = rottenOranges.front();
                rottenOranges.pop();
                // Now check out its neighbours
                if(e.first>0 && grid[e.first-1][e.second] == 1) {
                    grid[e.first-1][e.second] = 2;
                    rottenOranges.push({e.first-1, e.second});
                    newOrangeRotten = true;
                }
                if(e.first<rows-1 && grid[e.first+1][e.second] == 1){
                    grid[e.first+1][e.second] = 2;
                    rottenOranges.push({e.first+1, e.second});
                    newOrangeRotten = true;
                }
                if(e.second > 0 && grid[e.first][e.second-1] == 1){
                    grid[e.first][e.second-1] = 2;
                    rottenOranges.push({e.first, e.second-1});
                    newOrangeRotten = true;
                }
                if(e.second <columns-1 && grid[e.first][e.second+1] == 1){
                    grid[e.first][e.second+1] = 2;
                    rottenOranges.push({e.first, e.second+1});
                    newOrangeRotten = true;
                }
            }
            if(newOrangeRotten) time++;
            else return time;
        }
        return time;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time;
        // get rotten oranges
        queue<pair<int, int>> rottenOranges;
        int rows = grid.size();
        int columns = grid[0].size();
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j] == 2)
                    rottenOranges.push({i,j});
            }
        }
        time = bfs(grid, rottenOranges, rows, columns);
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return time;
    }

};


int main(){
    vector<vector<int>> grid1{{2,1,1},{1,1,0},{0,1,1}};                     // output is 4
    vector<vector<int>> grid2{{2,1,1},{0,1,1},{1,0,1}};                     // output is -1
    vector<vector<int>> grid3{{0,2}};                                       // output is 0
    vector<vector<int>> grid4{{1,1,0,0}, {0,1,1,0},{0,0,2,1},{1,1,1,0}};    // output is -1
    vector<vector<int>> grid5{{0}};                                         // output is 0
    vector<vector<int>> grid6{{1}};                                         // output is -1
    vector<vector<int>> grid7{{2}};                                         // output is 0
    vector<vector<int>> grid8{{2,1,1},{1,1,1},{0,1,2}};                     // output is 2
    
    Solution sol;
    vector<pair<int, int>> vec;
    // for(int i=0; i< 3;i++)
    // {
    //     for(int j=0; j<3; j++){
    //         vec = sol.getNeighbours(make_pair(i,j), 3,3);
    //         for(auto e: vec){
    //             cout << "(" << i << ", " << j << "): " << e.first << ", " << e.second << endl;
    //         }
    //     }
    // }
    
    cout << sol.orangesRotting(grid1) << endl;
    cout << sol.orangesRotting(grid2) << endl;
    cout << sol.orangesRotting(grid3) << endl;
    cout << sol.orangesRotting(grid4) << endl;
    cout << sol.orangesRotting(grid5) << endl;
    cout << sol.orangesRotting(grid6) << endl;
    cout << sol.orangesRotting(grid7) << endl;
    cout << sol.orangesRotting(grid8) << endl;
    // sol.orangesRotting(grid1);

    // int temp = sol.orangesRotting(grid5);
    // cout << "time taken: " << temp << endl;

    // print_grid(grid1);
    // print_grid(grid2);
    // print_grid(grid3);
    return 0;
}