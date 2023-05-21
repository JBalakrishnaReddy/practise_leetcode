#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        //Swap extreme rows and then do the transpose to get what we want
        int len = matrix.size();
        reverse(matrix.begin(), matrix.end());
        // for (auto i: matrix){
        //     for(auto j:i){
        //         cout << j << ", ";
        //     }
        //     cout << endl;
        // }

        for(int i=0; i< len; i++){
            for (int j=i+1; j<len; j++){
                swap(matrix[j][i], matrix[i][j]);
            }
        }

        // for (auto i: matrix){
        //     for(auto j:i){
        //         cout << j << ", ";
        //     }
        //     cout << endl;
        // }
    }
};


int main(){ 
    // vector<vector<int>> matrix1{
    //     {1,2,3},
    //     {4,5,6},
    //     {7,8,9}
    // };

    vector<vector<int>> matrix2{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution sol;
    sol.rotate(matrix2);
}