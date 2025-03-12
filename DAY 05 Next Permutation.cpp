[Naive Approach] Generating All Permutations - O(n!*n*log(n!)) Time and O(n!) Space

    The very basic idea that comes to our mind is that we would first generate all possible permutations of a given array and sort them. Once sorted, we locate the current permutation within this list. The next permutation is simply the next arrangement in the sorted order. If the current arrangement is the last in the list then display the first permutation (smallest permutation).

    Note: This approach will work only when there are no duplicated in the input array. Please refer the expected approach to handle duplicates.

// C++ Program to find the next permutation by generating 
// all permutations

#include <bits/stdc++.h>
using namespace std;

// Generates all permutations
void permutations(vector<vector<int>>& res, vector<int>& curr, 
                  int idx);

// Function to get the next permutation
void nextPermutation(vector<int>& arr) {
  
    // Generate all permutations and store in res
    vector<vector<int>> res;
    permutations(res, arr, 0);
    sort(res.begin(), res.end());

    // Traverse through res and find the next permutation
    for (int i = 0; i < res.size(); i++) {
      
        // Found a match
        if (res[i] == arr) {
          
            // Store the next
            if (i < res.size() - 1)
                arr = res[i + 1];
          
            // If the given permutation is the last
            if (i == res.size() - 1)
                arr = res[0];
          
            break;
        }
    }
}

// Function to generate all possible permutations
void permutations(vector<vector<int>>& res, vector<int>& arr, 
                  int idx) {
  
    // Base case: if idx reaches the end of the array
    if (idx == arr.size() - 1) {
        res.push_back(arr);
        return;
    }

    // Permutations made by swapping each element
    // starting from index `idx`
    for (int i = idx; i < arr.size(); i++) {
      
        // Swapping
        swap(arr[idx], arr[i]);

        // Recursive call to create permutations
        // for the next element
        permutations(res, arr, idx + 1);

        // Backtracking
        swap(arr[idx], arr[i]);
    }
}

int main() {
    vector<int> arr = { 2, 4, 1, 7, 5, 0 };
    nextPermutation(arr);
  
      for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}

[Expected Approach] Generating Only Next - O(n) Time and O(1) Space

Let's try some examples to see if we can recognize some patterns. 

    [1, 2, 3, 4, 5]: next is [1, 2, 3, 5, 4]
    Observation: 4 moves and 5 comes in place of it

    [1, 2, 3, 5, 4]: next is [1, 2, 4, 3, 5]
    Observation: 3 moves, 4 comes in place of it. 3 comes before 5 (mainly 3 and 5 are in sorted order)

    [1, 2, 3, 6, 5, 4]: next is [1, 2, 4, 3, 5, 6]
    Observation: 3 moves, 4 comes in place of it. [3, 5 and 6 are placed in sorted order]

    [3, 2, 1]: next is [1, 2, 3]
    Observation: All elements are reverse sorted. Result is whole array sorted.

    [1, 2, 3, 6, 4, 5]: next is [1, 2, 3, 6, 5, 4]
    Observation: 4 moves and 5 comes in place of it

Observations of Next permutation: 

    To get the next permutation we change the number in a position which is as right as possible.
    The first number to be moved is the rightmost number smaller than its next.
    The number to come in-place is the rightmost greater number on right side of the pivot.

Each permutation (except the very first) has an increasing suffix. Now if we change the pattern from the pivot point (where the increasing suffix breaks) to its next possible lexicographic representation we will get the next greater permutation.

To understand how to change the pattern from pivot, see the below image:
Next-permutation.webpNext-permutation.webp


// C++ Program to find the next permutation by 
// generating only next

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &arr) {
  
    int n = arr.size(); 

     // Find the pivot index
    int pivot = -1; 
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            pivot = i;
            break;
        }
    }

    // If pivot point does not exist, reverse the
    // whole array
    if (pivot == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }

    // find the element from the right that
    // is greater than pivot
    for (int i = n - 1; i > pivot; i--) {
        if (arr[i] > arr[pivot]) {
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    // Reverse the elements from pivot + 1 to the 
    // end to get the next permutation
    reverse(arr.begin() + pivot + 1, arr.end());
}

int main()
{
    vector<int> arr = { 2, 4, 1, 7, 5, 0 };
    nextPermutation(arr);    
    for (int x : arr) 
        cout << x << " ";    
    return 0;
}
