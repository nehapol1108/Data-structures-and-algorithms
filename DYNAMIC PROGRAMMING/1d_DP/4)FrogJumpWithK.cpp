#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N*K) 
//SC->O(N+N)
//MEMOIZATION
int func(vector<int>& h, int n, int k,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int minSteps=INT_MAX;
    for(int i=1;i<=k;i++){
        int jumpEnergy  = INT_MAX;
        if((n-i)>=0){
            jumpEnergy = func(h,n-i,k,dp) + abs(h[n]-h[n-i]);
            
        }
        minSteps = min(minSteps,jumpEnergy);
        
    }
    return dp[n] = minSteps;
}

//TC->O(N*K) 
//SC->O(N)
//TABULATION
int minimizeCost(vector<int>& a, int n, int k) {
    vector<int>dp(n+1,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int minsteps = INT_MAX;
        for(int j=1;j<=k;j++){
            if((i-j)>=0){
                int jumps = dp[i-j] + abs(a[i]-a[i-j]);
                minsteps = min(minsteps,jumps);
            }
            dp[i] = minsteps;
        }
    }
    return dp[n-1];
}
int main(){
    vector<int>h;
    int n;
    int k;
    vector<int>dp(n,-1);
    return func(h,n-1,k,dp);
    return 0;
}