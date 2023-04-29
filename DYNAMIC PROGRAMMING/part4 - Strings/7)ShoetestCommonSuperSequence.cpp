#include<bits/stdc++.h>
#define ll long long
using namespace std;
 int shortestCommonSupersequence(string s, string t, int x, int y)
{
    
    vector<vector<int>>dp(x+1,vector<int>(y+1,0));
    for(int i=0;i<=x;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=y;j++){
        dp[0][j]=0;
    }
    
    for(int i1=1;i1<=x;i1++){
        for(int i2=1;i2<=y;i2++){
            if(s[i1-1]==t[i2-1]){
                dp[i1][i2] = 1+ dp[i1-1][i2-1];
            }else{
                dp[i1][i2] = 0 + max(dp[i1-1][i2],dp[i1][i2-1]);
            }
        }
    }
    int len = (x+y)-dp[x][y];

    string ans(len,'#');
    int ind = len-1,i=x,j=y;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans[ind] = s[i-1];
            ind--;
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            ans[ind] = s[i-1];
            ind--;
            i--;
        }else{
            ans[ind] = t[j-1];
            ind--;
            j--;
        }
    }

    while(i>0){
       ans[ind] = s[i-1];
        ind--;
        i--;
    }
    while(j>0){
       ans[ind] = t[j-1];
       ind--;
       j--;
    }
    cout<<ans<<endl;
    return (x+y)-dp[x][y];
}
int main(){
    
    return 0;
}