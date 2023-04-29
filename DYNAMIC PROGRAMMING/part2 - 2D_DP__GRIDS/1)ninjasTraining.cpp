#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N*4*3) SC->O(N)+O(4*N)
//memoization
int func(int day,int last,vector<vector<int>>& points,vector<vector<int>>& dp){
    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi = max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1){
        return dp[day][last];
    }
    int maxi= 0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int point = points[day][task] + func(day-1,task,points,dp);
            maxi = max(maxi,point);
        }
    }
    return dp[day][last] = maxi;
}
int maximumPoints(vector<vector<int>>& points, int n) {
    // Code here
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return func(n-1,3,points,dp);
}

//tabulation
//TC->O(N*3*4) SC->O(N*4)
int maximumPoints(vector<vector<int>>&a, int n) {
    // Code here
    vector<vector<int>>dp(n,vector<int>(4,0));
    dp[0][0] = max(a[0][1],a[0][2]);
    dp[0][1] = max(a[0][0],a[0][2]);
    dp[0][2] = max(a[0][0],a[0][1]);
    dp[0][3] = max(a[0][1],max(a[0][2],a[0][0]));
    
    for(int day=1;day<n;day++){
        
        for(int last=0;last<4;last++){
            int maxi=0;
            dp[day][last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int point = a[day][task] + dp[day-1][task];
                    
                    maxi = max(maxi,point);
                }
            }
                dp[day][last]=max(dp[day][last],maxi);
        }
        
    }
    return dp[n-1][3];
}

//TC->O(N*4*3)
// SC->O(4)
int maximumPoints(vector<vector<int>>&a, int n) {
    // Code here
    vector<int>prev(4,0);
    prev[0] = max(a[0][1],a[0][2]);
    prev[1] = max(a[0][0],a[0][2]);
    prev[2] = max(a[0][0],a[0][1]);
    prev[3] = max(a[0][1],max(a[0][2],a[0][0]));
    
    for(int day=1;day<n;day++){
        vector<int>temp(4,0);
        for(int last=0;last<4;last++){
            int maxi=0;
            temp[last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int point = a[day][task] + prev[task];
                    
                    maxi = max(maxi,point);
                }
            }
                temp[last]=max(temp[last],maxi);
        }
        prev = temp;
        
    }
    return prev[3];
}
int main(){
    
    return 0;
}