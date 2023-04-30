#include<bits/stdc++.h>
#define ll long long
using namespace std;
//space O(n) TC= 2^n exponential as every function call other two function gives tle
int f(int i,int prev,vector<int>&a){
    if(i==a.size()){
        return 0;
    }
    int take = 0;
    if(prev==-1 || a[prev]<a[i] ){
        take =1+ f(i+1,i,a);
    }
    int nttake = f(i+1,prev,a);
    return max(take,nttake);
}
//space O(n)+ O(n^2)  TC= O(n^2) memoization
int f(int i,int prev,vector<int>&a,vector<vector<int>>&dp){
    if(i>=a.size()){
        return 0;
    }
    if(dp[i][prev+1]!=-1){
        return dp[i][prev+1];
    }
    int nttake = f(i+1,prev,a,dp);
    int take = 0;
    if( prev==-1 || a[prev]<a[i] ){
        take =1+ f(i+1,i,a,dp);
    }
    return dp[i][prev+1] =  max(take,nttake);
} 
//space O(n^2)  TC= O(n^2) tabulation
int lengthOfLIS(vector<int>& a) {
    int n =a.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //as initially values are zero so no need to write base cases
    for(int i=n-1;i>=0;i--){
        for(int prev = i-1;prev>=-1;prev--){
            int nttake = dp[i+1][prev+1]; //we are doing here prev+1 that is not there in memo bcoz we can store value
            //of -1 in prev
            int take = 0;
            if( prev==-1 || a[prev]<a[i] ){
                take =1+ dp[i+1][i+1];
            }
            dp[i][prev+1] =  max(take,nttake);
        }
    }
    return dp[0][-1+1];
}
//space O(n)  TC= O(n^2) space optimisation
int lengthOfLIS(vector<int>& a) {
    int n =a.size();
    vector<int>next(n+1,0);
    vector<int>curr(n+1,0);
    //as initially values are zero so no need to write base cases
    for(int i=n-1;i>=0;i--){
        for(int prev = i-1;prev>=-1;prev--){
            int nttake =next[prev+1]; //we are doing here prev+1 that is not there in memo bcoz we can store value
            //of -1 in prev
            int take = 0;
            if( prev==-1 || a[prev]<a[i] ){
                take =1+ next[i+1];
            }
            curr[prev+1] =  max(take,nttake);
        }
        next = curr;
    }
    return next[-1+1];
}



int main(){
    vector<int>a;
    return f(0,-1,a);
    return 0;
}