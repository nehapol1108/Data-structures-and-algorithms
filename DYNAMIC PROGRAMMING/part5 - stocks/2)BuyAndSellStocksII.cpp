#include<bits/stdc++.h>
#define ll long long
using namespace std;
//space O(n) TC= 2^n exponential as every function call other two function gives tle
int f(int i,int buy,vector<int>&a){
    if(i==a.size()){
        return 0;
    }
    int profit=0;
    if(buy){
         profit = max(-a[i]+f(i+1,0,a),f(i+1,1,a));
    }else{
        profit = max(a[i]+f(i+1,1,a),f(i+1,0,a));
    }
    return profit;
}
//space O(n) + O(n*2) TC= O(n*2) memoization
int f(int i,int buy,vector<int>&a,vector<vector<int>>&dp){
    if(i==a.size()){
        return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    if(buy){
         dp[i][buy] = max(-a[i]+f(i+1,0,a,dp),f(i+1,1,a,dp));
    }else{
        dp[i][buy] = max(a[i]+f(i+1,1,a,dp),f(i+1,0,a,dp));
    }
    return dp[i][buy];
}
long long maximumProfit(vector<long long>&a, int n) {
       vector<vector<long long>>dp(n,vector<long long>(2,-1));
    //    return f(0,1,a,dp);
    }
//space O(n*2)  TC= O(n*2) tabulation
int maxProfit(vector<int>&a, int n) {
    
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    dp[n][0] = 0;
    dp[n][1] = 0;
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            if(buy){
                    dp[i][buy] = max(-a[i]+dp[i+1][0],dp[i+1][1]);
            }else{
                dp[i][buy] = max(a[i]+dp[i+1][1],dp[i+1][0]);
            }
        }
    }
    return dp[0][1];
}
//space O(2)  TC= O(n*2) space optimisation
int maxProfit(vector<int>&a, int n) {
 
    vector<int>ahead(2,0),curr(2,0);
    ahead[0] = 0;
    ahead[1] = 0;
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            if(buy){
                    curr[buy] = max(-a[i]+ahead[0],ahead[1]);
            }else{
                curr[buy] = max(a[i]+ahead[1],ahead[0]);
            }   
        }
        ahead = curr;
    }
    return ahead[1];
}
//space O(2)  TC= O(n*2) space optimisation without using array
int maxProfit(vector<int>&a, int n) {
   
    int aheadNtbuy =0,aheadBuy=1,currNtBuy=1,currBuy = 0;
    aheadBuy = 0;
    aheadNtbuy = 0;
    for(int i=n-1;i>=0;i--){
            currBuy = max(-a[i]+aheadNtbuy,aheadBuy);
            currNtBuy = max(a[i]+aheadBuy,aheadNtbuy);  
        aheadNtbuy = currNtBuy;
        aheadBuy = currBuy;
    }
    return aheadBuy;
}
int main(){
    
    return 0;
}