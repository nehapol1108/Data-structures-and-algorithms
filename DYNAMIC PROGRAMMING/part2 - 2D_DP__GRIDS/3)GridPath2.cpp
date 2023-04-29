#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9+7;

//TC->O(N*M)  SC->O(N-1 + M-1) + O(N*M)
//MEMOIZATION
int func(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& grid){
    if(i<0 || j<0){
        return 0;
    }
    if(grid[i][j]==1){
        return 0;
    }
    if(i==0 && j==0){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int left =  func(i,j-1,dp,grid)%mod;
    int up =  func(i-1,j,dp,grid)%mod;
    return dp[i][j] =  (left%mod + up%mod)%mod;
}
int totalWays(int n, int m, vector<vector<int>>& grid) {
    // Code here
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return func(n-1,m-1,dp,grid)%mod;
    
} 

//TC->O(N*M)  SC-> O(N*M)
//TABULATION
int totalWays(int n, int m, vector<vector<int>>& grid) {
    // Code here
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int left=0,up=0;
            if(grid[i][j]==0 && i==0 && j==0){
                dp[i][j]=1;
            }else if(grid[i][j]==0){
                    if(j>0){
                        left =  dp[i][j-1]%mod;
                    }
                    if(i>0){
                        up =  dp[i-1][j]%mod;
                    }
                    dp[i][j]=(left%mod + up%mod)%mod;
            }
            
        }
    }
    return dp[n-1][m-1]%mod;
    
}

//TC->O(N*M)  SC-> O(M)
//SPACE OPTIMIZATION
int totalWays(int n, int m, vector<vector<int>>& grid) {
    // Code here
    vector<int>prev(m,0);
    for(int i=0;i<n;i++){
        vector<int>temp(m,0);
        for(int j=0;j<m;j++){
            int left=0,up=0;
            if(grid[i][j]==0 && i==0 && j==0){
                temp[j]=1;
            }else if(grid[i][j]==0){
                    if(j>0){
                        left =  temp[j-1]%mod;
                    }
                    if(i>0){
                        up =  prev[j]%mod;
                    }
                    temp[j]=(left%mod + up%mod)%mod;
            }
    }
    prev=temp;
}
return prev[m-1]%mod;
    
}
int main(){
    
    return 0;
}