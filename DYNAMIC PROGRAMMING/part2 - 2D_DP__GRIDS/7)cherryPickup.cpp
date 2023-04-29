#include<bits/stdc++.h>
#define ll long long
using namespace std;

//Time Complexity: O(N*M*M) * 9
// Space Complexity: O(N) + O(N*M*M)
int func(int i,int j1,int j2,vector<vector<int>>&a,vector<vector<vector<int>>>&dp){
    if(j1>=a[0].size() || j2>=a[0].size() || j1<0 || j2<0){
        return -1e9;
    }
    if(i==a.size()-1){
        if(j1==j2){
            return a[i][j1];
        }else{
            return a[i][j1] + a[i][j2];
        }
    }
    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }
    int maxi=-1;
    for(int di=-1;di<=1;di++){
        for(int dj=-1;dj<=1;dj++){
            int ans;
            if(j1==j2){
                ans = a[i][j1] + func(i+1,j1+di,j2+dj,a,dp);
            }else{
                ans = a[i][j1] + a[i][j2] + func(i+1,j1+di,j2+dj,a,dp);
            }
            maxi = max(maxi,ans);
        }
    }
    return dp[i][j1][j2] =  maxi;
}
int solve(int n, int m, vector<vector<int>>& grid) {
    vector<vector<vector<int>>>dp(n,vector < vector < int >> (m,vector<int>(m,-1)));
    return func(0,0,m-1,grid,dp);
} 

//Time Complexity: O(N*M*M)*9
//Space Complexity: O(N*M*M)
int solve(int n, int m, vector<vector<int>>& a) {
    vector<vector<vector<int>>>dp(n,vector < vector < int >> (m,vector<int>(m,0)));
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2){
                dp[n-1][j1][j2] = a[n-1][j1];
            }else{
                dp[n-1][j1][j2] = a[n-1][j1] + a[n-1][j2];
            }
        }
    }
    
    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxi = INT_MIN;
                for(int di=-1;di<=1;di++){
                    for(int dj=-1;dj<=1;dj++){
                        int ans=0;
                        if(j1==j2){
                            ans = a[i][j1];
                        }else{
                            ans = a[i][j1] + a[i][j2];
                        }
                        if((j1+di)>=0 && (j1+di)<m && (j2+dj)<m && (j2+dj)>=0){
                            ans += dp[i + 1][j1 + di][j2 + dj];
                        }
                        maxi = max(maxi,ans);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
            
        }
    }
    return dp[0][0][m-1];
}


// Time Complexity: O(N*M*M)*9
// Space Complexity: O(M*M)
int solve(int n, int m, vector<vector<int>>& a) {
    vector <vector< int>>front(m, vector < int > (m, 0)),curr(m,vector<int>(m, 0));
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2){
                front[j1][j2] = a[n-1][j1];
            }else{
                front[j1][j2] = a[n-1][j1] + a[n-1][j2];
            }
        }
    }
    
    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxi = INT_MIN;
                for(int di=-1;di<=1;di++){
                    for(int dj=-1;dj<=1;dj++){
                        int ans=0;
                        if(j1==j2){
                            ans = a[i][j1];
                        }else{
                            ans = a[i][j1] + a[i][j2];
                        }
                        if((j1+di)>=0 && (j1+di)<m && (j2+dj)<m && (j2+dj)>=0){
                            ans += front[j1 + di][j2 + dj];
                        }
                        maxi = max(maxi,ans);
                    }
                }
                curr[j1][j2] = maxi;
            }
            
        }
        front = curr;
    }
    return front[0][m-1];
}
int main(){
    
    return 0;
}