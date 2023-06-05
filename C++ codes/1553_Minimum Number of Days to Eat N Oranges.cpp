#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;

class Solution1 {
    // This solution has to be worked recursively with minimum no. of days at each stage
public:
    int minDays(int n) {
        // as of now this algorithm doesn't work for 40 and 80 oranges
        if(n <= 2) return n;
        int count = 0;
        cout << count << ": " << n << endl;
        if(n%3 == 0){
            // count = 1 + minDays(n-2*(n/3));
            count = 1+minDays(n/3);
        }else if((n-1)%3 ==0 ){
            // count = 2 + minDays((n-1) - 2 *((n-1)/3));
            count = 2 + minDays((n-1)/3);
        }else if(n%2 == 0){
            count = 1+ minDays(n/2);
        }else{
            count = 1+ minDays(n-1);
        }
        return count;
    }
};

class Solution2 {
    // This solution has to be worked recursively with minimum no. of days at each stage using trees concept.
    unordered_map<int, int> minDaysPC;
public:
    Solution2(){
        minDaysPC[0] = 0; minDaysPC[1] = 1; minDaysPC[2] = 2; minDaysPC[3] = 2;
        minDaysPC[4] = 3; minDaysPC[5] = 4; minDaysPC[6] = 3; minDaysPC[7] = 4;
        minDaysPC[8] = 4; minDaysPC[9] = 3; minDaysPC[10]= 4; minDaysPC[11]= 5;
    }
    int minDays(int n) {
        // if(n < 11) return minDaysPC[n];
        if( n < 12) return minDaysPC[n];
        int numDays = 0;
        // cout << n << endl;
        // if( (n%3 == 0) && ((n-1)%3 ==0) && (n%2 == 0)){
        //     numDays = 1+min(min(1+minDays(n/3), 2 + minDays((n-1)/3)), 1+ minDays(n/2));
        // }else
        if( (n%3 == 0) && (n%2 == 0)){
            // cout << __LINE__ << endl;
            numDays = min(1+minDays(n/3), 1+ minDays(n/2));
        }else if( ((n-1)%3 ==0) && (n%2 == 0)){
            // cout << __LINE__ << endl;
            numDays = min(2+minDays((n-1)/3), 1+ minDays(n/2));
        }else if(n%3 == 0){
            // count = 1 + minDays(n-2*(n/3));
            numDays = 1+minDays(n/3);
        }else if((n-1)%3 ==0 ){
            // cout << __LINE__ << endl;
            numDays = 2 + minDays((n-1)/3);
        }else if(n%2 == 0){
            // cout << __LINE__ << endl;
            numDays = 1+ minDays(n/2);
        }else{
            // cout << __LINE__ << endl;
            numDays = 1+ minDays(n-1);
        }
        return numDays;
    }
    

};

class Solution3 {
    // This solution has to be worked recursively with minimum no. of days at each stage using trees concept.
    // unordered_map<int, int> minDaysPC;
    vector<int> minDaysPC;
public:
    Solution3(){
        minDaysPC.resize(12);
        minDaysPC[0] = 0; minDaysPC[1] = 1; minDaysPC[2] = 2; minDaysPC[3] = 2;
        minDaysPC[4] = 3; minDaysPC[5] = 4; minDaysPC[6] = 3; minDaysPC[7] = 4;
        minDaysPC[8] = 4; minDaysPC[9] = 3; minDaysPC[10]= 4; minDaysPC[11]= 5;
    }
    int minDays(int n) {
        // if(n < 11) return minDaysPC[n];
        if( n < 12) return minDaysPC[n];
        int numDays = 0;
        // cout << n << endl;
        
        pair<int, bool > a (n/3, n%3 == 0);
        pair<int, bool > b (n/2, n%2 == 0);
        pair<int, bool > c ((n-1)/3, (n-1)%3 == 0);
        pair<int, bool > d ((n-2)/3, (n-2)%3 == 0);
        if(a.second && b.second ){
            numDays = min(1+minDays(a.first), 1+minDays(b.first));
        }else if(b.second && c.second){
            numDays = min(1+minDays(b.first), 2+minDays(c.first));
        }else if(b.second && d.second){
            numDays = min(1+minDays(b.first), min(3+minDays(d.first), 1+minDays(n-1)));
        }else if(a.second){
            numDays = 1+minDays(a.first);
        }else if(c.second){
            numDays = 2+minDays(c.first);
        }else if(b.second){
            numDays = 1+minDays(b.first);
        }else{
            numDays = 1+minDays(n-1);
        }
        return numDays;
    }
    

};

