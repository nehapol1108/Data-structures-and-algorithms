#include<bits/stdc++.h>
#define ll long long
using namespace std;

//tabulation  TC-> O(n^3) SC-> O(n^2)
int matrixMultiplication(vector<int>a, int n)
{
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=1;i<n;i++){
        dp[i][i]=0;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int mini = 1e9;
            for(int k=i;k<j;k++){
                int steps = a[i-1]*a[k]*a[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini,steps);
            }
            dp[i][j] = mini;
            
        }
    }
    return dp[1][n-1];
}
int main(){
    int n;
    cin>>n;
    vector<int>a; 
    return 0;
}