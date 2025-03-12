[Naive Approach] Using a temporary array - O(n) Time and O(n) Space

    The idea is to use a temporary array to store the reverse of the array.

        Create a temporary array of same size as the original array.
        Now, copy all elements from original array to the temporary array in reverse order.
        Finally, copy all the elements from temporary array back to the original array.

  // C++ Program to reverse an array using temporary array

#include <iostream>
#include <vector>
using namespace std;

// function to reverse an array
void reverseArray(vector<int> &arr) {
    int n = arr.size();
    
    // Temporary array to store elements in reversed order
    vector<int> temp(n);
  
    // Copy elements from original array to temp in reverse order
    for(int i = 0; i < n; i++)
        temp[i] = arr[n - i - 1];
  
    // Copy elements back to original array
    for(int i = 0; i < n; i++)
        arr[i] = temp[i];
}

int main() {
    vector<int> arr = { 1, 4, 3, 2, 6, 5 };

    reverseArray(arr);
  
    for(int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    return 0;
}


/*
  [Expected Approach - 1] Using Two Pointers - O(n) Time and O(1) Space

    The idea is to maintain two pointers: left and right, such that left points at the beginning of the array and right points to the end of the array.

    While left pointer is less than the right pointer, swap the elements at these two positions. After each swap, increment the left pointer and decrement the right pointer to move towards the center of array. This will swap all the elements in the first half with their corresponding element in the second half.

*/


// C++ Program to reverse an array using Two Pointers

#include <iostream>
#include <vector>
using namespace std;

// function to reverse an array
void reverseArray(vector<int> &arr) {
  
    // Initialize left to the beginning and right to the end
    int left = 0, right = arr.size() - 1;
  
    // Iterate till left is less than right
    while(left < right) {
      
        // Swap the elements at left and right position
        swap(arr[left], arr[right]);
      
        // Increment the left pointer
        left++;
      
        // Decrement the right pointer
        right--;
    }
}

int main() {
    vector<int> arr = { 1, 4, 3, 2, 6, 5 };

    reverseArray(arr);
  
    for(int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    return 0;
}
