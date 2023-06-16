#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        // ans.reserve(numRows);
        if(numRows == 0)    return ans;

        ans.push_back({1});
        if (numRows == 1)   return ans;
        
        ans.push_back({1,1});
        if (numRows == 2)   return ans;
        
        for(int i=2; i< numRows; i++){
            vector<int> temp{};
            ans.push_back({});
            int temp2 = 0;
            for(auto j: ans[i-1]){
                ans[i].push_back(temp2+j);
                // temp.push_back(temp2+j);
                temp2 = j;
            }
            ans[i].push_back(1);
            // temp.push_back(1);
            // ans.push_back(temp);
        }
        return ans;
    }
};


int main(int argc, char** argv){
    Solution sol;
    int temp = 2;
    if(argc >= 2){
        temp = atoi(argv[1]);
    }
    vector<vector<int>> vec = sol.generate(temp);
    for(auto i: vec){
        cout << "{ " ;
        for(auto j: i){
            cout << j << ", ";
        }
        cout << "}" << endl;
    }
    return 0;
}