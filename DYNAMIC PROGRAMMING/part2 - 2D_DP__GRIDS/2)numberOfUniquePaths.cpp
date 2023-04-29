#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N*M)  SC->O(N-1 + M-1) + O(N*M)
//MEMOIZATION
int func(int i,int j,vector<vector<int>>&dp){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int left =  func(i,j-1,dp);
    int up =  func(i-1,j,dp);
    return dp[i][j] =  left + up;
}
int NumberOfPath(int a, int b)
{
    vector<vector<int>>dp(a,vector<int>(b,-1));
    return func(a-1,b-1,dp);
} 

//TC->O(N*M)  SC-> O(N*M)
//TABULATION
int NumberOfPath(int a, int b)
{
    vector<vector<int>>dp(a,vector<int>(b,0));
    
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            int left=0,up=0;
            if(i==0 && j==0){
                dp[i][j]=1;
            }else{
                    if(j>0){
                    left =  dp[i][j-1];
                }
                if(i>0){
                    up =  dp[i-1][j];
                }
                
            dp[i][j]=up+left;
            
            }
            
        }
    }
    return dp[a-1][b-1];
}

//TC->O(N*M)  SC-> O(M)
//SPACE OPTIMIZATION
int NumberOfPath(int a, int b)
{
    
    vector<int>prev(b,0);
    for(int i=0;i<a;i++){
        vector<int>temp(b,0);
        for(int j=0;j<b;j++){
            int left=0,up=0;
            if(i==0 && j==0){
                temp[j]=1;
            }else{
                    if(j>0){
                    left =  temp[j-1];
                }
                if(i>0){
                    up =  prev[j];
                }
                
                temp[j]=up+left;
            
            }
            
        }
        prev=temp;
    }
    return prev[b-1];
}
int main(){
    
    return 0;
}