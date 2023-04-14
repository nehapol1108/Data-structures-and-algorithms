#include<bits/stdc++.h>
#define ll long long
using namespace std;

long long int mod = 1e9+7;

//TC->O(N)  SC->O(N) + O(N)  ->stack and dp vector
//memoization
long long int f(long long int n,vector<long long>&dp){
    if(n<=1){
        return dp[n]=n%mod;
    }
    if(dp[n]!=-1){
        return dp[n]%mod;
    }
    return dp[n] = (f(n-1,dp)%mod + f(n-2,dp)%mod)%mod;
}

//TC->O(N)  SC->O(N)  -> dp vector
//tabulation
long long int bottomUp(int n) {
    // code here
    vector<long long int>dp(n+1,0);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
    }
    return dp[n]%mod;
}

//TC->O(N)  SC->O(1) 
//space optimization
long long int bottomUp(int n) {
    // code here
    int prev = 0;
    int prev2=1;
    for(int i=2;i<=n;i++){
        int curr = prev+prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int main(){
    int n;
    vector<long long>dp(n+1,-1);
    return f(n,dp)%mod;
    return 0;
}