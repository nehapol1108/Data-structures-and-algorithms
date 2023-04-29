#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans=0;

//space O(n+m) + O(n*m) TC = O(n*m) //memoization
int func(string s, string t, int i,int j,vector<vector<int>>&dp){
    if(i==0 || j==0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
        func(s,t,i-1,j,dp);
        func(s,t,i,j-1,dp);
    if(s[i-1]==t[j-1]){
        dp[i][j] = 1 + func(s,t,i-1,j-1,dp);
        ans = max(ans, dp[i][j]);
        return dp[i][j];
        
    }
    return dp[i][j] = 0;
}
int longestCommonSubstr (string s, string t, int n, int m)
{
    // your code here
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    int v = func(s,t,n,m,dp);
    return ans;
} 

//space O(n*m) TC = O(n*m) //tabulation
int longestCommonSubstr (string s, string t, int n, int m)
{
    // your code here
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
            }else{
                dp[i][j]= 0;
            }
        }
    }
      return ans;
}

//space O(m) TC = O(n*m) //space optimisation

int longestCommonSubstr (string s, string t, int n, int m)
{
    // your code here
    vector<int>prev(m+1,0),curr(m+1,0);
    for(int j=0;j<=m;j++){
        prev[j]=0;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                curr[j] = 1+prev[j-1];
                ans = max(ans,curr[j]);
            }else{
                curr[j]= 0;
            }
        }
        prev = curr;
    }
    
    return ans;
}
int main(){
    
    return 0;
}