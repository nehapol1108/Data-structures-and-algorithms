#include<bits/stdc++.h>
#define ll long long
using namespace std;
//space O(n) TC= 2^n exponential as every function call other two function gives tle
int f(int i,int buy,vector<int>&a){
    if(i>=a.size()){
        return 0;
    }
    int profit=0;
    if(buy){
         profit = max(-a[i]+f(i+1,0,a),f(i+1,1,a));
    }else{
        profit = max(a[i]+f(i+2,1,a),f(i+1,0,a));
    }
    return profit;
}
//space O(n) + O(n*2) TC= O(n*2) memoization
int f_memo(int i,int buy,vector<int>&a,vector<vector<int>>&dp){
    if(i>=a.size()){
        return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    if(buy){
         dp[i][buy] = max(-a[i]+f_memo(i+1,0,a,dp),f_memo(i+1,1,a,dp));
    }else{
        dp[i][buy] = max(a[i]+f_memo(i+2,1,a,dp),f_memo(i+1,0,a,dp));
    }
    return dp[i][buy];
}
//space O((n+2)*2)  TC= O(n*2) tabulation
int maxProfit(vector<int>&a) {
    int n = a.size();
    vector<vector<int>>dp(n+2,vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            if(buy){
                dp[i][buy] = max(-a[i]+dp[i+1][0],dp[i+1][1]);
            }else{
                dp[i][buy] = max(a[i]+dp[i+2][1],dp[i+1][0]);
            }
        }
    }
    return dp[0][1];
}
// we can omit the second for loop as buy can 
//either have 0 or 1 as value space O(2 + (n+2))  TC= O(n)
int maxProfit(vector<int>&a) {
    int n = a.size();
    vector<vector<int>>dp(n+2,vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
            dp[i][1] = max(-a[i]+dp[i+1][0],dp[i+1][1]);
            dp[i][0] = max(a[i]+dp[i+2][1],dp[i+1][0]);    
    }
    return dp[0][1];
}
//space O(2*2*2)  TC= O(n) space optimisation 
int maxProfit(vector<int>&a) {
    int n = a.size();
    vector<int>front2(2,0);
    vector<int>front1(2,0);
    vector<int>curr(2,0);
    for(int i=n-1;i>=0;i--){
            curr[1] = max(-a[i]+front1[0],front1[1]);
            curr[0] = max(a[i]+front2[1],front1[0]);  
        front2 = front1;
        front1 = curr;
    }
    return curr[1];
}
int main(){
    vector<int>a;
    int n = a.size();
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return f_memo(0,1,a,dp);
    return 0;
}