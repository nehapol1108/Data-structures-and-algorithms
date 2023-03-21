#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.youtube.com/watch?v=_6QpiqTw_ew&ab_channel=AyushiSharma

// https://www.youtube.com/watch?v=muDPTDrpS28&ab_channel=TECHDOSE

//at any given point we need to find maximum distance it can reach
//TC->O(N) SC->O(1)
bool canJump(vector<int>& a) {
    int jumps=1,n=a.size();
    if(n<=1){
        return 1;
    }
    if(a[0]==0){
        return 0;
    }
    int maxreach=a[0];
    
    int steps=a[0];
    for(int i=1;i<n;i++){
        if(i==n-1){
            return 1;
        }
        maxreach = max(maxreach,a[i]+i);
        steps--;
        if(steps==0){
            jumps++;
            if(i>=maxreach){
                return 0;
            }
            steps = maxreach-i;
        }
    }
    
    return 0;
    } 
int main(){
    
    return 0;
}