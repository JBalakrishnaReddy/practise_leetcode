
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        /*  We buy and sell iff we see profit. The algorithm maintains prices s.t
            at any point of time the indexes of minPrice and maxPrices are either same or 
            maxPrice index is greater or later day's as compared to minPrice.
            At any point during traversal if find that current maxPrice is more 
            than current day price by transaction fee then we sell it and book profit, 
            now we believe that current day prices are minPrices and maxPrices and we 
            don't sell them as we do not get profit and continue to traverse and repeat previous steps.
            1. Initialize minPrices and maxPrices to prices[0] and start loop over entire price range.
            2. Check if we can make profit. If the current maxPrice is 
                greater than current element by atleast fee we can book
                profit and also initialize minPrice and maxPrice to 
                current price and go to step 2. If we cannot book profits
                then go to next step.
            4. Check if current Price is less than minPrice, 
                if yes then update the current min as well as
                maxPrice also to current price(this is done so that maxPrice 
                is not from previous history of prices) , else go to next step.
            5. If the number is more than maxPrice then update only maxPrice 
            6. Once the loop ends if there can be min and maxPrice that step 
                was unable to capture that can be captured now and update to overall profit.
        */
        int len = prices.size();
        if(len<=1)  return 0;
        int minPrice = prices[0];
        int maxPrice = prices[0];
        int profit = 0;
        for(int i=1; i< len; i++){
            if((prices[i]+fee <= maxPrice) && (maxPrice - minPrice - fee > 0)) {
                //Here the next transaction starts
                profit += maxPrice - minPrice - fee;
                // cout << maxPrice << ", " << minPrice << "," << profit << endl;
                minPrice = maxPrice =prices[i];
                // minPriceIndex = maxPriceIndex = i;
            }
            if(prices[i] <= minPrice){
                // We need to update both minPrice and maxPrice as maxPrice 
                // cannot be something from previous date
                minPrice = maxPrice =prices[i];
                // cout << "i " << i <<" minPrice: " << minPrice << endl;
            }else if(prices[i] > maxPrice){
                maxPrice = prices[i];
                // cout << "i " << i <<" maxPrice: " << maxPrice << endl;
            }
        }
        // cout << maxPrice << ", " << minPrice << endl;
        if((maxPrice - minPrice - fee > 0))  profit += maxPrice - minPrice - fee;
        return profit;
    }
};

int main(){
    // vector<int>prices{1,3,2,8,4,9};
    // vector<int>prices{1,3,2,8,4,9,3,7,5,10,3};  //output=13
    // int fee = 2;
    // vector<int>prices{1,3,7,5,10,3};
    // int fee = 3;
    vector<int>prices{10, 9, 8, 7, 2, 0};       // output = 0
    int fee = 3;
    // vector<int> prices{4,5,2,4,3,3,1,2,5,4};    // output = 4
    // int fee = 1;

    Solution sol;
    int temp = sol.maxProfit(prices, fee);
    cout << temp << endl;

    return 0;
}