#include<bits/stdc++.h>
#define ll long long
using namespace std;


//TC->O(N^2) SC->O(N)
void insert(stack<int>&s,int temp){
    if(s.size()==0){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
}
void reverse(stack<int>&s){
    if(s.size()<=1){
        return;
    }
    int temp = s.top();
    s.pop();
    reverse(s);
    insert(s,temp);
}
int main(){
    stack<int>s;
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(1);
    s.push(4);
    s.push(8);

    reverse(s);
    while(s.size()>0){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}