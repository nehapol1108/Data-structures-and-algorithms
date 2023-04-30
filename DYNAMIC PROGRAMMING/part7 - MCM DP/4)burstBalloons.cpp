#include<bits/stdc++.h>
#define ll long long
using namespace std;

//recursion  TC-> exponential SC-> O(n)
int f(int i,int j,vector<int>&a ){
    if(i>j){
        return 0;
    }
    int maxCoin=INT_MIN;
    for(int ind = i;ind<=j;ind++){
        int coins = a[i-1]*a[ind]*a[j+1] + f(i,ind-1,a) + f(ind+1,j,a);
        maxCoin = max(maxCoin,coins);
    }
    return maxCoin;
}
//memoization  TC-> O(n^3) SC-> O(n) + O(n^2)
int f(int i,int j,vector<int>&a,vector<vector<int>>&dp ){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int maxCoin=INT_MIN;
    for(int ind = i;ind<=j;ind++){
        int coins = a[i-1]*a[ind]*a[j+1] + f(i,ind-1,a,dp) + f(ind+1,j,a,dp);
        maxCoin = max(maxCoin,coins);
    }
    return dp[i][j]= maxCoin;
}
//space optimization  TC-> O(n^3) SC-> O(n^2)
int maxCoins(vector<int>& a) {
        
    int n = a.size();
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    a.push_back(1);
    a.insert(a.begin(),1);
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(i>j)continue;
            int maxCoin=INT_MIN;
            for(int ind = i;ind<=j;ind++){
                int coins = a[i-1]*a[ind]*a[j+1] + dp[i][ind-1] + dp[ind+1][j];
                maxCoin = max(maxCoin,coins);
            }
            dp[i][j]= maxCoin;
        }
    }
    return dp[1][n];
}
int main(){
    int n;
    cin>>n;
    vector<int>a; 
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    a.push_back(1);
    a.insert(a.begin(),1);
    return f(1,n,a,dp);
    return 0;
}