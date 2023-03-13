#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N+N) SC->O(N)
// https://www.youtube.com/watch?v=88mGJqbnPVw&t=581s&ab_channel=codeExplainer
int func(vector<int>a,int k){
    int i=0,j=0,n=a.size();
    unordered_map<int,int>m;
    int count=0;
    while(j<n){
        m[a[j]]++;
        while(m.size()>k){
            m[a[i]]--;
            if(m[a[i]]==0){
                m.erase(a[i]);
            }
            i++;
        }
        count+=(j-i+1);
        j++;
    }
    return count;
}
int subarraysWithKDistinct(vector<int>&a, int k) {
    return func(a,k)-func(a,k-1);
} 
int main(){
    
    return 0;
}