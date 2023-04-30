#include<bits/stdc++.h>
#define ll long long
using namespace std;

//recursion  TC-> exponential SC-> O(n)
int f(int i,int j,vector<int>&cuts){
    if(i>j)return 0;
    int mini = INT_MAX;
    for(int ind = i;ind<=j;ind++){
        long long cost = cuts[j+1]-cuts[i-1] + f(i,ind-1,cuts) + f(ind+1,j,cuts);
        mini = min(mini,int(cost));
    }
    return mini;
}
//memoization  TC-> O(n^3) SC-> O(n) + O(n^2)
int f(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
    if(i>j)return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini = INT_MAX;
    for(int ind = i;ind<=j;ind++){
        int cost = cuts[j+1]-cuts[i-1] + f(i,ind-1,cuts,dp) + f(ind+1,j,cuts,dp);
        mini = min(mini,cost);
    }
    return  dp[i][j] =mini;
}
int minCost(int c, vector<int>&cuts) {
    int n = cuts.size();
    vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
    cuts.push_back(c);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    return f(1,n,cuts,dp);
}
//space optimization  TC-> O(n^3) SC-> O(n^2)
 int minCost(int n, vector<int>&cuts) {
    int c = cuts.size();
    vector<vector<int>>dp(c+2,vector<int>(c+2,0));
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    for(int i=c;i>=1;i--){
        for(int j=1;j<=c;j++){
            if(i>j)continue;
            int mini = INT_MAX;
            for(int ind = i;ind<=j;ind++){
                int cost = cuts[j+1]-cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                mini = min(mini,cost);
            }
            dp[i][j] =mini;
        }
    }
    return dp[1][c];
}

int main(){
    vector<int>cuts;
    int n;
    int c = cuts.size();
    vector<vector<int>>dp(c+2,vector<int>(c+2,0));
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    f(1,n,cuts);
    return 0;
}