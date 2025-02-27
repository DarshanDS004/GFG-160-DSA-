[Naive Approach] Using Temporary Array - O(n) Time and O(n) Space
The idea is to create a temporary array of same size as the input array arr[].

First, copy all non-zero elements from arr[] to the temporary array.
Then, fill all the remaining positions in temporary array with 0.
Finally, copy all the elements from temporary array to arr[].

// C++ Program to move all zeros to end using temporary array

#include <bits/stdc++.h>
using namespace std;

// function to move all zeros to the end
void pushZerosToEnd(vector<int> &arr) {
    int n = arr.size();
    vector<int> temp(n);

    // to keep track of the index in temp[]
    int j = 0;

    // Copy non-zero elements to temp[]
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0)
            temp[j++] = arr[i];
    }

    // Fill remaining positions in temp[] with zeros
    while (j < n) {
        temp[j++] = 0;
    }

    // Copy all the elements from temp[] to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

int main() {
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd(arr);

    // Print the modified array
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}


[Better Approach] Two Traversals - O(n) Time and O(1) Space
The idea is to move all the zeros by traversing the array twice.

First Traversal: Shift non-zero elements

Traverse the array and maintain the count of non-zero elements. This count is initialized with 0 and keeps track of where the next non-zero element should be placed in the array.
If the element is non-zero, place it at arr[count] and increment count by 1.
After traversing all the elements, all non-zero elements will be shifted to the front while maintaining their original order.
Second Traversal: Fill remaining positions with zeros

After the first traversal, all non-zero elements will be at the start of the array and count will store the index where the first zero should be placed.
Iterate from count to the end of array and fill all indices with 0.


// C++ Program to move all zeros to end using two traversals

#include <bits/stdc++.h>
using namespace std;

// Function which pushes all zeros to end 
void pushZerosToEnd(vector<int>& arr) {
    
    // Count of non-zero elements
    int count = 0;  

    // If the element is non-zero, replace the element at
    // index 'count' with this element and increment count
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0)
            arr[count++] = arr[i];
    }

    // Now all non-zero elements have been shifted to
    // the front. Make all elements 0 from count to end.
    while (count < arr.size())
        arr[count++] = 0;
}

int main() {
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}


[Expected Approach] One Traversal - O(n) Time and O(1) Space
The idea is similar to the previous approach where we took a pointer, say count to track where the next non-zero element should be placed. However, on encountering a non-zero element, instead of directly placing the non-zero element at arr[count], we will swap the non-zero element with arr[count]. This will ensure that if there is any zero present at arr[count], it is pushed towards the end of array and is not overwritten.

  // C++ Program to move all zeros to end using one traversal

#include <bits/stdc++.h>
using namespace std;

// Function which pushes all zeros to end of array
void pushZerosToEnd(vector<int>& arr) {
  
    // Pointer to track the position for next non-zero element
    int count = 0;
     
    for (int i = 0; i < arr.size(); i++) {

        // If the current element is non-zero
        if (arr[i] != 0) {
          
            // Swap the current element with the 0 at index 'count'
            swap(arr[i], arr[count]);
            // Move 'count' pointer to the next position
            count++;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}


Using Library Methods
In C++, there exists a method stable_parition() that we can directly use here to implement the above method.



// C++ Program to move zeros to the end using Library Methods

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void pushZerosToEnd(vector<int> &arr) {
    stable_partition(arr.begin(), arr.end(), [](int n) { 
                                       return n != 0; });
}

int main() {
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd(arr);
    for (int i : arr)
        cout << i << ' ';
    return 0;
}
