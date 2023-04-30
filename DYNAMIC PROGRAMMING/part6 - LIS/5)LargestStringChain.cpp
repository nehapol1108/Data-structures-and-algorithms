#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool checkPossible(string &s1,string &s2){
    if(s1.size()-1 !=s2.size()){
        return false;
    }
    int first = 0;
    int second =0;
    while(first<s1.size()){
        if(s1[first]==s2[second]){
            first++;
            second++;
        }else{
            first++;
        }
    }
    if(first==s1.size() && second == s2.size()){
        return true;
    }
    return false;
}
bool comp(string &s1,string &s2){
    return s1.size()<s2.size();
}

//tc - > O(n^2 * length of s1) + nlog(n) fr sorting SC-> O(n)
int longestStrChain(vector<string>&a) {
    int n = a.size();
    sort(a.begin(),a.end(),comp);
    vector<int>dp(n,1);
    int maxi=1;
    for(int i=0;i<n;i++){
        for(int prev = 0;prev<i;prev++){
            if(checkPossible(a[i],a[prev]) && (1+dp[prev])>dp[i]){
                dp[i] = 1+dp[prev];
            }
        }
        maxi = max(maxi,dp[i]);
    }
    return maxi;
} 
int main(){
   
   
    return 0;
}