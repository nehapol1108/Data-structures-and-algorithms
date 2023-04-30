#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool isPalindrome(string &s)
{
    for(int i=0;i<s.length()/2;i++)
        if(s[i]!=s[s.length()-1-i])
            return 0;
    return 1;
}
//recursion  TC-> exponential SC-> O(n)
int f(int i,vector<int>& a, int k){
    int n = a.size();
    if(i==n)return 0;
    int len=0;
    int maxi=INT_MIN;
    int maxAns = INT_MIN;
    for(int j=i;j<min(i+k,n);j++){
        len++;
        maxi=max(maxi,a[j]);
        int sum = len*maxi + f(j+1,a,k);
        maxAns = max(maxAns,sum);
    }
    return maxAns;
}
//memoization  TC-> O(n*k) SC-> O(n) + O(n)
int f(int i,vector<int>& a, int k, vector<int>&dp){
    int n = a.size();
    if(i==n)return 0;
    if(dp[i]!=-1){
        return dp[i];
    }
    int len=0;
    int maxi=INT_MIN;
    int maxAns = INT_MIN;
    for(int j=i;j<min(i+k,n);j++){
        len++;
        maxi=max(maxi,a[j]);
        int sum = len*maxi + f(j+1,a,k,dp);
        maxAns = max(maxAns,sum);
    }
    return  dp[i] = maxAns;
}
//Tabulation  TC-> O(n*k) SC-> O(n) 
int maxSumAfterPartitioning(vector<int>& a, int k) {
    int n = a.size();
    vector<int>dp(n+1,0);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        int len=0;
        int maxi=INT_MIN;
        int maxAns = INT_MIN;
        for(int j=i;j<min(i+k,n);j++){
            len++;
            maxi=max(maxi,a[j]);
            int sum = len*maxi + dp[j+1];
            maxAns = max(maxAns,sum);
        }
        dp[i] = maxAns;
    }
    return dp[0];
}
int main(){
    
    return 0;
}