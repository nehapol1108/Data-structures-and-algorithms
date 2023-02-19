#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
// https://www.youtube.com/watch?v=PM0sn2ggtlE&ab_channel=LearnCodeRepeat 
//TC->O(n)
//SC->O(1)
int findKthPositive(vector<int>& a, int k) {
    int n=a.size();
    if(a[0]>k){
        return k;
    }
    int i=0,closeMid=0;
    while(i<n && a[i]-(i+1)<k){
        i++;
        closeMid=i;
    }
    return k+closeMid;
}
//TC->O(logn)
//SC->O(1)
int findKthPositive(vector<int>& a, int k) {
    int n=a.size();
    int low=0,high=n-1;
    int closeMid=0;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(a[mid]-(mid+1)<k){
            closeMid=mid+1;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    cout<<closeMid;
    return k+closeMid;
}

int main(){
    
    return 0;
}