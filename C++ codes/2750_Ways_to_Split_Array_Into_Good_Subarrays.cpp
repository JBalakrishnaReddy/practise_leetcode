/*You are given a binary array nums.

A subarray of an array is good if it contains exactly one element with the value 1.

Return an integer denoting the number of ways to split the array nums into good subarrays. As the number may be too large, return it modulo 109 + 7.

A subarray is a contiguous non-empty sequence of elements within an array.

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    /*  This is based on combinations.
        Answer is Multiply all (numberOfZeros+1) between ones.
        

        Algorithm:
        1. If vector doesn't contain any 1s then return 0 else go to next step.
        2. Start a loop to traverse the digits, go to next step
        3. Pick new number and if number is 0, go to step - 4, else go to step 5.
        4. If zeroPrefixExists == true, then ignore the current number, go to step 3 else go to step 4.1.
            4.1. Increase zerosCount by 1 and go to step 3.
        5. Since the digit is 1, noOfGoodArrays will be equal to noOfGoodArrays*(zerosCount+1).
        6. If the traversal is complete then return the noOfGoodArrays.

    */
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long zerosCount = 0, noOfGoodArrays=1;
        bool zeroPrefixExists = true;
        const int mod = 1e9+ 7;
        if(find(nums.begin(), nums.end(), 1) == nums.end())    return 0;
        for(int i: nums){
            if(i==0){
                if(zeroPrefixExists) continue;
                zerosCount++;
            }else{
                // The below line is computationally expensive because of modulo operator.
                // noOfGoodArrays = noOfGoodArrays == 0 ? (zerosCount+1)%mod :  ((noOfGoodArrays%mod) * ((zerosCount+1)%mod))%mod;
                noOfGoodArrays = noOfGoodArrays*(zerosCount+1);
                // While loop is to avoid modulo operator as it is expensive
                while(noOfGoodArrays >= mod){
                    noOfGoodArrays -= mod;
                }
                // noOfGoodArrays = ((noOfGoodArrays%mod) * ((zerosCount+1)%mod))%mod;
                zerosCount = 0;
                zeroPrefixExists = false;
            }
        }
        return noOfGoodArrays;

    }
};

class Solution1 {
    /*  This is based on combinations.
        The number of combinations depend on number of zeros in between 2 ones.
        Both suffix and prefix zeros doesn't alter the number of combinations 
        as they always go with 1 preceeding it for suffix zeros,
        prefix zeros always go with 1 succeeding it.
        So the algorithm starts with neglecting starting zeros.
        If noOfGoodArray = 0 => we didn't yet encounter 1
        Algorithm:
        1. If vector doesn't contain any 1s then return 0 else go to next step.
        2. Start traversing the digits, go to next step
        3. If the number is 0, go to step - 4, else go to step 
        4. If noOfGoodArray is 0, then ignore the number and go to step 3 else go to step 5.
        5. Increase zerosCount by 1 and go to step 3.
        6. Since the digit is 1, noOfGoodArrays will be 

        Initialize two variable one to count number of zeros between ones, another one to store possible number of combinations
    */
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long zerosCount = 0, noOfGoodArrays=0;
        const int mod = 1e9+ 7;
        if(find(nums.begin(), nums.end(), 1) == nums.end())    return 0;
        for(int i: nums){
            if(i==0){    
                if(noOfGoodArrays == 0) continue;
                zerosCount++;
            }else{
                noOfGoodArrays = noOfGoodArrays == 0 ? (zerosCount+1)%mod :  ((noOfGoodArrays%mod) * ((zerosCount+1)%mod))%mod;
                zerosCount = 0;
            }
        }
        return noOfGoodArrays;

    }
};

int main(){
    vector<int> vec1{0,1,1,0,0,1,0,0,1,1,0,1,0,1};      // 36
    vector<int> vec2{0,0,0};                            // 0
    vector<int> vec3{0,1,0};                            // 1
    vector<int> vec4{0,1,0,0,1};                        // 3
    vector<int> vec5{0,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,0,0,1,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,0,1,0,1,0,1,1,0,0,0,0,0,1,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,1,0,1,0,0,0,1,0,0,1,1,0,1,1,1,1,1,0,1,1,0,0,1,1,1,0,0,1,0,0,1,1,0,1,0,1,1,1,0,0,1,0,0,0,1,0,0,1,0,0,1,1,1,1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,1,1,0,0,0,1,0,1,1,1,1,1,0,1,0,1,0,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,1,0,0,1,1,1,0,1,1,1,0,1,0,1,1,0,0,1,1,1,0,0,1,1,1,1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,1,0,1,0,1,1,1,0,0,1,0,1,0,1,0,1,0,1,1,0,0,1,0,0,1,0,1,1,0,0,0,0,1,0,0,0,1,0,1,0,1,1,1,1,0,0,0,1,0,0,1,0,0,0,1,0,1,1,1,0,1,1,0};

    Solution sol;
    cout << sol.numberOfGoodSubarraySplits(vec1) << endl;
    cout << sol.numberOfGoodSubarraySplits(vec2) << endl;
    cout << sol.numberOfGoodSubarraySplits(vec3) << endl;
    cout << sol.numberOfGoodSubarraySplits(vec4) << endl;
    cout << sol.numberOfGoodSubarraySplits(vec5) << endl;




}