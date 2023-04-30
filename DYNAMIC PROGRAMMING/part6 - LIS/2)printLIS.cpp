#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N^2) + O(length of LIS)
//SC->O(2N)
void printLIS(ll *a,ll n){
    vector<int>dp(n+1,1),hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for(int i=0;i<n;i++){
        hash[i] = i;
        for(int prev=0;prev<i;prev++){
            if(a[prev]<a[i] && (1+dp[prev])>dp[i]){
                dp[i] = 1+dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i]>maxi){
            maxi= dp[i];
            lastIndex = i;
        }
    }
    vector<int>temp;
    temp.push_back(a[lastIndex]);
    while(hash[lastIndex]!=lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(a[lastIndex]);
    }
    reverse(temp.begin(),temp.end());
    for(auto i:temp){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    
    return 0;
}