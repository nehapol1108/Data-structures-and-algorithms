// https://leetcode.com/problems/increasing-triplet-subsequence/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool increasingTriplet(vector<int>&a) {
    int n=a.size();
    if(n<3){
        return false;
    }
    int left = INT_MAX;
    int mid = INT_MAX;
    for(int i=0;i<n;i++){
        if(a[i]>mid){
            return true;
        }else if(a[i]>left && a[i]<mid){
            mid = a[i];
        }
        else if(a[i]<left){
            left=a[i];
        }
    }
    return false;
}