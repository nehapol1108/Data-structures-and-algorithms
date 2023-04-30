#include<bits/stdc++.h>
#define ll long long
using namespace std;

//recursion  TC-> exponential SC-> O(n)
int f_recur(int i,int j,vector<int> &a){
    if(i==j){
        return 0;
    }
    int mini = 1e9;
    for(int k=i;k<j;k++){
        int steps = a[i-1]*a[k]*a[j] + f_recur(i,k,a) + f_recur(k+1,j,a);
        mini = min(mini,steps);
    }
    return mini;
}
//memoization  TC-> O(n^3) SC-> O(n) + O(n^2)
int f(int i,int j,vector<int> &a,vector<vector<int>>&dp){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini = 1e9;
    for(int k=i;k<j;k++){
        int steps = a[i-1]*a[k]*a[j] + f(i,k,a,dp) + f(k+1,j,a,dp);
        mini = min(mini,steps);
    }
    return dp[i][j] = mini;
}

int main(){
    int n;
    cin>>n;
    vector<int>a; 
    f_recur(1,n-1,a);
    return 0;
}