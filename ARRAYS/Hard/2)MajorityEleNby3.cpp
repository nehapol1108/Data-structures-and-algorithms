#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Solution 1: Brute-Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)
vector<int> majorityElement(vector<int>&a) {
    unordered_map<int,int>m;
    int n=a.size();
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }
    vector<int>ans;
    for(auto i:m){
        if(i.second>(n/3)){
            ans.push_back(i.first);
        }
    }
    return ans;
}


//solution 2: Most voting algo
// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> majorityElement(vector<int>&a) {
    int n=a.size();
    vector<int>ans;

    int n1=-1,n2=-1,c1=0,c2=0;
    for(int i=0;i<n;i++){
        if(n1==a[i]){
            c1++;
        }else if(n2==a[i]){
            c2++;
        }else if(c1==0){
            n1=a[i];
            c1=1;
        }else if(c2==0){
            n2=a[i];
            c2=1;
        }else{
            c1--;
            c2--;
        }
    }
    c1=0,c2=0;
    for(int i=0;i<n;i++){
        if(n1==a[i]){
            c1++;
        }else if(n2==a[i]){
            c2++;
        }
    }
    if(c1>(n/3)){
        ans.push_back(n1);
    }
    if(c2>(n/3)){
        ans.push_back(n2);
    }
    return ans;
}
int main(){
    
    return 0;
}