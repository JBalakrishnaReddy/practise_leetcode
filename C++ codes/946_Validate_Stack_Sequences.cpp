#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void print_vector(vector<int> & vec, string msg="")
{
    cout << msg;
    for(int i =0; i<vec.size(); i++)
    {
        cout << vec[i] << ",";
    }
    cout << endl;
}

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        bool possible = true;
        int len = popped.size();
        vector<int> vec;
        vec.reserve(len);   // Since we know its maximum size so reserving it so that push_back doesn't create overhead.
        int next_possible_index;

        vector<int>::iterator it = find(pushed.begin(), pushed.end(), popped[0]);
        if(it==vec.end())
            return false;
        vec.assign(pushed.begin(), it);
        // print_vector(vec,"first assign: ");
        next_possible_index = distance(pushed.begin(), it)+1;    // It has to be less than len
        for(int i=1; i<len; i++){
            // cout<< "element to be popped: " << popped[i] <<endl;
            // print_vector(vec);
            // int temp2 = vec.back();
            if(!vec.empty()){
                if(popped[i] == vec.back()){
                    vec.pop_back();
                    // cout << "popping: " << temp2 << endl;
                    continue;
                }
            }
            if(next_possible_index < len){
                if(popped[i] == pushed[next_possible_index])
                {    
                    next_possible_index++;
                    continue;
                }else{
                    it = find(pushed.begin()+next_possible_index, pushed.end(), popped[i]);
                    if(it!=vec.end()){
                        for(vector<int>::iterator j = pushed.begin()+next_possible_index; j!=it; ++j)
                            vec.push_back(*j);
                        next_possible_index = distance(pushed.begin(), it)+1;
                        // print_vector(vec,"before popping: ");
                        continue;
                    }
                }
            }
            possible = false;
            break;
        }
        return possible;
    }
};

int main(){
    vector<int> pushed;
    // int push_arr[] = {1,2,3,4,5};
    int push_arr[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> popped;
    int pop_arr1[] = {4,5,3,2,1};
    int pop_arr2[] = {4,3,5,1,2};
    int pop_arr3[] = {3,6,5,4,2,1,7,8,9,10};
    for(int i =0; i<sizeof(push_arr)/sizeof(int); i++){
        pushed.push_back(push_arr[i]);
        popped.push_back(pop_arr3[i]); // Since both arrays are of same sizes this doesn't matter to be in a single for loop
    }

    Solution sol;
    bool temp = sol.validateStackSequences(pushed, popped);
    cout << "return: " << temp << endl;

    return 0;
}