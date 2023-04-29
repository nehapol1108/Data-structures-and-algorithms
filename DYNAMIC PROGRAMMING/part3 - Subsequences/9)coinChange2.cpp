#include<bits/stdc++.h>
#define ll long long
using namespace std;
//TC->O(N*target) SC->O(N*target) + O(N)
//memoization
long long int f(int i,int a[],int tar,vector<vector< long long int>>&dp){
    if(i==0){
        return (tar%a[0]==0);
    }
    if(dp[i][tar]!=-1){
        return dp[i][tar];
    }
    long long int nttake = f(i-1,a,tar,dp);
    long long int take=0;
    if(a[i]<=tar){
        take = f(i,a,tar-a[i],dp);
    }
    return dp[i][tar]=take+nttake;
}
long long int count(int a[], int n, int target) {
    
    vector<vector<long long int>>dp(n,vector<long long int>(target+1,-1)); 
    return f(n-1,a,target,dp) ;
} 

//TC->O(N*target) SC->O(N*target)
//tabulation
long long int count(int a[], int n, int target) {
    vector<vector<long long int>>dp(n,vector<long long int>(target+1,0)); 
    for(int i=0;i<=target;i++){
        if((i%a[0])==0){
            dp[0][i]=1;
        }else{
                dp[0][i]=0;
        }
    }
    for(int i=1;i<n;i++){
        for(int tar = 0;tar<=target;tar++){
            long long int nttake = dp[i-1][tar];
            long long int take=0;
            if(a[i]<=tar){
                take = dp[i][tar-a[i]];
            }
            dp[i][tar]=take+nttake;
        }
    }
    return dp[n-1][target];
}


//TC->O(N*target) SC->O(target)
//space optimization
long long int count(int a[], int n, int target) {
    vector<long long int>prev(target+1,0),curr(target+1,0);
    for(int i=0;i<=target;i++){
        if((i%a[0])==0){
            prev[i]=1;
        }else{
                prev[i]=0;
        }
    }
    for(int i=1;i<n;i++){
        for(int tar = 0;tar<=target;tar++){
            long long int nttake = prev[tar];
            long long int take=0;
            if(a[i]<=tar){
                take = curr[tar-a[i]];
            }
            curr[tar]=take+nttake;
        }
        prev = curr;
    }
    return prev[target];
}
int main(){
    
    return 0;
}