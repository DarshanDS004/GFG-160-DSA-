[Naive Approach] By iterating over all subarrays - O(n^2) Time and O(1) Space

    The idea is to run two nested loops to iterate over all possible subarrays and find the maximum sum. The outer loop will mark the starting point of a subarray and inner loop will mark the ending point of the subarray.

// C++ Program to find the maximum subarray sum using nested loops 

#include <bits/stdc++.h>
using namespace std;

// Function to find the sum of subarray with maximum sum
int maxSubarraySum(vector<int> &arr) {
    int res = arr[0];
  
    // Outer loop for starting point of subarray
      for(int i = 0; i < arr.size(); i++) {
        int currSum = 0;
      
        // Inner loop for ending point of subarray
        for(int j = i; j < arr.size(); j++) {
            currSum = currSum + arr[j];
          
            // Update res if currSum is greater than res
            res = max(res, currSum);
        }
    }
    return res;
}

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << maxSubarraySum(arr);
    return 0;
}


[Expected Approach] Using Kadane's Algorithm - O(n) Time and O(1) Space

    The idea of Kadane's algorithm is to traverse over the array from left to right and for each element, find the maximum sum among all subarrays ending at that element. The result will be the maximum of all these values.

    But, the main issue is how to calculate maximum sum among all the subarrays ending at an element in O(1) time?

    To calculate the maximum sum of subarray ending at current element, say maxEnding, we can use the maximum sum ending at the previous element. So for any element, we have two choices:

        Choice 1: Extend the maximum sum subarray ending at the previous element by adding the current element to it. If the maximum subarray sum ending at the previous index is positive, then it is always better to extend the subarray.
        Choice 2: Start a new subarray starting from the current element. If the maximum subarray sum ending at the previous index is negative, it is always better to start a new subarray from the current element.

    This means that maxEnding at index i = max(maxEnding at index (i - 1) + arr[i], arr[i]) and the maximum value of maxEnding at any index will be our answer.


  // C++ Program for Maximum Subarray Sum using Kadane's Algorithm

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum subarray sum
int maxSubarraySum(vector<int> &arr) {
    int res = arr[0];
    int maxEnding = arr[0];

    for (int i = 1; i < arr.size(); i++) {
      
        // Find the maximum sum ending at index i by either extending 
        // the maximum sum subarray ending at index i - 1 or by
        // starting a new subarray from index i
        maxEnding = max(maxEnding + arr[i], arr[i]);
      
        // Update res if maximum subarray sum ending at index i > res
        res = max(res, maxEnding);
    }
    return res;
}

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << maxSubarraySum(arr);
    return 0;
}


