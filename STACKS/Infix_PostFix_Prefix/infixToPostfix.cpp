#include<bits/stdc++.h>
#define ll long long
using namespace std;

// https://www.youtube.com/watch?v=MxKBRgyO-94&ab_channel=Education4u
int checkPriority(char s){
    if(s=='+' || s=='-'){
        return 1;
    }else if(s=='*' || s=='/'){
        return 2;
    }
    else if(s=='^'){
        return 3;
    }
    return -1;
}
string infixToPostfix(string s) {
    string ans="";
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            ans.push_back(s[i]);
        }else if(s[i]=='('){
            st.push(s[i]);
        }else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
                
        }
        else{
            int pr = checkPriority(s[i]);
            while(!st.empty() && pr <= checkPriority(st.top())){
                char ch = st.top();
                ans.push_back(ch);
                st.pop();
            } 
            st.push(s[i]);
            
            
            
        }
    }
    while(!st.empty()){
        char ch = st.top();
        ans.push_back(ch);
        st.pop();
    }

    return ans;
} 
int evaluatePostFix(string s){
    stack<int>st;
    for(int i=0;i<s.size();i++){
       
        if(s[i]-'0'>=0 && s[i]-'0'<=9){
            st.push(s[i]-'0');
        }else{
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            char ch = s[i];
            // cout<<op1<<" "<<op2<<" "<<s[i]<<endl;
            switch (ch)
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            }
        }
    }
    return st.top();
}
int main(){
    string infix = "((2+7)*3-2)/5";
    string postfix = infixToPostfix(infix);
    cout<<postfix<<endl;
    int ans = evaluatePostFix(postfix);
    cout<<ans<<endl;

    return 0;
}