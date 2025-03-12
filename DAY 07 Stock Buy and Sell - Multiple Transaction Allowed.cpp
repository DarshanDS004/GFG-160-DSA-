[Naive Approach] Using Recursion - Exponential Time

We consider every valid pair (A pair of indexes i and j such that price[i] < price[j] and j > i), we get the profit of the pair as (price[j] - price[i]) and add recursively compute profits for i-1 and j+1. Finally we return the maximum of all profits obtained by all valid pairs.

#include <iostream>
#include <vector>
using namespace std;

int maxProfitRec(vector<int> &price, int start, int end) {
    int res = 0;
  
    // Consider every valid pair, find the profit with it
    // and recursively find profits on left and right of it
    for (int i = start; i < end; i++) {
        for (int j = i + 1; j <= end; j++) {
            if (price[j] > price[i]) {
                int curr = (price[j] - price[i]) + 
                            maxProfitRec(price, start, i - 1) + 
                              maxProfitRec(price, j + 1, end);
                res = max(res, curr);
            }
        }
    }
    return res;
}

// Wrapper function
int maximumProfit(vector<int> &prices) {
    return maxProfitRec(prices, 0, prices.size()-1);
}

int main() {
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    cout << maximumProfit(prices);
    return 0;
}

[Better Approach] Local Minima and Maxima - O(n) Time and O(1) Space

When the prices are going down, we do not do anything and let the prices go down. When the prices reach a local minimum value (a value after which the prices go up), we buy the stock. When the prices are going up, we let the prices go up and once the prices reach a local maxima, we sell the stock.

The idea is to traverse the array from left to right and do following.

    Find local minima and then a local maxima.
    Compute the difference between two and add to the result. 

Working:

#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(vector<int>& prices) {
    int n = prices.size();
    int lMin = prices[0];  // Local Minima
    int lMax = prices[0];  // Local Maxima
    int res = 0;
  
    int i = 0;
    while (i < n - 1) {
      
        // Find local minima 
        while (i < n - 1 && prices[i] >= prices[i + 1]) { i++; }
        lMin = prices[i];
       
        // Local Maxima
        while (i < n - 1 && prices[i] <= prices[i + 1]) { i++; }
        lMax = prices[i];
      
        // Add current profit 
        res = res + (lMax - lMin);
    }
  
    return res;
}

int main() {
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    cout << maximumProfit(prices);
    return 0;
}

[Expected Approach] Accumulate Profit - O(n) Time and O(1) Space

This is mainly an optimization over the previous solution. Instead of selling at local maxima, we keep selling while the prices are going up. This way we accumulate the same profit and avoid some condition checks required for computing local minima and maxima.

Traverse price[] from i = 1 to price.size() - 1

    res = 0
    if price[i] > price[i - 1]
        res = res + price[i] - price[i - 1]

// C++ Program to find the max profit when multiple
// transactions are allowed

#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(const vector<int>& prices) {
    int res = 0;
  
    // Keep on adding the difference between
    // adjacent when the prices a
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) 
            res += prices[i] - prices[i - 1];
    }
    
    return res;
}

int main() {
    vector<int> prices = { 100, 180, 260, 310, 40, 535, 695 };
    cout << maximumProfit(prices) << endl;
    return 0;
}
