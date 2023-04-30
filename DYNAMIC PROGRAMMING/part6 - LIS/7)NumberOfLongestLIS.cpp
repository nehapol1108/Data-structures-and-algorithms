#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N^2) SC->O(2N)
int NumberofLIS(int n, vector<int>&a) { 
    vector<int>dp(n,1),cnt(n,1);
    int maxi=1;
    for(int i=0;i<n;i++){
        for(int prev = 0;prev<i;prev++){
            if(a[i]>a[prev] && (1+dp[prev])>dp[i]){
                dp[i] = 1+dp[prev];
                cnt[i] = cnt[prev];
            }else if(a[i]>a[prev] && (1+dp[prev])==dp[i]){
                cnt[i] += cnt[prev];
            }
        }
        maxi = max(maxi,dp[i]);
        
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxi){
            ans+=cnt[i];
        }
    }
    
    return ans ;
} 
int main(){
    
    return 0;
}