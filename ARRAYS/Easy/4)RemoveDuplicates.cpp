#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Time complexity: O(n*log(n))+O(n)
// Space Complexity: O(n) 
int removeDuplicates(int arr[], int n) {
    set < int > set;
    for (int i = 0; i < n; i++) {
        set.insert(arr[i]);
    }
    int k = set.size();
    int j = 0;
    for (int x: set) {
        arr[j++] = x;
    }
    return k;
}

// Time complexity: O(n)
// Space Complexity: O(1) 
int remove_duplicate(int a[],int n){
    int j=1;
    if(n==1){
        return 1;
    }
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            a[j]=a[i];
            j++;
        }
    }
    return j;
}
int main(){
    
    return 0;
}