#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
        vector<int> generate(int rowIndex) {
        vector<int> ans;
        // ans.reserve(numRows);
        if(rowIndex == 0)    return ans;

        ans.assign({1});
        if (rowIndex == 1)   return ans;
        
        ans.assign({1,1});
        if (rowIndex == 2)   return ans;
        
        for(int i=2; i<=rowIndex; i++){
            vector<int> temp{};
            int temp2 = 0;
            for(auto j: ans){
                temp.push_back(temp2+j);
                temp2 = j;
            }
            temp.push_back(1);
            ans.assign(temp.begin(), temp.end());

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
    vector<int> vec = sol.generate(temp);
    cout << "{ ";
    for(auto i: vec){
            cout << i << ", ";
    }
    cout << "}" << endl;
    return 0;
}