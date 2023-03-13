#include<bits/stdc++.h>
#define ll long long
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
using namespace std;
int maxScore(vector<int>&a, int k) {
    int j=0,i=0,n=a.size();
    int sum2 = accumulate(a.begin(),a.end(),0);
    int sum=0,mini=INT_MAX;
    if(k>=n){
        return sum2;
    }
    k = n-k;
    while(j<n){
        sum+=a[j];
        if((j-i+1)<k){
            j++;
        }else if((j-i+1)==k){
            mini = min(sum,mini);
            sum-=a[i];
            i++;
            j++;
        }
    }
    
    return sum2-mini;
} 
int main(){
    
    return 0;
}