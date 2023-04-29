#include<bits/stdc++.h>
#define ll long long
using namespace std;

//GREEDY
//TC->O(N) SC->O(N)
static bool comp(int a,int b){
    return a>b;
}
vector<int> minPartition(int N)
{
    vector<int>v={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } ;
    sort(v.begin(),v.end(),comp);
    int n=v.size();
    int temp = N;
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(temp<=0){
            return ans;
        }
        int coins = (temp/v[i]);
        temp = temp - coins*v[i];
        if(coins>0){
            while(coins>0){
                ans.push_back(v[i]);
                coins--;
            }
        }
    }
    
    return ans;
}

//TC->O(N*target) SC->O(N*target) + O(N)
//memoization
int func(vector<int>&a,int i,vector<vector<int>>&dp,int target){
    if(i==0){
        if((target%a[0])==0){
            return target/a[0];
        }
        return 1e9;
    }
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    int nttake = func(a,i-1,dp,target);
    int take = 1e9;
    if(a[i]<=target){
        take = 1 + func(a,i,dp,target-a[i]);
    }
    return dp[i][target] = min(take,nttake);
}
int coinChange(vector<int>&v, int target) {
    int n = v.size();
    vector<vector<int>>dp(n,vector<int>(target+1,-1)); 
    return func(v,n-1,dp,target)==1e9?-1:func(v,n-1,dp,target);
}


//TC->O(N*target) SC->O(N*target)
//tabulation
int coinChange(vector<int>&a, int target) {
    int n = a.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0)); 
    for(int i=0;i<=target;i++){
        if((i%a[0])==0){
            dp[0][i]=i/a[0];
        }else{
            dp[0][i]=1e9;
        }
    }
    for(int i=1;i<n;i++){
        for(int j = 0;j<=target;j++){
            int nttake = dp[i-1][j];
            int take = 1e9;
            if(a[i]<=j){
                take = 1 + dp[i][j-a[i]];
            }
            dp[i][j] = min(take,nttake);
        }
    }
    return dp[n-1][target]==1e9?-1:dp[n-1][target];
}

//TC->O(N*target) SC->O(target)
//space optimization
int coinChange(vector<int>&a, int target) {
    int n = a.size();
    vector<int>prev(target+1,0),curr(target+1,0); 
    for(int i=0;i<=target;i++){
        if((i%a[0])==0){
            prev[i]=i/a[0];
        }else{
            prev[i]=1e9;
        }
    }
    for(int i=1;i<n;i++){
        for(int j = 0;j<=target;j++){
            int nttake = prev[j];
            int take = 1e9;
            if(a[i]<=j){
                take = 1 + curr[j-a[i]];
            }
            curr[j] = min(take,nttake);
        }
        prev=curr;
    }
    return prev[target]==1e9?-1:prev[target];
}
int main(){
    
    return 0;
}