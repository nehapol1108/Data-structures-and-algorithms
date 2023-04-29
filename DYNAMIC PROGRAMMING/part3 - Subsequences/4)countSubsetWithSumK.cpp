#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9+7;
//TC->O(N*target) SC->O(N*target) + O(N)
//tabulation
int summ(int a[],int i,int sum,vector<vector<int>>&dp){
    
    if(i==0){
        if(sum==0 && a[0]==0){
            return dp[i][sum]=2; //take and not take 
        }
        if(sum==0 || a[0]==sum){
            return dp[i][sum]=1;  //take
        }
        return dp[i][sum]=0;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum]%mod;
    }
    int nttake = summ(a,i-1,sum,dp)%mod;
        int take =0;
    if(sum>=a[i]){
        take = summ(a,i-1,(sum-a[i])%10000000007,dp)%mod;
    }
    return  dp[i][sum]=(take%mod+nttake%mod)%mod ;
    
}
int perfectSum(int arr[], int n, int sum)
{
    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    //sort(a,a+n);
    return summ(arr,n-1,sum,dp)%mod;
} 

int mod = 1e9+7;
//TC->O(N*target) SC->O(N*target)
//tabulation
int perfectSum(int a[], int n, int sum)
{
    vector<vector<int>>dp(n,vector<int>(sum+1,0));
    for(int i=0;i<=sum;i++){
        if(a[0]==0 && i==0){
            dp[0][i]=2;
        }else if(i==0 || a[0]==i){
            dp[0][i]=1;
        }
    }
    
    for(int i=1;i<n;i++){
        for(int target = 0;target<=sum;target++){
            int nttake = dp[i-1][target]%10000000007;
            int take =0;
            if(target>=a[i]){
                take = dp[i-1][target-a[i]]%10000000007;
            }
            dp[i][target]=(take%mod+nttake%mod)%mod ;
        }
    }
    return dp[n-1][sum]%mod;
}
//TC->O(N*target) SC->O(target)
//space optimization
int perfectSum(int a[], int n, int sum)
{
    vector<int>prev(sum+1,0),curr(sum+1,0);
    for(int i=0;i<=sum;i++){
        if(a[0]==0 && i==0){
            prev[i]=2;
        }else if(i==0 || a[0]==i){
            prev[i]=1;
        }
    }
    
    for(int i=1;i<n;i++){
        for(int target = 0;target<=sum;target++){
            int nttake = prev[target]%10000000007;
            int take =0;
            if(target>=a[i]){
                take = prev[target-a[i]]%10000000007;
            }
            curr[target]=(take%mod+nttake%mod)%mod ;
        }
        prev = curr;
    }
    return prev[sum]%mod;
}
int main(){
    
    return 0;
}