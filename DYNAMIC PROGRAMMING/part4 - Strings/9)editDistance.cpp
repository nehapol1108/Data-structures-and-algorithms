#include<bits/stdc++.h>
#define ll long long
using namespace std;
//space O(n+m) TC=3^n *3^m exponential as every function call other two function gives tle O(N)*K
int f(int i,int j,string &s1,string &s2){
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(s1[i]==s2[j]){
        return f(i-1,j-1,s1,s2);
    }
    return 1 + min(f(i-1,j-1,s1,s2),min(f(i-1,j,s1,s2),f(i,j-1,s1,s2)));
}
//space O(n+m) + O(n*m) TC = O(n*m) //memoization
int f(int i,int j,string &s1,string &s2, vector<vector<int>>&dp){
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return dp[i][j] = f(i-1,j-1,s1,s2,dp);
    }
    return dp[i][j] = 1 + min(f(i-1,j-1,s1,s2,dp),min(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp)));
}
//space O(n+m) + O(n*m) TC = O(n*m) //memoization but using 1 based indexing
int f(int i,int j,string &s1,string &s2, vector<vector<int>>&dp){
    if(i==0){
        return j;
    }
    if(j==0){
        return i;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i-1]==s2[j-1]){
        return dp[i][j] = f(i-1,j-1,s1,s2,dp);
    }
    return dp[i][j] = 1 + min(f(i-1,j-1,s1,s2,dp),min(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp)));
}
//space O(n*m) TC = O(n*m) //tabulation
int minDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    return dp[n][m];
}


//space O(m) TC = O(n*m) //space optimisation
int editDistance(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<int>prev(m+1,0),curr(m+1,0);
    for(int j=0;j<=m;j++){
        prev[j] = j;
    }
    for(int i=1;i<=n;i++){
        curr[0]=i;
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                curr[j] = prev[j-1];
            }
            else {
                curr[j] =  1 + min(prev[j-1],min(curr[j-1],prev[j]));
                
            }
            
        }
        prev = curr;
    }
    return prev[m];

}

int main(){
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    
    return 0;
}