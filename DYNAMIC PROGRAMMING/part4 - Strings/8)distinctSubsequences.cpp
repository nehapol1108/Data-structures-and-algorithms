#include<bits/stdc++.h>
#define ll long long
using namespace std;

//space O(n+m) + O(n*m) TC = O(n*m) //memoization
int func(string s,string t,int i,int j,vector<vector<int>>&dp){
    if(j<0){
        return 1;
    }
    if(i<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==t[j]){
        return dp[i][j]= func(s,t,i-1,j-1,dp) + func(s,t,i-1,j,dp);
    }
    else{
        return dp[i][j] = func(s,t,i-1,j,dp);
    }
}
int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return func(s,t,n-1,m-1,dp);
} 

//space O(n*m) TC = O(n*m) //tabulation

int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<double>>dp(n+1,vector<double>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]= dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return (int)dp[n][m];
}

//space O(m) TC = O(n*m) //space optimisation
int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<double>prev(m+1,0),curr(m+1,0);
    prev[0] = 1,curr[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                curr[j]= prev[j-1] + prev[j];
            }
            else{
                curr[j] = prev[j];
            }
        }
        prev=curr;
    }
    return (int)prev[m];
}
//space O(m) TC = O(n*m) //further space optimisation using just one array

 int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<double>prev(m+1,0);
    prev[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(s[i-1]==t[j-1]){
                prev[j]= prev[j-1] + prev[j];
            }
            else{
                prev[j] = prev[j];
            }
        }
        
    }
    return (int)prev[m];
}
int main(){
    
    return 0;
}