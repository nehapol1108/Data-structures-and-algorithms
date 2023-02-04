#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.
int subarraySum(vector<int>& a, int k) {
    int n=a.size();
    int pre[n];
    pre[0]=a[0];
    for(int i=1;i<a.size();i++){
        pre[i]=pre[i-1]+a[i];
    }
    int ans=0;
    unordered_map<int,int>m;
    for(int i=0;i<a.size();i++){
        if(pre[i]==k){
            ans++;
        }
        else if(m.find(pre[i]-k)!=m.end()){
            ans+=m[pre[i]-k];
        }
        m[pre[i]]++;
    }
    return ans;
} 
int main(){
    
    return 0;
}