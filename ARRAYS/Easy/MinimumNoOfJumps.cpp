// Minimum number of jumps
// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int minJumps(int a[], int n){
    if(n<=1){
        return 0;
    }
    if(a[0]==0){
        return -1;
    }
    int maxReach = a[0];
    int jumps=1;
    int step=a[0];
    for(int i=1;i<n;i++){
        if(i==n-1){
            return jumps;
        }
        maxReach = max(maxReach,a[i]+i);
        step--;
        if(step==0){
            jumps++;
            if(i>=maxReach){
                return -1;
            }
            step = maxReach-i;
        }
    }
    return -1;
}
 
int main(){
    
    return 0;
}