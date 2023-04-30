#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC- O(N^2) SC->O(N)
int longestBitonicSequence(vector<int>& a, int n) {
	  // Write your code here.
    vector<int>dp(n,1);
    vector<int>dp2(n,1);
    for(int i=0;i<n;i++){
        for(int prev = 0;prev<i;prev++){
            if(a[i]>a[prev] && (dp[prev] + 1)>dp[i]){
                dp[i] = dp[prev] +1;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int prev = n-1;prev>i;prev--){
            if(a[i]>a[prev] && (dp2[prev] + 1)>dp2[i]){
                dp2[i] = dp2[prev] +1;  
            }
        }
    }
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        maxi = max(maxi,dp[i]+dp2[i]-1);
    }
    return maxi;
} 

   
int main(){
   
   
    return 0;
}