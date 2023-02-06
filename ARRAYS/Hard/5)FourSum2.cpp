#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/4sum-ii/description/
int fourSumCount(vector<int>&a, vector<int>&b, vector<int>&c, vector<int>&d) {
    int res=0;
    unordered_map<int,int>m;
    for(auto i:c){
        for(auto j:d){
            m[i+j]++;
        }
    }
    for(auto i:a){
        for(auto j:b){
            res+= m[-(i+j)];
        }
    }
return res;
} 
int main(){
    
    return 0;
}