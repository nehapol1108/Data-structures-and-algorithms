#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N*target) SC->O(N*target) + O(N)
//memoization
bool func(vector<int>&a,int target,int i,vector<vector<int>>&dp){
    if(target==0)return true;
    if(i==0){
        return (a[0]==target?true:false);
    }
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    bool not_take = func(a,target,i-1,dp);
    bool take = false;
    if(target>=a[i]){
        take = func(a,target-a[i],i-1,dp);
    }
    return dp[i][target] = take || not_take;
}
bool isSubsetSum(vector<int>a, int sum){
    int n = a.size();
    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    return func(a,sum,n-1,dp);
} 

//TC->O(N*target) SC->O(N*target)
//tabulation
bool isSubsetSum(vector<int>a, int sum){
    int n = a.size();
    vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    if(a[0]<=sum){
        dp[0][a[0]]=true;   
    }
    
    for(int i=1;i<n;i++){
        for(int target =0 ;target<=sum;target++){
            bool not_take = dp[i-1][target];
            bool take = false;
            if(target>=a[i]){
                take = dp[i-1][target-a[i]];
            }
            dp[i][target] = take || not_take;
        }
    }
    return dp[n-1][sum];
}

//TC->O(N*target) SC->O(target)
//space optimization
bool isSubsetSum(vector<int>a, int sum){
    int n = a.size();
    vector<bool>prev(sum+1,0),curr(sum+1,0);
    prev[0]=true,curr[0]=true;
    if(a[0]<=sum){
        prev[a[0]]=true;   
    }
    for(int i=1;i<n;i++){
        for(int target =0 ;target<=sum;target++){
            bool not_take = prev[target];
            bool take = false;
            if(target>=a[i]){
                take = prev[target-a[i]];
            }
            curr[target] = take || not_take;
        }
        prev=curr;
    }
    return prev[sum];
}
int main(){
    
    return 0;
}