/*You are given two 0-indexed arrays nums and cost consisting each of n positive integers.

You can do the following operation any number of times:

Increase or decrease any element of the array nums by 1.
The cost of doing one operation on the ith element is cost[i].

Return the minimum total cost such that all the elements of the array nums become equal.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution2 {
public:

    long long calc(vector<int>&nums, vector<int>& cost, long long median){

        long long ans = 0;

         for(int i=0;i<nums.size();i++)
           ans += abs(nums[i]-median)*(cost[i]);
        //    ans += abs(1ll*nums[i]-median)*(1ll*cost[i]);

         return ans;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {

        long long tot = 0;
        long long sum = 0;
        int n = nums.size();

        vector<pair<int,int>> vec;

        for(int i=0;i<nums.size();i++)
            vec.push_back({nums[i],cost[i]});

        sort(vec.begin(),vec.end());

        for(int i=0;i<n;i++)
        sum += vec[i].second;

        long long median=0;
        int i=0;

        while(tot < (sum+1)/2 && i<n){

             tot += vec[i].second;
             median = vec[i].first;
             i++;
        }
        cout << median << endl;
        
        return calc(nums,cost,median);
    }
};

class Solution1 {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long min_cost = INT64_MAX, totalSum = 0, prevSum=INT64_MAX;
        unsigned int len = nums.size();
        long long minValue = INT64_MAX, maxValue=0;
        cout << min_cost << ", " << prevSum << ", " << minValue <<", " << maxValue << endl;
        // int prevSum = INT32_MAX,
        // vector<pair<int,int>>q;
        for(int i=0; i<len;i++){
            if(nums[i]<minValue)    minValue = nums[i];
            if(nums[i] > maxValue)  maxValue = nums[i];
        }
        
        for(long long x = minValue; x<=maxValue; x++){
            totalSum = 0;
            for(int i=0; i<len;i++) totalSum += abs(x-nums[i])*cost[i];
            if(totalSum < min_cost)  min_cost = totalSum;
        }
        return min_cost;
    }

    
};

class Solution{
    /*Solution is based on prefix and suffix*/
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = 0;
        long long totalCost = 0;
        long long leftCost = 0;
        long long rightCost = 0;
        vector<pair<long , long >> vec;
        
        int len = nums.size();
        for(int i=0; i< len; i++)   vec.push_back({nums[i], cost[i]});
        sort(vec.begin(), vec.end());
        vector<long> prefixCost(len);
        prefixCost[0] = vec[0].second;
        
        for(int i=1; i<len; i++){
            prefixCost[i] = vec[i].second + prefixCost[i - 1];
            totalCost += (vec[i].first-vec[0].first)*vec[i].second;    // This is the total cost of moving all the right side elements pulling down by one 
            rightCost += vec[i].second;
        }
        ans = totalCost;             // Assuming first element is the answer.
        // cout << "totalCost:"  << totalCost << ", leftCost: " << leftCost << ", " << "rightCost: " << rightCost << endl;
        // for(int i=1; i<len; i++){
        //     leftCost += vec[i-1].second;
        //     long gap = vec[i].first-vec[i-1].first;
        //     cout << leftCost << ", " << rightCost << endl;
        //     totalCost = totalCost + (leftCost-rightCost)*gap;
        //     rightCost -= vec[i].second;
        //     if(totalCost < ans){
        //         ans = totalCost;
        //     }
        // }
        for (int i = 1; i < len; ++i) {
            int gap = vec[i].first - vec[i - 1].first;
            totalCost += 1l * prefixCost[i - 1] * gap;
            totalCost -= 1l * (prefixCost[len - 1] - prefixCost[i - 1]) * gap;
            ans = min(ans, totalCost);
        }
        return ans;
    }
};

int main(){
    // vector<int> nums{2,2,2,2,2}, cost = {4,2,8,1,3};
    // vector<int> nums{1,3,5,2}, cost{2,3,1,14};
    // vector<int> nums{1,3,5,2, 12, 8, 2, 10, 6}, cost{2,3,1,14, 2, 3, 4, 5, 8};  // Answer should be 116 
    // vector<int> nums{735103,366367,132236,133334,808160,113001,49051,735598,686615,665317,999793,426087,587000,649989,509946,743518};
    // vector<int> cost{724182,447415,723725,902336,600863,287644,13836,665183,448859,917248,397790,898215,790754,320604,468575,825614};  // Answer should be 1907611126748
    vector<int> nums {348417,981862,507335,474537,26633,986541,859441,582902,866561,887385,470146,928812,3510};
    vector<int> cost {612038,351545,413813,455422,507754,391190,760845,523127,854280,21802,801360,682463,845779};    // 2076720842828

    Solution sol;
    long long temp = sol.minCost(nums,cost);
    cout << temp << endl;
    return 0;
}