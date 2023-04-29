#include<bits/stdc++.h>
#define ll long long
using namespace std;
//space O(n) TC= exponential as every function call other two function gives tle
int f(int i,int buy,int cap,vector<int>&a){
    if(cap==0){
        return 0;
    }
    if(i==a.size()){
        return 0;
    }
    int profit=0;
    if(buy){
         profit = max(-a[i]+f(i+1,0,cap,a),f(i+1,1,cap,a));
    }else{
        profit = max(a[i]+f(i+1,1,cap-1,a),f(i+1,0,cap,a));
    }
    return profit;
}
//space O(n) + O(n*2*3) TC= O(n*2*3) memoization
int f(int i,int buy,int cap,vector<int>&a,vector<vector<vector<int>>>&dp){
    if(cap==0){
        return 0;
    }
    if(i==a.size()){
        return 0;
    }
    if(dp[i][buy][cap]!=-1){
        return dp[i][buy][cap];
    }
    int profit=0;
    if(buy){
         dp[i][buy][cap] = max(-a[i]+f(i+1,0,cap,a,dp),f(i+1,1,cap,a,dp));
    }else{
        dp[i][buy][cap] = max(a[i]+f(i+1,1,cap-1,a,dp),f(i+1,0,cap,a,dp));
    }
    return dp[i][buy][cap];
}
int maxProfit(vector<int>&a){
    int n = a.size();
   vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
   return f(0,1,2,a,dp);
}
//space O(n*2*3)  TC= O(n*2*3) tabulation
int maxProfit(vector<int>&a) {
    int n = a.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    // base cases nhi likha toh bhi chalega bcoz initially all values are 0 only
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<2;j++){
    //         dp[i][j][0] = 0;
    //     }
    // }
    // for(int j=0;j<2;j++){
    //     for(int k =0;k<3;k++){
    //         dp[n][j][k] = 0;
    //     }       
    // }
    for(int i = n-1;i>=0;i--){
        for(int buy=0;buy<2;buy++){
            for(int cap =1;cap<3;cap++){ //as for cap = 0 ans is 0 so start from 1
                    if(buy){
                            dp[i][buy][cap] = max(-a[i]+dp[i+1][0][cap] ,dp[i+1][1][cap] );
                    }else{
                        dp[i][buy][cap] = max(a[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                    }
            }       
        }
    }
    
    return dp[0][1][2];
}
//space O(2*3)  TC= O(n*2*3) space optimisation
int maxProfit(vector<int>&a) {
    int n = a.size();
    vector<vector<int>>ahead(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
    for(int i = n-1;i>=0;i--){
        for(int buy=0;buy<2;buy++){
            for(int cap =1;cap<3;cap++){ //as for cap = 0 ans is 0 so start from 1
                    if(buy){
                            curr[buy][cap] = max(-a[i]+ahead[0][cap] ,ahead[1][cap] );
                    }else{
                        curr[buy][cap] = max(a[i]+ahead[1][cap-1],ahead[0][cap]);
                    }
            }       
        }
        ahead = curr;
    }
    
    return ahead[1][2];
}
//using n*4 matrix  memoization TC -> O(n*4) SC -> O(4*n) + O(n)
int f(int i,int transc,vector<int>&a,vector<vector<int>>&dp){
    if(transc==4 || i==a.size()){
        return 0;
    }
    if(dp[i][transc]!=-1){
        return dp[i][transc];
    }
    if(transc%2==0){
         dp[i][transc] = max(-a[i]+f(i+1,transc+1,a,dp),f(i+1,transc,a,dp));
    }else{
        dp[i][transc] = max(a[i]+f(i+1,transc+1,a,dp),f(i+1,transc,a,dp));
    }
    return dp[i][transc];
}

int main(){
    int n;
    cin>>n;
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    vector<vector<int>>ahead(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
    vector<vector<int>>dp2(n,vector<int>(4,-1));
    return 0;
}