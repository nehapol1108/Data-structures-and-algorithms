#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N) 
//SC->O(N+N)
//MEMOIZATION
int func(int n,vector<int>&dp,vector<int>& h){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int left = func(n-1,dp,h) + abs(h[n] - h[n-1]);
    int right = INT_MAX;
    if(n>1){
        right = func(n-2,dp,h) + abs(h[n]-h[n-2]);
    }
    return dp[n] = min(left,right);    
}


//TC->O(N) 
//SC->O(N)
//TABULATION
int minimumEnergy(vector<int>&a, int n) {
    // Code here
    vector<int>dp(n+1,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int left = dp[i-1] + abs(a[i]-a[i-1]);
        int right = INT_MAX;
        if(i>1){
            right = dp[i-2] + abs(a[i]-a[i-2]);
        }
        dp[i] = min(left,right);
    }
    return dp[n-1];
}

//TC->O(N) 
//SC->O(1)
//SPACE OPTIMIZATION
int minimumEnergy(vector<int>&a, int n) {
    // Code here
    int prev=0;
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int left = prev + abs(a[i]-a[i-1]);
        int right = INT_MAX;
        if(i>1){
            right = prev2 + abs(a[i]-a[i-2]);
        }
        prev2 = prev;
        prev = min(left,right);
    }
    return prev;
}
int main(){
    vector<int>height;
    int n;
    vector<int>dp(n,-1);
    return func(n-1,dp,height);
    return 0;
}