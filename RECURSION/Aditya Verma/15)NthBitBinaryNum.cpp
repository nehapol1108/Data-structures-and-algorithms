#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N) SC->O(N)
void solve(int one,int zero,int n,string op){
    if(n==0){
        cout<<op<<" ";
        return;
    }
    string op1 = op;
    op1.push_back('1');
    solve(one+1,zero,n-1,op1);
    if(one>zero){
        string op2 = op;
        op2.push_back('0');
        solve(one,zero+1,n-1,op2);
    }
} 
int main(){
    int n=5;
    string op="";
    int one=0,zero=0;
    solve(one,zero,n,op);
    return 0;
}