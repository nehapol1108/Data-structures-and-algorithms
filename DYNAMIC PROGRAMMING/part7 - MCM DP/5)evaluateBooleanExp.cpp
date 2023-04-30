#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
//memoization  TC-> O(n^3) SC-> O(n) + O(n^2)
int f(int i,int j,int isTrue,string a,vector<vector<vector<ll>>>&dp){
    if(i>j){return 0;}
    if(i==j){
        if(isTrue==1){
            return a[i]=='T';
        }else{
             return a[i]=='F';
        }
     }
    if(dp[i][j][isTrue]!=-1){
        return dp[i][j][isTrue];
    }
     long long ways=0;
     for(int ind = i+1;ind<=j-1;ind+=2){
            ll lt = f(i,ind-1,1,a,dp)%mod;
            ll lf = f(i,ind-1,0,a,dp)%mod;
            ll rt = f(ind+1,j,1,a,dp)%mod;
            ll rf = f(ind+1,j,0,a,dp)%mod;
           
            if(a[ind]=='&'){
                 if(isTrue){
                      ways = (ways + (lt*rt)%mod)%mod;
                 }
                 else{
                    ways = (ways + (lt*rf)%mod + (rt*lf)%mod + (rf*lf)%mod)%mod;
                }
            }else if(a[ind]=='|'){
                 if(isTrue){
                      ways = (ways +( lt*rt)%mod + (lt*rf)%mod + (rt*lf)%mod)%mod;
                 }
                 else{
                    ways = (ways + (rf*lf)%mod)%mod;
                }
            }else{
                 if(isTrue){
                      ways = (ways + (lt*rf)%mod + (lf*rt)%mod)%mod;
                 }
                 else{
                    ways =( ways + (lt*rt)%mod + (rf*lf)%mod)%mod;
                }
            }
        
    }
    return dp[i][j][isTrue] = ways;
}
int main(){
    int n;
    cin>>n;
    string a;
    int n = a.size();
    vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
    return f(0,n-1,1,a,dp);
    return 0;
}