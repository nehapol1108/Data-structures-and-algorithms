#include<bits/stdc++.h>
#define ll long long
using namespace std;

// https://leetcode.com/problems/climbing-stairs/

int mod = 1e9+7;
//Function to count number of ways to reach the nth stair.
//TC->O(N)  SC->O(N) + O(N)  ->stack and dp vector
//memoization
int func(int n,vector<int>&dp){
    if(n<=2){
        dp[n]=n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int one = func(n-1,dp)%mod;
    int two = func(n-2,dp)%mod;
    return dp[n] = (one+two)%mod;
}

//TC->O(N)  SC->O(N)  -> dp vector
//tabulation
int countWays(int n)
{
    if(n==1)return 1;
    vector<int>dp(n+1,0);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
    }
    return dp[n]%mod;
}

//TC->O(N)  SC->O(1) 
//space optimization
int countWays(int n)
{
    if(n==1)return 1;
    int prev2=1,prev=2;
    for(int i=3;i<=n;i++){
        int curr =(prev+prev2)%mod;
        prev2=prev;
        prev=curr;
    }
    return prev%mod;
}

int main(){
    int n;
    vector<int>dp(n+1,-1);
    return func(n,dp)%mod;
    return 0;
}