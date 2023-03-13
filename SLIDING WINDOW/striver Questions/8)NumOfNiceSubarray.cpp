#include<bits/stdc++.h>
#define ll long long
using namespace std;
int numberOfSubarrays(vector<int>&a, int k) {
    int n =a.size();
    unordered_map<int,int>m;
    int j=0,ans=0,sum=0;
    while(j<n){
        if(a[j]%2!=0){
            sum++;
        }
        if(sum==k){
            ans++;
        }
        if(m.find(sum-k)!=m.end()){
            ans+=m[sum-k];
        }
        m[sum]++;
        j++;
    }
    return ans;
}
int main(){
    
    return 0;
}