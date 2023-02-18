#include<bits/stdc++.h>
#define ll long long
using namespace std;
//this one is with duplicates
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/solutions/1890199/c-algorithm-binary-search/ 
bool search(vector<int>& a, int key) {
    int n=a.size();
    int l=0,e=n-1;
    while(l<=e){
        int m=l+(e-l)/2;
        if(a[m]==key){
            return true;
        }else if(a[l]==a[m] && a[m]==a[e]){
            l++;
            e--;
        }else if(a[l]<=a[m]){
            if(key>=a[l] && key<a[m]){
                e=m-1;
            }else{
                l=m+1;
            }
        }else{
            if(key>a[m] && key<=a[e]){
                l=m+1;
            }else{
                e=m-1;
            }
        }
    }
    return false;
    
}
int main(){
    
    return 0;
}