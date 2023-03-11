#include <iostream>
#include <vector>
#include <stdbool.h>

#include <algorithm>
#include <ctime>

using namespace std;

class Solution {
public:
    vector<int> get_same_values(vector<int> & nums2)
    {
        int temp = nums2[0];
        int count = 1;
        for (int i=1; i<=nums2.size();i++)
        {
            if(temp == nums2[i])
            {
                count ++;
                continue;
            }
            break;
        }
        vector<int> vec;
        vec.push_back(temp);
        vec.push_back(count);
        return vec;
    }

    void print_vector(vector<int> & vec)
    {
        // for(vector<int>:: iterator i = vec.begin(); i!=vec.end();i++)
        // {
        //     cout << *i << ",";
        // }
        for(int i =0; i<vec.size(); i++)
        {
            cout << vec[i] << ",";
        }
        cout << endl;
    }
    
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)
            return;
        if(nums1.size() == n)
        {
            nums1.clear();
            nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
            return;
        } 
        vector<int> vec; // = get_same_values(nums2);
        int temp; // = vec[0];
        int count; // = vec[1];
        // cout << "temp: " << temp << " count:" << count << endl;
        nums1.erase(nums1.begin()+m, nums1.end());
        if(!(nums1[m-1] <= nums2[0]))    // if nums1.end() < nums2.begin()
        {
            for(int i=0; i<= m+n;i++)
            {
                vec = get_same_values(nums2);
                temp = vec[0];
                count = vec[1];
                cout << "temp: " << temp << " count:" << count << endl;
                cout << "i: " << i << endl;
                if(nums1[i] <= temp){
                    continue;
                }
                nums1.insert(nums1.begin()+i, count, temp);
                // nums1.erase(nums1.end()-count, nums1.end());
                nums2.erase(nums2.begin(), nums2.begin()+count);
                i += count;
                // cout << "i: " << i << endl;
                cout<< "nums1: ";
                print_vector(nums1);
                cout << "mums2: ";
                print_vector(nums2);
            }
            nums1.insert(nums1.end(), nums2.begin(), nums2.end());     
        }
        // nums1.insert(nums2.begin(), nums2.end());
        else{
            nums1.insert(nums1.begin()+m, nums2.begin(), nums2.end());     
        }
    }

    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //This code works like charm on Leetcode. Beats most of the codes written by others.
        if(n==0)
            return;
        if(nums1.size() == n)   // or we can say m=0
        {
            nums1.clear();
            nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
            return;
        } 
        // vector<int> vec; // = get_same_values(nums2);
        // int temp;
        // int count;
        // cout << "unsorted array 1 ";
        // print_vector(nums1);
        // cout << "unsorted array 2 ";
        // print_vector(nums2);
        for(int i=0; i<n; i++){
            // vec = get_same_values(nums2);
            // temp = vec[0];
            // count = vec[1];
            bool found = false;
            // cout <<"found: " << found << "m: " << m << endl;
            for(int j=0; j<m; j++){
                // cout << "j: " << j << endl;
                if(nums2[i] <= nums1[j]){
                    // cout << __LINE__ << endl;
                    nums1.insert(nums1.begin()+j, nums2[i]);
                    // cout << __LINE__ << endl;
                    // nums1.erase(nums1.end());
                    nums1.pop_back();
                    // cout << __LINE__ << endl;
                    m++;
                    found = true;
                    break;
                    // m += count;
                    // idx = j;
                    // j = idx+count;
                    // nums2.erase(nums2.begin());
                    // nums2.erase(nums2.begin(), nums2.begin()+count);
                    // continue;
                }
            }
            // cout <<"found: " << found << "m: " << m << endl;

            if(!found){
                nums1.insert(nums1.begin()+m, nums2[i]);
                // nums1.erase(nums1.end());
                nums1.pop_back();
                m++;
            }
            cout<< "nums1: ";
            print_vector(nums1);
            cout << "mums2: ";
            print_vector(nums2);
        }


    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // This is cleaned version of merge2 above. Just removed all the commented code 
        // This code works like charm on Leetcode. Beats most of the codes written by others.
        if(n==0)
            return;
        if(nums1.size() == n)   // or we can say m=0
        {
            nums1.clear();
            nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
            return;
        }
        for(int i=0; i<n; i++){
            bool found = false;
            for(int j=0; j<m; j++){
                // cout << "j: " << j << endl;
                if(nums2[i] <= nums1[j]){
                    nums1.insert(nums1.begin()+j, nums2[i]);
                    nums1.pop_back();
                    m++;
                    found = true;
                    break;
                }
            }
            if(!found){
                nums1.insert(nums1.begin()+m, nums2[i]);
                nums1.pop_back();
                m++;
            }
            cout<< "nums1: ";
            print_vector(nums1);
            cout << "mums2: ";
            print_vector(nums2);
        }
    }
};

int main()
{
    vector<int> nums1;
    int m = 3;
    int arr1[] = {1,2,3,0,0,0,0,0};
    for(int i=0; i<8;i++){
        nums1.push_back(arr1[i]);
    }


    srand(unsigned(std::time(nullptr)));
    vector<int> v(10);
    generate(v.begin(), v.end(), std::rand);
    for(int i=0; i<v.size(); i++){
        v[i] = v[i]%10000;
        cout << v[i] << ",";
    }

    // nums1.push_back(0);
    cout << *nums1.begin() << *nums1.end() << endl;
    // nums1.erase(nums1.end());

    // nums1.erase(nums1.begin()+m, nums1.end());
    // blah.print_vector(nums1);
    // return 0;

    vector<int> nums2;
    int arr2[] = {2,5,6,0,1};
    int n = 5;
    for(int i=0; i<n;i++){
        nums2.push_back(arr2[i]);
    }  
    
    Solution blah;

    // blah.merge(nums1, m, nums2, n);
    // blah.print_vector(nums1);
    blah.print_vector(v);
    return 0;
}