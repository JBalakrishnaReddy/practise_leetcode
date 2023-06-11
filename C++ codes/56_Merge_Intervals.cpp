#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size() <= 1)  return intervals;
        sort(intervals.begin(), intervals.end());
        vector<int> prevSet = intervals[0];
        int len = intervals.size();
        for(int i=1; i<len; i++){
            if(prevSet[1] >= intervals[i][0]){
                if(prevSet[1] <= intervals[i][1]){
                    prevSet[1] = intervals[i][1];
                }
            }else{
                ans.push_back(prevSet);
                prevSet = intervals[i];
            }
        }
        ans.push_back(prevSet);
        return ans;
    }
};

int main(){
    vector<vector<int>> intervals1 {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> intervals2 {{1,4},{4,5}};
    vector<vector<int>> intervals3 {{1,4},{0,4}}; 
    vector<vector<int>> intervals4 {{1,3},{2,6},{8,10},{15,18}, {14,20}, {12, 22}}; 
    vector<vector<int>> intervals5 {{1,4}, {2,3}};
    vector<vector<int>> intervals6 {{1,4},{0,0}};

    Solution sol;
    vector<vector<int>> vec = sol.merge(intervals1);
    vec = sol.merge(intervals2);
    vec = sol.merge(intervals3);
    vec = sol.merge(intervals4);
    vec = sol.merge(intervals5);
    vec = sol.merge(intervals6);

    return 0;
}