#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.youtube.com/watch?v=KuE_Cn3xhxI&ab_channel=TECHDOSE

//TC->O(N) SC->O(N)
 bool checkValidString(string s) {
    stack<int>star;
    stack<int>open;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            open.push(i);
        }else if(s[i]=='*'){
            star.push(i);
        }else if(s[i]==')'){
            if(open.size()>0){
                open.pop();
            }else if(star.size()>0){
                star.pop();
            }else{
                return false;
            }
        }
    }
    while(!open.empty() && !star.empty() && star.top()>open.top()){
        star.pop();
        open.pop();
    }
    while(!star.empty()){
        star.pop();
    }
    if(open.empty()){
        return true;
    }
    return false;
} 

//TC->O(N) SC->O(1) two passes
bool checkValidString(string s) {
    if(s.size()==0)return true;
    int balance =0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]==')'){
            balance--;
        }else{
            balance++;
        }
        if(balance<0)return false;
    }

    if(balance==0)return true;
    balance=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='('){
            balance--;
        }else{
            balance++;
        }
        if(balance<0)return false;
    }
    return true;
}


// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/
//Similar question like above
bool canBeValid(string s, string l) {
    if(s.size()%2!=0)return false;
    if(s.size()==0)return true;
    int balance =0,unlock=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(l[i]=='0'){
            unlock++;
        }
        else if(s[i]==')'){
            balance--;
        }else{
            balance++;
        }
        if((unlock+balance)<0)return false;
    }

    if(balance==0)return true;
    balance=0,unlock=0;
    for(int i=n-1;i>=0;i--){
        if(l[i]=='0'){
            unlock++;
        }
        else if(s[i]=='('){
            balance--;
        }else{
            balance++;
        }
        if((unlock+balance)<0)return false;
    }
    return true;
}
int main(){
    
    return 0;
}