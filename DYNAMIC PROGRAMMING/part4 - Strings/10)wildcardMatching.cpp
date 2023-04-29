#include<bits/stdc++.h>
#define ll long long
using namespace std;
//space O(n+m) TC=exponential as every function call other two function gives tle O(N)*K
int f(int i,int j,string &s,string &t){
    if(i<0 && j<0){
        return true;
    }
    if(i<0 && j>=0){
        return false;
    }
    if(j<0 && i>=0){
        for(int k =0;k<=i;k++){
            if(s[k]!='*'){
                return false;
            }
        }
        return true;
    }
    if(s[i]==t[j] || s[i]=='?'){
        return f(i-1,j-1,s,t);
    }
    if(s[i]=='*'){
        return f(i-1,j,s,t) | f(i,j-1,s,t);
    }
    return false;
}
//space O(n+m) + O(n*m) TC = O(n*m) //memoization
int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(i<0 && j<0){
        return true;
    }
    if(i<0 && j>=0){
        return false;
    }
    if(j<0 && i>=0){
        for(int k =0;k<=i;k++){
            if(s[k]!='*'){
                return false;
            }
        }
        return true;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==t[j] || s[i]=='?'){
        return dp[i][j] = f(i-1,j-1,s,t,dp);
    }
    if(s[i]=='*'){
        return dp[i][j] = f(i-1,j,s,t,dp) | f(i,j-1,s,t,dp);
    }
    return false;
}
//space O(n+m) + O(n*m) TC = O(n*m) //memoization for 1 based indexing to convert into tabu
int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(i==0 && j==0){
        return true;
    }
    if(i==0 && j>0){
        return false;
    }
    if(j==0 && i>0){
        for(int k =1;k<=i;k++){
            if(s[k-1]!='*'){
                return false;
            }
        }
        return true;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i-1]==t[j-1] || s[i-1]=='?'){
        return dp[i][j] = f(i-1,j-1,s,t,dp);
    }
    if(s[i-1]=='*'){
        return dp[i][j] = f(i-1,j,s,t,dp) | f(i,j-1,s,t,dp);
    }
    return false;
}

//space O(n*m) TC = O(n*m) //tabulation
 bool isMatch(string t, string s) {
        int m = t.size();
        int n = s.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int j=1;j<=m;j++){
            dp[0][j] = false;
        }
        for(int i=0;i<=n;i++){
            bool flag = true;
            for(int k =1;k<=i;k++){
                if(s[k-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1] || s[i-1]=='?'){
                   dp[i][j] = dp[i-1][j-1];
                }
                else if (s[i-1]=='*'){
                    dp[i][j] = dp[i][j-1] | dp[i-1][j];
                }else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }


//space O(m) TC = O(n*m) //space optimisation
bool isMatch(string t, string s) {
    int m = t.size();
    int n = s.size();
    vector<bool>prev(m+1,false),curr(m+1,false);
    prev[0] = true;
    for(int j=1;j<=m;j++){
        prev[j] = false;
    }
    for(int i=1;i<=n;i++){
        bool flag = true;
        for(int k =1;k<=i;k++){
            if(s[k-1]!='*'){
                flag=false;
                break;
            }
        }
        curr[0] = flag;
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1] || s[i-1]=='?'){
                curr[j] = prev[j-1];
            }
            else if (s[i-1]=='*'){
                curr[j] = curr[j-1] | prev[j];
            }else{
                curr[j] = false;
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