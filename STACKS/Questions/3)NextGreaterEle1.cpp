#include<bits/stdc++.h>
#define ll long long
using namespace std;

// https://www.youtube.com/watch?v=Du881K7Jtk8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=76&ab_channel=takeUforward
//TC->O(N) SC->O(N)
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& a) {
    stack<int>s;
    vector<int>ans;
    unordered_map<int,int>m;
    for(int i=a.size()-1;i>=0;i--){
        while(!s.empty() && s.top()<=a[i]){
            s.pop();
        }
        if(s.empty()){
            m[a[i]] = -1;
        }else{
                m[a[i]] = s.top();
        }
        s.push(a[i]);
    }
    for(auto i:nums1){
        ans.push_back(m[i]);
    }
    return ans;
}
int main(){
    
    return 0;
}