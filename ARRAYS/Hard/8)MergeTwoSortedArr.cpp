#include<bits/stdc++.h>
#define ll long long
using namespace std;

// https://leetcode.com/problems/merge-sorted-array/description/

// Time Complexity: O(n+m)
// Space Complexity:  O(n+m) 
void merge(vector<int>&a, int n, vector<int>&b, int m) {
    vector<int>c(n+m);
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(a[i]<=b[j]){
            c[k++]=a[i++];
        }else{
            c[k++]=b[j++];
        }
    }
    while(i<n){
        c[k++]=a[i++];  
    }
    while(j<m){
        c[k++]=b[j++];    
    }
    a = c;
}


// Time Complexity: O(n*m)
// Space Complexity:  O(1) 
void merge(vector<int>&a, int n, vector<int>&b, int m) {
    if(m==0){
        return;
    }
    if(n==0){
        a=b;
        return;
    }
    int k;
    for(int i=0;i<n;i++){
        if(a[i]>b[0]){
            swap(a[i],b[0]);
        }

        int first = b[0];
        for(k=1;k<m && b[k]<first;k++){
            b[k-1]=b[k];
        }
        b[k-1]=first;
    }
    k=n;
    for(int i=0;i<m;i++){
        a[k]=b[i];
        k++;
    }
}

// Time Complexity: O(n+m)
// Space Complexity:  O(1) 
void merge(vector<int>&a, int n, vector<int>&b, int m) {
    int gap = ceil((float)(n+m)/2);
    while(gap>0){
        int i=0,j=gap;
        while(j<(n+m)){
            if(j<n && a[i]>a[j]){
                swap(a[i],a[j]);
            }else if(i<n && j>=n && a[i]>b[j-n]){
                swap(a[i],b[j-n]);
            }else if(i>=n && j>=n && b[i-n]>b[j-n]){
                swap(b[i-n],b[j-n]);
            }
            i++;
            j++;
        }
        
        if(gap==1){
            gap=0;
        }else{
            gap = ceil((float) gap / 2);
        }
    }
        int k=n;
    for(int i=0;i<m;i++){
        a[k]=b[i];
        k++;
    }
}
int main(){
    
    return 0;
}