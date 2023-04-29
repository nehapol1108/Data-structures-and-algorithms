#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N) 
//SC->O(N+N)
//MEMOIZATION
int func(int *a,int i,vector<int>&dp){
    if(i==0){
        return a[0];
    }
    if(i<0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int pick = func(a,i-2,dp) + a[i];
    int notpick = func(a,i-1,dp);
    return dp[i] = max(pick,notpick);
    
}

//TC->O(N) 
//SC->O(N)
//tabulation
int findMaxSum(int *a, int n) {
    long long dp[n]={0};
    dp[0]=a[0];
    for(int i=1;i<n;i++){
        int take = a[i];
        if(i>1){
            take += dp[i-2];
        }
        int nottake = dp[i-1];
        dp[i] = max(take,nottake);
    }
    return dp[n-1];
}

//TC->O(N) 
//SC->O(1)
//SPACE OPTIMIZATION
int findMaxSum(int *a, int n) {
    int prev=a[0],prev2=0;
    for(int i=1;i<n;i++){
        int take = a[i];
        if(i>1){
            take += prev2;
        }
        int nottake = prev;
        int curr = max(take,nottake);
        prev2= prev;
        prev = curr;
    }
    return prev;
}
int main(){
    int *a;
    int n;
    vector<int>dp(n,-1);
    return func(a,n-1,dp);
    return 0;
}