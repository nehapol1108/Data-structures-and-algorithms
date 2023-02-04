#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool ispar(string &x)
{
    stack<char>s;
    for(int i=0;i<x.size();i++){
        if(x[i]=='(' || x[i]=='{' || x[i]=='[' ){
            s.push(x[i]);
        }else{
            if(s.empty())return false;
            char c = s.top();
            s.pop();
            if(x[i]==')' && c!='('){
                return false;
            }else if(x[i]==']' && c!='['){
                return false;
            }else if(x[i]=='}' && c!='{'){
                return false;
            }
        }
    }
    if(!s.empty())return false;
    return true;
}
int main(){
    string s;
    cin>>s;
    bool ans = ispar(s);
    cout<<ans<<endl;
    return 0;
}