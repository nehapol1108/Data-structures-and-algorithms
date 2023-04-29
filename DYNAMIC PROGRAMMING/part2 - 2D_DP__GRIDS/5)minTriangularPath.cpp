#include<bits/stdc++.h>
#define ll long long
using namespace std;
//TC->O(N*N) SC->O(N*N) + O(N)
//MEMOIZATION
int func(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&a){
    
    if(i==a.size()-1){
        return a[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int right = a[i][j] + func(i+1,j+1,dp,a);
    int down =  a[i][j] + func(i+1,j,dp,a);
    return dp[i][j] =  min(right ,down);
}
int minimizeSum(int n, vector<vector<int>>& a) {
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return func(0,0,dp,a);

} 

//TC->O(N*N) (near about) SC->O(N*N) 
//TABULATION
int minimizeSum(int n, vector<vector<int>>& a) {
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int j=0;j<n;j++){
        dp[n-1][j] = a[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int right=0,down=0;
            if(i==n-1){
                dp[i][j]=a[i][j];
            }else{
                right = a[i][j] + dp[i+1][j+1];
                down =  a[i][j] + dp[i+1][j];
                dp[i][j]=min(right,down);
            }     
        }
    }
    return dp[0][0];

}

//TC->O(N*M)  SC-> O(M)
//SPACE OPTIMIZATION
int minimizeSum(int n, vector<vector<int>>& a) {
    vector<int>next(n,0);
    for(int j=0;j<n;j++){
        next[j] = a[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        vector<int>temp(n,0);
        for(int j=i;j>=0;j--){
            int right=0,down=0;
            if(i==n-1){
                temp[j]=a[i][j];
            }else{
                right = a[i][j] + next[j+1];
                down =  a[i][j] + next[j];
                temp[j]=min(right,down);
            }     
        }
        next = temp;
    }
    return next[0];

}
int main(){
    
    return 0;
}