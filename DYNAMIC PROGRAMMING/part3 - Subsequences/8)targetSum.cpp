#include<bits/stdc++.h>
#define ll long long
using namespace std;


//TC->O(N*target) SC->O(target)
//space optimization
int mod = 1e9+7;
int findTargetSumWays(vector<int>&a ,int d) {
    int n=a.size();
        int sum1 = accumulate(a.begin(),a.end(),0);
    if((sum1-d)<0 || (sum1-d)%2!=0){
        return 0;
    }
    int sum = (sum1-d)/2;
    vector<int>prev(sum+1,0),curr(sum+1,0);
    for(int i=0;i<=sum;i++){
        if(a[0]==0 && i==0){
            prev[i]=2;
        }else if(i==0 || a[0]==i){
            prev[i]=1;
        }
    }
    
    for(int i=1;i<n;i++){
        for(int target = 0;target<=sum;target++){
            int nttake = prev[target]%10000000007;
            int take =0;
            if(target>=a[i]){
                take = prev[target-a[i]]%10000000007;
            }
            curr[target]=(take%mod+nttake%mod)%mod ;
        }
        prev = curr;
    }
    return prev[sum]%mod;
} 
int main(){
    
    return 0;
}