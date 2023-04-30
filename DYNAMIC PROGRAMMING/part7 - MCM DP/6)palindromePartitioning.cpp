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
int f(int i,string s){
    if(i==s.size()){
        return 0;
    }
    int mini=INT_MAX;
    string temp="";
    for(int j=i;j<s.size();j++){
         temp.push_back(s[j]);
        if(isPalindrome(temp)){
            int cost =1+ f(j+1,s);
             mini = min(mini,cost);
        }
       
        
    }
    return mini;
}
//memoization  TC-> O(n^3) SC-> O(n) + O(n)
bool isPalindrome(int i,int j,string s){
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}
int func(string s,int i,vector<int>&dp,int n){
    if(i==n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int partition = INT_MAX;
    for(int j=i;j<n;j++){
        if(isPalindrome(i,j,s)){
            int cost = 1 + func(s,j+1,dp,n);
            partition = min(cost,partition);
        }
    }
    return dp[i] = partition;
}
int palindromicPartition(string s)
{
    // code here
    int n = s.size();
    vector<int>dp(n,-1);
    return func(s,0,dp,n)-1;
}
//Tabulation  TC-> O(n^3) SC-> O(n) 
int palindromicPartition(string s)
{
    // code here
    int n = s.size();
    vector<int>dp(n+1,0);
    for(int i=n-1;i>=0;i--){
        int partition = INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost = 1 + dp[j+1];
                partition = min(cost,partition);
            }
        }
        dp[i] = partition;
    }
    return dp[0]-1;
}
int main(){
    
    return 0;
}

