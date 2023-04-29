#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N*target) SC->O(target)
//space optimization
int minDifference(int a[], int n)  { 
    int sum = accumulate(a,a+n,0);
    vector<bool>prev(sum+1,0),curr(sum+1,0);
    prev[0]=true,curr[0]=true;
    if(a[0]<=sum){
        prev[a[0]]=true;   
    }
    for(int i=1;i<n;i++){
        for(int target =0 ;target<=sum;target++){
            bool not_take = prev[target];
            bool take = false;
            if(target>=a[i]){
                take = prev[target-a[i]];
            }
            curr[target] = take || not_take;
        }
        prev=curr;
    }
    int mini = INT_MAX;
    for(int s1=0;s1<=sum/2;s1++){
        if(prev[s1]==true){
            mini = min(mini,abs((sum-s1)-s1));
        }
    }
    return mini;
}  
int main(){
    
    return 0;
}