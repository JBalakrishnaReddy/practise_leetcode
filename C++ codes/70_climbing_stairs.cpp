/* The solution to this problem is completed.
 This is kind of fibonocci sequence problem. */

#include <iostream>
#include <cstddef>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int64_t arr[] = {0,1}, temp=0;
        for (int i=0; i<n; i++){
            temp = arr[0];
            arr[0] = arr[1];
            arr[1] = arr[1]+temp;
        }
        return arr[1];
    }
};

int main()
{
    Solution sol;
    cout << sol.climbStairs(3) << endl;
}