class Solution {
    // This solution has to be worked recursively with minimum no. of days at each stage using trees concept.
    // unordered_map<int, int> minDaysPC;
    vector<int> minDaysPC;
public:
    unordered_map <int,int> mp;
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
        // if(this->mp[n] !=0 ) return mp[n];
        // this->mp[n] += 1;
        int numDays = 0;
        // cout << n << endl;
        
        // pair<int, bool > a (n/3, n%3 == 0);
        // pair<int, bool > b (n/2, n%2 == 0);
        // pair<int, bool > c ((n-1)/3, (n-1)%3 == 0);
        // pair<int, bool > d ((n-2)/3, (n-2)%3 == 0);
        // if(a.second && b.second ){
        //     numDays = min(min(1+minDays(a.first), 1+minDays(b.first)),\
        //                 min(2+minDays(a.first-1), 2+minDays(b.first-1)));
        // }else if(b.second && c.second){
        //     numDays = min(2+minDays(b.first-1), min(1+minDays(b.first),\
        //                 2+minDays(c.first)));
        // }else if(b.second && d.second){
        //     numDays = min( min(1+minDays(b.first), 2+minDays(b.first-1)),\
        //                 min(3+minDays(d.first), 1+minDays(n-1)) );
        // }else if(a.second){
        //     numDays = min(1+minDays(a.first), 2+minDays(a.first-1));
        // }else if(c.second){
        //     numDays = 2+minDays(c.first);
        // }else if(b.second){
        //     numDays = min(1+minDays(b.first), 2+minDays(b.first-1));
        // }else{
        //     numDays = 1+minDays(n-1);
        // }


        pair<int, bool > a (n/3, n%3 == 0);
        pair<int, bool > b (n/2, n%2 == 0);
        pair<int, bool > c ((n-1)/3, (n-1)%3 == 0);
        pair<int, bool > d ((n-1)/2, (n-1)%2 == 0); // This exists only when b is not satisfied.
        pair<int, bool > e ((n-2)/3, (n-2)%3 == 0);
        if( a.second && b.second ){
            #ifdef TRIAL
            numDays = min(min(1+minDays(a.first), 1+minDays(b.first)),\
                        min(2+minDays(a.first-1), 2+minDays(b.first-1)));
            #else
            numDays = min(1+minDays(a.first), 1+minDays(b.first)) ;
            #endif
        }else if( b.second && c.second ) {
            #ifdef TRIAL
            numDays = min(2+minDays(b.first-1), min(1+minDays(b.first),\
                    2+minDays(c.first)));
            #else
            numDays =  min(1+minDays(b.first), 2+minDays(c.first));
            #endif
        }else if( b.second && e.second ){
            #ifdef TRIAL
            numDays = min( min(1+minDays(b.first), 2+minDays(b.first-1)),\
                        min(3+minDays(e.first), 1+minDays(n-1)) );
            #else
            numDays =  min(1+minDays(b.first), 3+minDays(e.first));
            #endif
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
        // this->mp[n] = numDays;
        return numDays;
    }
    

};


int main(int argc, char* argv[]){
    Solution sol;
    int temp = 0;
    // map<int, int> mp;
    // cout << mp.size() << endl;
    // cout << mp[0] << endl;
    // cout << mp.size() << endl;
    // for(int i=0; i<12; i++){
    //     temp = sol.minDays(i);
    //     cout << i << ": " << temp << endl;
    // }
    for(int i=1; i<argc; i++){
        // cout << atoi(argv[i]) << endl;
        cout << atoi(argv[i]) << ": " << sol.minDays(atoi(argv[i])) << endl;
    }
    cout << sol.mp.size() << endl;
    // for(int i=0; i< sol.mp.size(); i++){
    //     cout << i << ": " << sol.mp[i] << endl;
    // }
    return 0;
    // if(argc > 1){
    //     int temp = atoi(argv[1]);
    // }
    cout << 40 << ": " << sol.minDays(40) << endl;
    cout << 80 << ": " << sol.minDays(80) << endl;
    cout << 19786 << ": " << sol.minDays(19786) << endl;
    cout << 84806671 << ": " << sol.minDays(84806671) << endl;
    // vector<int> vec{10, 20, 30, 40, 50, }
}