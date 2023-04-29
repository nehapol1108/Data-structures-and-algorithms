#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9+7;

//TC->O(N*M)  SC->O(N-1 + M-1) + O(N*M)
//MEMOIZATION
int func(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& grid){
        
    if(i==0 && j==0){
        return grid[i][j];
    }
    if(i<0 || j<0){
        return 1e9;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int left = grid[i][j] + func(i,j-1,dp,grid);
    int up =  grid[i][j] + func(i-1,j,dp,grid);
    return dp[i][j] =  min(left ,up);
}
int minPathSum(vector<vector<int>>& a) {
    int m = a.size();
    int n=a[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(m-1,n-1,dp,a);

}

//TC->O(N*M)  SC-> O(N*M)
//TABULATION
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int left=0,up=0;
            if(i==0 && j==0){
                dp[i][j]=grid[i][j] ;
            }else{
                if(j>0){
                    left =  grid[i][j] +  dp[i][j-1]%mod;
                }else{
                    left=1e9;
                }
                if(i>0){
                    up = grid[i][j] + dp[i-1][j]%mod;
                }else{
                    up=1e9;
                }
                dp[i][j]=min(left,up);
            }     
        }
    }
    return dp[n-1][m-1]%mod;

}

//TC->O(N*M)  SC-> O(M)
//SPACE OPTIMIZATION
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m=grid[0].size();
    vector<int>prev(m,0);
    for(int i=0;i<n;i++){
        vector<int>temp(m,0);
        for(int j=0;j<m;j++){
            int left=0,up=0;
            if(i==0 && j==0){
                temp[j]=grid[i][j] ;
            }else{
                if(j>0){
                    left =  grid[i][j] +  temp[j-1]%mod;
                }else{
                    left=1e9;
                }
                if(i>0){
                    up = grid[i][j] + prev[j]%mod;
                }else{
                    up=1e9;
                }
                temp[j]=min(left,up);
            }  
                
        }
            prev = temp; 
    }
    return prev[m-1]%mod;

}
int main(){
    
    return 0;
}

