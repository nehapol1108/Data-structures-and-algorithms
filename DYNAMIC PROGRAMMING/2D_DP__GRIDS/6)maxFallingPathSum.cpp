#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N*N)(more than this) SC->O(N*N) + O(N)
//MEMOIZATION
int func(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&a){
    if(i>=a.size() || j>=a.size() || i<0 || j<0){
        return 0;
    }
    if(i==0){
        return a[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int upper = a[i][j] + func(i-1,j,dp,a);
    int ld =  a[i][j] + func(i-1,j-1,dp,a);
    int rd =  a[i][j] + func(i-1,j+1,dp,a);
    return dp[i][j] =  max(upper,max(ld,rd));
}
int maximumPath(int n, vector<vector<int>> a)
{
    vector<vector<int>>dp(n,vector<int>(n,-1));
    int maxi = 0;
    for(int i=a.size()-1;i>=0;i--){
        int result = func(a.size()-1,i,dp,a);
        maxi = max(maxi,result);
    }
    return maxi;

}

//TC->O(N*N)(more than this) SC->O(N*N) 
//TABULATION
int maximumPath(int n, vector<vector<int>> a)
{
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int j=0;j<n;j++){
        dp[0][j] = a[0][j];
    }
    int maxi = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int ld = 0,rd = 0;
            int up = a[i][j] + dp[i-1][j];
            if((j-1)>=0){
                ld =  a[i][j] + dp[i-1][j-1];
            }
            if((j+1)<n){
                rd =  a[i][j] + dp[i-1][j+1];
            }
            dp[i][j] = max(up,max(ld,rd));
        }
    }
    int ans = dp[n-1][0];
    for(int j=0;j<n;j++){
        ans = max(ans,dp[n-1][j]);
    }
    return ans;
}

//TC->O(N*N)(more than this) SC->O(N) 
//TABULATION
int maximumPath(int n, vector<vector<int>> a)
{
    vector<int>prev(n,0);
    for(int j=0;j<n;j++){
        prev[j] = a[0][j];
    }
    int maxi = 0;
    for(int i=1;i<n;i++){
        vector<int>temp(n,0);
        for(int j=0;j<n;j++){
            int ld = 0,rd = 0;
            int up = a[i][j] + prev[j];
            if((j-1)>=0){
                ld =  a[i][j] + prev[j-1];
            }
            if((j+1)<n){
                rd =  a[i][j] + prev[j+1];
            }
            temp[j] = max(up,max(ld,rd));
        }
        prev = temp;
    }
    int ans =prev[0];
    for(int j=0;j<n;j++){
        ans = max(ans,prev[j]);
    }
    return ans;
}
int main(){
    
    return 0;
}