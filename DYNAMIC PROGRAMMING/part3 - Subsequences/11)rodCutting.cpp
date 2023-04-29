#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N*N) SC->O(N*N) + O(N)
//memoization
int func(int a[],int i,int l,vector<vector<int>>&dp){
    if(i==0){
        return dp[0][l] = a[0]*l;
    }
    if(dp[i][l]!=-1){
        return dp[i][l];
    }
    int nttake = func(a,i-1,l,dp);
    int take = 0;
    int rod_l = i+1;
    if(rod_l<=l){
        take = a[i] + func(a,i,l-rod_l,dp);
    }
    return dp[i][l] = max(take,nttake);
    
}
int cutRod(int price[], int n) {
        
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    
    return func(price,n-1,n,dp);
}

//TC->O(N*N) SC->O(N*N)
//tabulation
int cutRod(int a[], int n) {
        
    vector<vector<int>>dp(n,vector<int>(n+1,0));
    for(int i=0;i<=n;i++){
        dp[0][i] = a[0]*(i);
    }
    for(int i=1;i<n;i++){
        for(int l=0;l<=n;l++){
                int nttake = dp[i-1][l];
                int take = 0;
                int rod_l = i+1;
                if(rod_l<=l){
                    take = a[i] + dp[i][l-rod_l];
                }
                dp[i][l] = max(take,nttake);
        }
    }
    return dp[n-1][n];
}

//TC->O(N*N) SC->O(N)
//space optimization
int cutRod(int a[], int n) {
    vector<int>prev(n+1,0),curr(n+1,0);
    for(int i=0;i<=n;i++){
        prev[i] = a[0]*(i);
    }
    for(int i=1;i<n;i++){
        for(int l=0;l<=n;l++){
                int nttake = prev[l];
                int take = 0;
                int rod_l = i+1;
                if(rod_l<=l){
                    take = a[i] + curr[l-rod_l];
                }
                curr[l] = max(take,nttake);
        }
        prev = curr;
    }
    return prev[n];
}
int main(){
    
    return 0;
}