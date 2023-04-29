

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//space O(n*m) TC = O(n*m) //tabulation
//for printing
//TC->O(N+M ) SC->O(1)
int main()
{
    string s = "abaaa";
    string t = "baabaca";
    int x = s.size();
    int y = t.size();
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
    int len = dp[x][y];

    string ans(len,'#');
    int ind = len-1,i=x,j=y;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans[ind] = s[i-1];
            ind--;
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    cout<<ans<<endl;

    return 0;
}
