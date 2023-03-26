#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(2^N) SC->O(N) for strings
//method 1
void get_ss(string s,string ans){
    if(s.size()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string rem = s.substr(1);
    get_ss(rem,ans+ch);
    get_ss(rem,ans+"");
} 
//method 2 for strings 
void get_ss(string s,string ans,int i){
    if(i==s.size()){
        cout<<ans<<endl;
        return;
    }
    char ch = s[i];
    string op1 = ans;
    string op2 = ans;
    op2.push_back(ch);
    get_ss(s,op1,i+1);
    get_ss(s,op2,i+1);
} 


//for array 
// https://leetcode.com/problems/subsets/
//TC->O(2^N) SC->O(N)
void getss(vector<int>&a,int i,vector<vector<int>>&ans,vector<int>op){
    if(i==a.size()){
        ans.push_back(op);
        return;
    }
    vector<int>op1 = op;
    vector<int>op2 = op;
    op2.push_back(a[i]);
    getss(a,i+1,ans,op1);
    getss(a,i+1,ans,op2);
}
vector<vector<int>> subsets(vector<int>&a) {
    vector<int>op;
    vector<vector<int>>ans;
    getss(a,0,ans,op);
    return ans;
}
int main(){
    
    return 0;
}