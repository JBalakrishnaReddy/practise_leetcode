#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;

class Solution {
    // This solution has to be worked recursively with minimum no. of days at each stage using trees concept.
    vector<int> minDaysPC;
    unordered_map <int,int> mp;
public:
    Solution(){
        minDaysPC.resize(12);
        minDaysPC[0] = 0; minDaysPC[1] = 1; minDaysPC[2] = 2; minDaysPC[3] = 2;
        minDaysPC[4] = 3; minDaysPC[5] = 4; minDaysPC[6] = 3; minDaysPC[7] = 4;
        minDaysPC[8] = 4; minDaysPC[9] = 3; minDaysPC[10]= 4; minDaysPC[11]= 5;
        // mp[0] = 0; mp[1] = 1; mp[2] = 2; mp[3] = 2;
        // mp[4] = 3; mp[5] = 4; mp[6] = 3; mp[7] = 4;
        // mp[8] = 4; mp[9] = 3; mp[10]= 4; mp[11]= 5;
    }
    int minDays(int n) {
        // if(n < 11) return minDaysPC[n];
        if( n < 12) return minDaysPC[n];
        if(this->mp[n] !=0 ) return mp[n];
        int numDays = 0;
        pair<int, bool > a (n/3, n%3 == 0);
        pair<int, bool > b (n/2, n%2 == 0);
        pair<int, bool > c ((n-1)/3, (n-1)%3 == 0);
        pair<int, bool > d ((n-1)/2, (n-1)%2 == 0); // This exists only when b is not satisfied.
        pair<int, bool > e ((n-2)/3, (n-2)%3 == 0);
        if( a.second && b.second ){
            numDays = min(1+minDays(a.first), 1+minDays(b.first)) ;
        }else if( b.second && c.second ) {
            numDays =  min(1+minDays(b.first), 2+minDays(c.first));
        }else if( b.second && e.second ){
            numDays =  min(1+minDays(b.first), 3+minDays(e.first));
        }else if( a.second && d.second){
            numDays = min(1+minDays(a.first), 2+minDays(d.first));
        }else if( d.second && c.second){
            numDays = min(2+minDays(d.first), 2+minDays(c.first));
        }else if(d.second && e.second){
            numDays = min(2+minDays(d.first), 3+minDays(e.first));
        }else if(a.second){
            numDays = min(1+minDays(a.first), 2+minDays(a.first-1));
        }else if(d.second){
            numDays = 2+minDays(c.first);
        }else if(b.second){
            numDays = min(1+minDays(b.first), 2+minDays(b.first-1));
        }else{
            numDays = 1+minDays(n-1);
        }
        this->mp[n] = numDays;
        return numDays;
    }
};


int main(int argc, char* argv[]){
    Solution sol;
    int temp = 0;
    for(int i=1; i<argc; i++){
        cout << atoi(argv[i]) << ": " << sol.minDays(atoi(argv[i])) << endl;
    }

    cout << 40 << ": " << sol.minDays(40) << endl;
    cout << 80 << ": " << sol.minDays(80) << endl;
    cout << 19786 << ": " << sol.minDays(19786) << endl;
    cout << 84806671 << ": " << sol.minDays(84806671) << endl;
    return 0;
}