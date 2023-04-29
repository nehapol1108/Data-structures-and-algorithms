#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N*capacity) SC->O(N*capacity) + O(N)
//memoization
int knap(int wt[],int val[],int i,int w,vector<vector<int>>&dp){
    if(i==0){
        if(wt[0]<=w){
            return val[0];
        }else{
            return 0;
        }
    }
    if(dp[i][w]!=-1){
        return dp[i][w];
    }
    int nttake = knap(wt,val,i-1,w,dp);
    int take=INT_MIN;
    if(wt[i]<=w){
        take= val[i]+ knap(wt,val,i-1,w-wt[i],dp);
    }
    return dp[i][w]= max(take,nttake);
}
int knapSack(int W, int wt[], int val[], int n) 
{ 
    vector<vector<int>>dp(n,vector<int>(W+1,-1));
    return knap(wt,val,n-1,W,dp);
    
} 

//TC->O(N*capacity) SC->O(N*capacity)
//tabulation
int knapSack(int W, int wt[], int val[], int n) 
{ 
    vector<vector<int>>dp(n,vector<int>(W+1,0));
    for(int i=0;i<=W;i++){
        if(wt[0]<=i){
            dp[0][i]=val[0];
        }
        
    }  
    for(int i=1;i<n;i++){
        for(int w=0;w<=W;w++){
            int nttake = dp[i-1][w];
            int take=INT_MIN;
            if(wt[i]<=w){
                take= val[i]+dp[i-1][w-wt[i]];
            }
            dp[i][w]= max(take,nttake);
        }
    }
    return dp[n-1][W];
    
}

//TC->O(N*capacity) SC->O(capacity)
//space optimization
int knapSack(int W, int wt[], int val[], int n) 
{ 
    vector<int>prev(W+1,0),curr(W+1,0);
    for(int i=0;i<=W;i++){
        if(wt[0]<=i){
            prev[i]=val[0];
        }
        
    }  
    for(int i=1;i<n;i++){
        for(int w=0;w<=W;w++){
            int nttake = prev[w];
            int take=INT_MIN;
            if(wt[i]<=w){
                take= val[i]+prev[w-wt[i]];
            }
            curr[w]= max(take,nttake);
        }
        prev=curr;
    }
    return prev[W];
    
}
int main(){
    
    return 0;
}