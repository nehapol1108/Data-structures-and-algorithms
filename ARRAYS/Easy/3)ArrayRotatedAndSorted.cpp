#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Given an array nums, return true if the array was originally sorted in non-decreasing order,
// then rotated some number of positions (including zero). Otherwise, return false.
// There may be duplicates in the original array.
//TC->O(N) S.C->O(1)
bool check(vector<int>& nums) {
    int i=0, n = nums.size();
    while(i < n-1 && nums[i] <= nums[i+1]) ++i;
    int j = i+1;
    while(j < n-1 && nums[j] <= nums[j+1]) ++j;
    
    // the array is either only sorted or sorted & rotated
    return i == n-1 || (j == n-1 && nums[n-1] <= nums[0]);
} 


//check if array is sorted
// Time Complexity: O(N^2)
// Space Complexity: O(1)
bool isSorted(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[i])
        return false;
    }
  }

  return true;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
bool isSorted(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1])
      return false;
  }

  return true;
}
int main(){
    
    return 0;
}