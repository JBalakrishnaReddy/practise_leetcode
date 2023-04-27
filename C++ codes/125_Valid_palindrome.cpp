

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    // Ascii number for A-65 to Z-90, a-97 and z-122, 0 -48 and 9 -57
    bool isPalindrome(string s) {
        string s1;
        for(char &ip :s){
            if(isalnum(ip))
                s1 += tolower(ip);
        }
        return _isPalindrome(s1);
    }
    bool isPalindrome2(string s) {
        int len = s.length();
        string s1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i=0; i<len; i++){
            if( ((s[i] >= 48) && (s[i] <= 57)) || ((s[i] >= 97) && (s[i] <= 122)) ){
                s1 += s[i];
            }
        }
        cout << s1 << endl;
        return _isPalindrome(s1);
    }

private:
    bool _isPalindrome(string s){
        string s2 = s;
        reverse(s2.begin(), s2.end());
        if(!s2.compare(s))
            return true;
        return false;
    }
};

int main(){
    Solution sol;
    int temp = sol.isPalindrome("A man, a plan, a canal: Panama");
    // temp = sol.isPalindrome("race a car");
    // temp = sol.isPalindrome("");
    cout << "is palindrome: " << temp << endl;
    return 0;
}