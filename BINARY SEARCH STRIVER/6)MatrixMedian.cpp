#include<bits/stdc++.h>
#define ll long long
using namespace std;
//brute force
/*
To sort the matrix TC->O(n*m)log(n*m) SC->O(n*m)
*/ 

/*
Optimised : using Binary search 
10^9 -> approx 2^32
log2(2^32) => 32

TC->O(n*32 log2(m))
SC->O(1)
*/
int countele(vector<int>&a,int mid){
    int l=0,h=a.size()-1;
    while(l<=h){
        int md = l +(h-l)/2;
        if(a[md]<=mid){
            l = md+1;
        }else{
            h=md-1;
        }
    }
    return l;
}
int median(vector<vector<int>> &a, int n, int m){
    int l=1,h=1e9;
    while(l<=h){
        int mid = l+(h-l)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+= countele(a[i],mid);
        }
        if(cnt<=(n*m)/2){
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    return l;
}
int main(){
    
    return 0;
}