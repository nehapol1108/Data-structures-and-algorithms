#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://practice.geeksforgeeks.org/problems/prefix-to-infix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prefix-to-infix-conversion

//TC->O(N) SC->O(N)
string preToInfix(string pre) {
    // Write your code here
    reverse(pre.begin(),pre.end());
    stack<string>s;
    for(int i=0;i<pre.size();i++){
        if((pre[i]>='A' && pre[i]<='Z') || (pre[i]>='a' && pre[i]<='z')){
            string temp;
            temp.push_back(pre[i]);
            s.push(temp);
        }
        else{
            string a1 = s.top();
            s.pop();
            string a2 = s.top();
            s.pop();
            string temp;
            temp.push_back('(');
            temp+=a1;
            temp.push_back(pre[i]);
            temp+=a2;
            temp.push_back(')');
            s.push(temp);
        }
    }
    return s.top();
}
int main(){
    
    return 0;
}