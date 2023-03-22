#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N) SC-O(N)
void solve(stack<int>&s,int k){
    if(k==1){
        s.pop();
        return;
    }
    int val = s.top();
    s.pop();
    solve(s,k-1);
    s.push(val);
}
int main(){
    stack<int>s;
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(1);
    s.push(4);
    s.push(3);
    int k = s.size()/2 +1;
    solve(s,k);
    while(s.size()>0){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}