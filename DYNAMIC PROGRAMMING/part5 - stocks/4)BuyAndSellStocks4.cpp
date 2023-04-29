#include<bits/stdc++.h>
#define ll long long
using namespace std;
//space O(n) TC= exponential as every function call other two function gives tle
int f(int i,int transc,vector<int>&a,int k){
    if(transc==2*k || i==a.size()){
        return 0;
    }
    int profit=0;
    if(transc%2==0){
        profit = max(-a[i]+f(i+1,transc+1,a,k),f(i+1,transc,a,k));
    }else{
        profit = max(a[i]+f(i+1,transc+1,a,k),f(i+1,transc,a,k));
    }
    return profit;
}
//space O(n) + O(n*(k*2)) TC= O(n*(k*2)) memoization
int f(int i,int transc,vector<int>&a,vector<vector<int>>&dp,int k){
    if(transc==2*k || i==a.size()){
        return 0;
    }
    if(dp[i][transc]!=-1){
        return dp[i][transc];
    }
    if(transc%2==0){
         dp[i][transc] = max(-a[i]+f(i+1,transc+1,a,dp,k),f(i+1,transc,a,dp,k));
    }else{
        dp[i][transc] = max(a[i]+f(i+1,transc+1,a,dp,k),f(i+1,transc,a,dp,k));
    }
    return dp[i][transc];
}
//space O(n*(k*2+1))  TC= O(n*(k*2)) tabulation
 int maxProfit(int k, vector<int>&a) {
        int n = a.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        //base cases nhi likhe toh bhi chalega as initially only all values are 0
        for(int i=n-1;i>=0;i--){
            for(int transc=2*k-1;transc>=0;transc--){
                if(transc%2==0){
                     dp[i][transc] = max(-a[i]+dp[i+1][transc+1],dp[i+1][transc]);
                }else{
                    dp[i][transc] = max(a[i]+dp[i+1][transc+1],dp[i+1][transc]);
                }
            }
        }
        return dp[0][0];
    }
//space O(k*2+1)  TC= O(n*2k+1) space optimisation
int maxProfit(int k, vector<int>&a) {
    int n = a.size();
    vector<int>ahead(2*k+1,0),curr(2*k+1,0);
    //base cases nhi likhe toh bhi chalega as initially only all values are 0
    for(int i=n-1;i>=0;i--){
        for(int transc=2*k-1;transc>=0;transc--){
            if(transc%2==0){
                    curr[transc] = max(-a[i]+ahead[transc+1],ahead[transc]);
            }else{
                curr[transc] = max(a[i]+ahead[transc+1],ahead[transc]);
            }
        }
        ahead = curr;
    }
    return ahead[0];
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>>dp(n,vector<int>(2*k,-1));
    vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
    vector<int>ahead(2*k+1,0),curr(2*k+1,0);
    return 0;
} 