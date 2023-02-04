#include<bits/stdc++.h>
using namespace std;
 
// Time Complexity: O(N*log(N))
// Space Complexity: O(n)
int sortArr(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}

// Time Complexity: O(N)
// Space Complexity: O(1)
int largest(vector<int> &arr, int n)
{
    int a = arr[0];
    for(int i=1;i<n;i++){
        a = max(a,arr[i]);
    }
    return a;
}

int main() {
    vector<int> arr1 = {2,5,1,3,0};
    vector<int> arr2 = {8,10,5,7,9};
   
    cout<<"The Largest element in the array is: "<<sortArr(arr1)<<endl;
    cout<<"The Largest element in the array is: "<<largest(arr2,arr2.size())<<endl;
   
    return 0;
}