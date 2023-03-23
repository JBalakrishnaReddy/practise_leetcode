/*There are n cars going to the same destination along a one-lane road. The destination is target miles away.

You are given two integer array position and speed, both of length n, where position[i] is the position of 
    the ith car and speed[i] is the speed of the ith car (in miles per hour).

A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the 
    same speed. The faster car will slow down to match the slower car's speed. The distance between these 
    two cars is ignored (i.e., they are assumed to have the same position).

A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single 
    car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.

Return the number of car fleets that will arrive at the destination. */

/*
Example 1:

Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
Explanation:
The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12.
The car starting at 0 does not catch up to any other car, so it is a fleet by itself.
The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
Note that no other cars meet these fleets before the destination, so the answer is 3. */

/*
Example 2:

Input: target = 10, position = [3], speed = [3]
Output: 1
Explanation: There is only one car, hence there is only one fleet.

Example 3:

Input: target = 100, position = [0,2,4], speed = [4,2,1]
Output: 1
Explanation:
The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. The fleet moves at speed 2.
Then, the fleet (speed 2) and the car starting at 4 (speed 1) become one fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
*/


// We have to find maximum number of car fleets possible.

#include <iostream>
#include <cstddef>
#include <vector>

using namespace std;

void print_vector(vector<int> & vec, string msg="")
{
    cout << msg;
    for(vector<int>:: iterator i = vec.begin(); i!=vec.end();i++)
    {
        cout << *i << ",";
    }
    cout << endl;
}

class Solution{
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){

        vector<int> time;   // time vector of size n;
        int numOfFleets = 0;
        int numOfCars = position.size();
        int currentFleet = 1;
        if(numOfCars == 1){
            return 1;
        }
        shortBubbleSort(position, speed);
        // print_vector(position, "sorted position array: ");
        // print_vector(speed, "sorted speed array: "); 

        // We will get the time vector 
        // for(int i=0; i<numOfCars; i++){
        //     time.push_back(position[i]/speed[i]);
        // }
        for(int i=numOfCars-1; i>=0; i--){
            numOfFleets += 1;
            int time = (target-position[i])/speed[i];
            cout << __LINE__ << " " << time << " " << position[i] << " " << speed[i] << endl;
            for(int j=i-1; j>=0; j--){
                i = j+1;
                cout << __LINE__ << " " << (target-position[j])/speed[j] << " " << position[j] << " " << speed[j] << endl;
                if((target-position[j])/speed[j] <= time){
                    time = (target-position[j])/speed[j];
                    continue;
                }
                break;
            }
        }

        // for(int i=numOfCars; i>0 ; i--){
        //     numOfFleets += 1;
        //     int time = position[i]/speed[i];
        //     for(int j=i-1; j<numOfCars; j--){
        //         i=j+1;
        //         if(position[j]/speed[j] != time)
        //             break;
        //         continue;
        //     }
        // }
        return numOfFleets;
    }
private:
    vector<int>& shortBubbleSort(vector<int>& avector, vector<int>& bvector){ //the vector for bubble sort
        bool exchanges = true;
        int passnum = avector.size();
        // print_vector(avector, "a vector: ");
        //while vector size is greater than 0 and exchanges = true
        while (passnum > 0 && exchanges) {
            exchanges = false;
        //loops through vector, exchanging values until it reaches the end of vector.
            for(int i = 0; i < passnum-1; i++){
                if(avector[i] > avector[i+1]){
                    exchanges = true;
                    // int temp = avector[i];
                    // avector[i] = avector[i+1];
                    // avector[i+1] = temp;
                    swap(avector[i], avector[i+1]);
                    swap(bvector[i], bvector[i+1]);
                }
            }
            //subtracts from the passnum variable so that the next passthrough is one less
            //than the previous, because the largest value has already 'bubbled' all the way up.
            passnum = passnum - 1;
        }
        return avector;
    }

    void swap(int& x, int& y){
        int temp = x;
        x = y;
        y = temp;
    }

};

int main(){
    // int target = 12, pos[] = {10,8,0,5,3}, spd[] = {2,4,1,1,3};
    int target = 100, pos[] = {0,2,4}, spd[] = {4,2,1};
    vector<int> position, speed;
    for(int i=0; i<sizeof(pos)/sizeof(int); i++)
        position.push_back(pos[i]);
    for(int i=0; i<sizeof(spd)/sizeof(int); i++)
        speed.push_back(spd[i]);

    Solution sol;
    // sol.shortBubbleSort(position, speed);
    // print_vector(position, "sorted position array: ");
    // print_vector(speed, "sorted speed array: ");
    cout << "number of Fleets: " << sol.carFleet(target, position, speed);
    // cout << "maximum number of car fleets: " << sol.carFleet(target, position, speed) << endl;
    return 0;
}