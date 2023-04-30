#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC- O(N^2) SC->O(N)
vector<int> largestDivisibleSubset(vector<int>&a) {
    int n = a.size();
    vector<int>dp(n,1),hash(n);
    int maxi = 1;
    int lastindx=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        hash[i] = i;
        for(int prev = 0;prev<i;prev++){
            if(a[i]%a[prev]==0 && (dp[prev] + 1)>dp[i]){
                dp[i] = dp[prev] +1;
                hash[i] = prev;
            }
        }
        if(dp[i]>maxi){
            maxi = dp[i];
            lastindx = i;
        }
    }
    vector<int>ans;
    ans.push_back(a[lastindx]);
    while(hash[lastindx]!=lastindx){
        lastindx = hash[lastindx];
        ans.push_back(a[lastindx]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

   
int main(){
   
   
    return 0;
}