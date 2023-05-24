#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second > b.second;
    }
};

inline bool cmp(pair<int, int> x, pair<int,int>y)
{
    return x.second < y.second;
}

class Solution1 {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> lis;
        // map<int, int, greater<int> > lis2;
        priority_queue < pair<int, int>, vector<pair<int, int>>, myComp > pq;
        vector<int> vec;
        for(auto i:nums)    lis[i]++;

        for(unordered_map<int,int>::iterator it=lis.begin(); it != lis.end(); it++){
            pq.push({it->first, it->second});
            // cout << it->first <<"; " << it->second << endl;
        }
        while(k--){
            // cout << pq.top().first <<"; " << pq.top().second << endl;
            vec.push_back(pq.top().first);
            pq.pop();
        }
        return vec;
    }
};

class Solution{
    // This is the best solution I came up with.
    public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        vector<pair<int,int>> vec;
        unordered_map<int, int> lis;
        // auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        //     return a.second < b.second;
        // };
        // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        priority_queue < pair<int, int>, vector<pair<int, int>>, myComp > pq;
        vector<int> ans;
        for(auto i:nums)    lis[i]++;
        for(auto i:lis){
            pq.push(i);
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }

};

int main(){
    Solution sol;
    vector<int> vec{1,1,1,2, 4, 2, 4, 3};
    vector<int> ans = sol.topKFrequent(vec, 2);
    for(auto i:ans) cout << i << ", ";
    cout << endl;
    return 0;
}