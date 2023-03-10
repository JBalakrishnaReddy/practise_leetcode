#include <iostream>
#include <cstddef>
#include <vector>

using namespace std;

int main()
{
    vector<int> g1;
    // vector<int> v2(1,2,3,4,5);
    int arr[] = {3,4,5,6,7,8};
    // vector<int> num {1, 2, 3, 4, 5};
    // vector<int> v2(arr, sizeof(arr)/sizeof(arr[0]));
    vector<int> v2(3,4);
    for(int i=1; i<=10; i++)
        g1.push_back(i);

    cout << "output of begin and end" <<endl;
    // for (const int &i=g1.begin(); i!= g1.end(); i++)
    //     cout << i << " ";
    for (vector<int>::iterator i =g1.begin(); i!=g1.end(); i++)
        cout << *i << " ";
    cout << endl;

    cout << "size: " << g1.size() << endl;
    cout << "max_size: " << g1.max_size() << endl;
    cout << "capacity: " << g1.capacity() << endl;
    cout << "is empty: " << g1.empty() << endl;
    // cout << "hello world" << endl;

    for (auto i=v2.begin(); i!=v2.end(); i++)
        cout << *i << " ";
    cout << endl;
    return 0;
}