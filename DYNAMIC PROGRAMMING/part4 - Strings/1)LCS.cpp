#include<bits/stdc++.h>
#define ll long long
using namespace std;
//space O(n+m) TC=2^n *2^n exponential as every function call other two function gives tle O(N)*K
int lcs_recur(int i,int j,string s,string t){
    if(i<0 || j<0){
        return 0;
    }
    if(s[i]==t[j]){
        return 1+ lcs_recur(i-1,j-1,s,t);
    }
    return 0 + max(lcs_recur(i-1,j,s,t),lcs_recur(i,j-1,s,t));
}
//space O(n+m) + O(n*m) TC = O(n*m) //memoization
int lcs_memo(int i,int j,string s,string t,vector<vector<int>>&dp){
    if(i==0 || j==0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i-1]==t[j-1]){
        return dp[i][j] = 1+ lcs_memo(i-1,j-1,s,t,dp);
    }
    return  dp[i][j] = 0 + max(lcs_memo(i-1,j,s,t,dp),lcs_memo(i,j-1,s,t,dp));
}
int lcs(int x, int y, string s1, string s2)
{
    
    vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
    return lcs_memo(x,y,s1,s2,dp);
}

//space O(n*m) TC = O(n*m) //tabulation
int lcs(int x, int y, string s, string t)
{
    vector<vector<int>>dp(x+1,vector<int>(y+1,0));
    for(int i=0;i<=x;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=y;j++){
        dp[0][j]=0;
    }
    
    for(int i1=1;i1<=x;i1++){
        for(int i2=1;i2<=y;i2++){
            if(s[i1-1]==t[i2-1]){
                dp[i1][i2] = 1+ dp[i1-1][i2-1];
            }else{
                dp[i1][i2] = 0 + max(dp[i1-1][i2],dp[i1][i2-1]);
            }
        }
    }
    return dp[x][y];
}

//space O(m) TC = O(n*m) //space optimisation
int longestCommonSubsequence_space(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<int>prev(m+1,0),curr(m+1,0);
    for(int j=0;j<=m;j++){
        prev[j] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    curr[j] = 1+ prev[j-1];
            }
            else{
                curr[j] = 0 + max(prev[j],curr[j-1]);
            }
        }
        prev = curr;
    }   
    return prev[m];
}



int main(){
    
    return 0;
}