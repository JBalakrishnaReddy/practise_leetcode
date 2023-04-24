#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOfMultiples(int n) {
        // {
        // vector<int> vec;
        // for(int i=3; i<=n;){
        //     vec.push_back(i);
        //     i+=3;
        // }
        // for(int i=5; i<=n;){
        //     if(getRemainder(i, 3) == 0){
        //         i += 5;
        //         continue;
        //     }
        //     vec.push_back(i);
        //     i += 5;
        // }
        // for(int i=7; i<=n; ){
        //     if((getRemainder(i, 3) == 0) || (getRemainder(i, 5) == 0)){
        //         i += 7;
        //         continue;
        //     }
        //     vec.push_back(i);
        //     i += 7;
        // }
        // // cout << __LINE__ << endl;
        // return sum(vec);
        // }
        
        //The below method seems simple and easy to read but the use of percentiles is computationally expensive for processor.
        // {
        // long sum = 0;
        // for(int i=1;i<=n;i++){
        //     if(i % 3 == 0) sum += i;
        //     else if(i % 5 == 0) sum += i;
        //     else if(i % 7 == 0) sum += i;
        // }
        // return sum;
        // }

        long sum = 0;

        for(int i=3; i<=n;){
            sum += i;
            i += 3;
        }
        for(int i=5; i<=n;){
            if(getRemainder(i, 3) == 0){
                i+=5;
                continue;
            }
            sum += i;
            i += 5;
        }
        for(int i=7; i<=n; ){
            if((getRemainder(i, 3) == 0) || (getRemainder(i, 5) == 0)){
                i += 7;
                continue;
            }
            // vec.push_back(i);
            sum += i;
            i += 7;
        }
        return sum;
    }
private:
    int sum(vector<int> &vec){
        int len=vec.size(), __sum__ = 0;
        for(int i=0;i <len; i++)
        {
            cout << vec[i] << ',';
            __sum__ += vec[i];
        }
        return __sum__;
    }
    int getRemainder(int num, int divisor)
    {
        return (num - divisor * (num / divisor));
    }
};

int main(){
    Solution sol;
    int temp  = sol.sumOfMultiples(40);
    cout << "sum: " << temp << endl;
    return 0;
}