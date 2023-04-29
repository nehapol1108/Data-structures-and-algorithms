#include<bits/stdc++.h>
#define ll long long
using namespace std;
//space O(n) TC= 2^n exponential as every function call other two function gives tle
int f(int i,int buy,vector<int>&a,int fees){
    if(i==a.size()){
        return 0;
    }
    int profit=0;
    if(buy){
         profit = max(-a[i]+f(i+1,0,a,fees),f(i+1,1,a,fees));
    }else{
        profit = max(a[i]-fees+f(i+1,1,a,fees),f(i+1,0,a,fees));
    }
    return profit;
}
//space O(n) + O(n*2) TC= O(n*2) memoization
int f_memo(int i,int buy,vector<int>&a,vector<vector<int>>&dp,int fees){
    if(i>=a.size()){
        return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    if(buy){
         dp[i][buy] = max(-a[i]+f_memo(i+1,0,a,dp,fees),f_memo(i+1,1,a,dp,fees));
    }else{
        dp[i][buy] = max(a[i]-fees+f_memo(i+1,1,a,dp,fees),f_memo(i+1,0,a,dp,fees));
    }
    return dp[i][buy];
}
//space O(n*2)  TC= O(n*2) tabulation
int maxProfit(vector<int>&a,int fees) {
    int n = a.size();
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    dp[n][0] = 0;
    dp[n][1] = 0;
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            if(buy){
                    dp[i][buy] = max(-a[i]+dp[i+1][0],dp[i+1][1]);
            }else{
                dp[i][buy] = max(a[i]-fees+dp[i+1][1],dp[i+1][0]);
            }
        }
    }
    return dp[0][1];
}
//space O(2)  TC= O(n*2) space optimisation
int maxProfit(vector<int>&a,int fees) {
    int n = a.size();
    vector<int>ahead(2,0),curr(2,0);
    ahead[0] = 0;
    ahead[1] = 0;
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            if(buy){
                    curr[buy] = max(-a[i]+ahead[0],ahead[1]);
            }else{
                curr[buy] = max(a[i]-fees + ahead[1],ahead[0]);
            }   
        }
        ahead = curr;
    }
    return ahead[1];
}
//space O(2)  TC= O(n*2) space optimisation without using array
int maxProfit(vector<int>&a,int fees) {
    int n = a.size();
    int aheadNtbuy =0,aheadBuy=1,currNtBuy=1,currBuy = 0;
    aheadBuy = 0;
    aheadNtbuy = 0;
    for(int i=n-1;i>=0;i--){
            currBuy = max(-a[i]+aheadNtbuy,aheadBuy);
            currNtBuy = max(a[i]-fees +aheadBuy,aheadNtbuy);  
        aheadNtbuy = currNtBuy;
        aheadBuy = currBuy;
    }
    return aheadBuy;
}
int main(){
    
    return 0;
}