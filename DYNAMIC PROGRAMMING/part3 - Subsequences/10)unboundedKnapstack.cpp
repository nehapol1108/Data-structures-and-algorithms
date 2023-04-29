#include<bits/stdc++.h>
#define ll long long
using namespace std;
//space O(n) TC=2^n exponential as every function call other two function gives tle O(N)*K
int f(int i,int w, vector<int> &val, vector<int> &wt){
    if(i==0){
        return (int)((w/wt[0]) * val[0]);
    }
    int nttake = f(i-1,w,val,wt);
    int take = -1e9;
    if(wt[i]<=w){
        take = val[i]+ f(i,w-wt[i],val,wt);
    }
    return max(take,nttake);
}

//space O(n*maxwt)+O(n) TC = O(n*maxwt) //memoization
int f(int i,int w, vector<int> &val, vector<int> &wt,vector<vector<int>>&dp){
    if(i==0){
        return dp[0][w]= (int)((w/wt[0]) * val[0]);
    }
    if(dp[i][w]!=-1){
       return dp[i][w];
    }
    int nttake = f(i-1,w,val,wt,dp);
    int take = -1e9;
    if(wt[i]<=w){
        take = val[i]+ f(i,w-wt[i],val,wt,dp);
    }
    return dp[i][w]= max(take,nttake);
}

//space O(n*maxwt) TC = O(n*maxwt) //tabulation
int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>>dp(n,vector<int>(W+1,0));
    for(int i=0;i<=W;i++){
        dp[0][i]= (int)((i/wt[0]) * val[0]);
    }
    for(int i=1;i<n;i++){
        for(int w=0;w<=W;w++){
            int nttake = dp[i-1][w];
            int take = -1e9;
            if(wt[i]<=w){
                take = val[i]+ dp[i][w-wt[i]];
            }
            dp[i][w]= max(take,nttake);
        }
    }
    return dp[n-1][W];
}


//space O(target) TC = O(n*target) //space optimisation
int unboundedKnapsack_space(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<int>prev(W+1,0),curr(W+1,0);
    for(int i=0;i<=W;i++){
        prev[i]= (int)((i/wt[0]) * val[0]);
    }
    for(int i=1;i<n;i++){
        for(int w=0;w<=W;w++){
            int nttake =  prev[w];
            int take = -1e9;
            if(wt[i]<=w){
                take = val[i]+ curr[w-wt[i]];
            }
            curr[w]= max(take,nttake);
        }
        prev= curr;
    }
    return  prev[W];
}

//space O(target) TC = O(n*target) //further space optimisation
int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<int>prev(W+1,0);
    for(int i=0;i<=W;i++){
        prev[i]= (int)((i/wt[0]) * val[0]);
    }
    for(int i=1;i<n;i++){
        for(int w=0;w<=W;w++){
            int nttake =  prev[w];
            int take = -1e9;
            if(wt[i]<=w){
                take = val[i]+ prev[w-wt[i]];
            }
            prev[w]= max(take,nttake);
        }
    }
    return  prev[W];
}
int main(){
    
    return 0;
}