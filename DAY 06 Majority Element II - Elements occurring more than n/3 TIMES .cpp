[Naive Approach] Using Nested Loops - O(n^2) Time and O(1) Space

The idea is to iterate over all elements and count the frequency of the element in the array. If the frequency of the element is greater than floor(n/3), add it to the result. To avoid adding duplicate elements into the result, we can check if the element is already present in the result. We can stop the iteration if we have already found two majority elements.
// C++ program to find Majority elements in an array
// using nested loops

#include <iostream>
#include <vector>
using namespace std;

// Function to find Majority elements in an array
vector<int> findMajority(vector<int> &arr) {
    int n = arr.size();
    vector<int> res;

    for (int i = 0; i < n; i++) {
        
        // Count the frequency of arr[i]
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (arr[j] == arr[i])
                cnt += 1;
        }
      
        // Check if arr[i] is a majority element
        if (cnt > (n / 3)) {
          
            // Add arr[i] only if it is not already
            // present in the result
            if (res.size() == 0 || arr[i] != res[0]) {
                res.push_back(arr[i]);
            }
        }
      
        // If we have found two majority elements, 
        // we can stop our search
        if (res.size() == 2) {
            if(res[0] > res[1])
                swap(res[0], res[1]);
            break;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {2, 2, 3, 1, 3, 2, 1, 1};
    vector<int> res = findMajority(arr);
    for (int ele : res)
        cout << ele << " ";
    return 0;
}

1 2 

[Better Approach] Using Hash Map or Dictionary - O(n) Time and O(n) Space

    The idea is to use a hash map or dictionary to count the frequency of each element in the array. After counting, iterate over the hash map and if the frequency of any element is greater than (n/3), push it into the result. Finally, the majority elements are returned after sorting.

// C++ program for finding out majority element in an array
// using hash map

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to find Majority element in an array
vector<int> findMajority(vector<int> &arr) {
    int n = arr.size();
    unordered_map<int, int> freq;
    vector<int> res;

    // find frequency of each number
    for (int ele : arr)
        freq[ele]++;

    // Iterate over each key-value pair in the hash map
    for (auto it : freq) {
        int ele = it.first;
        int cnt = it.second;

        // Add the element to the result, if its frequency
        // if greater than floor(n/3)
        if (cnt > n / 3)
            res.push_back(ele);
    }

    if (res.size() == 2 && res[0] > res[1])
        swap(res[0], res[1]);
    return res;
}

int main() {

    vector<int> arr = {2, 2, 3, 1, 3, 2, 1, 1};
    vector<int> res = findMajority(arr);
    for (auto ele : res) {
        cout << ele << " ";
    }
    return 0;
}


Expected Approach] Boyer-Moore’s Voting Algorithm - O(n) Time and O(1) Space

    The idea is based on the observation that there can be at most two majority elements, which appear more than n/3 times. so we can use Boyer-Moore’s Voting algorithm. As we iterate the array, We identify potential majority elements by keeping track of two candidates and their respective counts.

Steps:

    Initialize two variables ele1 = -1 and ele2 = -1, for candidates and two variables cnt1 = 0 and cnt2 = 0, for counting.
    In each iteration,
        If an element is equal to any candidate, update that candidate's count.
        If count of a candidate reaches zero then replace that candidate with current element.
        If neither candidate matches and both counts are non zero, decrement the counts.
    After this, in second pass we check if the chosen candidates appear more than n/3 times in the array. If they do then include them in result array.

Since any element than appears more than floor(n/3) times, will dominate over elements that appear less frequently. Whenever we encounter a different element, we decrement the count of both the candidates. This maintains at most two candidates in the array.
moore-s-voting-algorithm-1.webpmoore-s-voting-algorithm-1.webp


// C++ program for finding the majority element in an array
// using Moore’s Voting algorithm

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// Function to find Majority element in an array
vector<int> findMajority(vector<int> &arr) {
    int n = arr.size();

    // Initialize two candidates and their counts
    int ele1 = -1, ele2 = -1, cnt1 = 0, cnt2 = 0;

    for (int ele : arr) {
      
        // Increment count for candidate 1
        if (ele1 == ele) {
            cnt1++;
        }
      
        // Increment count for candidate 2
        else if (ele2 == ele) {
            cnt2++;
        }
      
        // New candidate 1 if count is zero
        else if (cnt1 == 0) {
            ele1 = ele;
            cnt1++;
        }
      
        // New candidate 2 if count is zero
        else if (cnt2 == 0) {
            ele2 = ele;
            cnt2++;
        }
      
        // Decrease counts if neither candidate
        else {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> res;
    cnt1 = 0;
    cnt2 = 0;

    // Count the occurrences of candidates
    for (int ele : arr) {
        if (ele1 == ele) cnt1++;
        if (ele2 == ele) cnt2++;
    }

    // Add to result if they are majority elements
    if (cnt1 > n / 3) res.push_back(ele1);
    if (cnt2 > n / 3 && ele1 != ele2) res.push_back(ele2);
    
    if(res.size() == 2 && res[0] > res[1])
        swap(res[0], res[1]);
    return res;
}

int main() {
  
    vector<int> arr = {2, 2, 3, 1, 3, 2, 1, 1};
    vector<int> res = findMajority(arr);
    for (int ele : res) {
        cout << ele << " ";
    }
    return 0;
}

