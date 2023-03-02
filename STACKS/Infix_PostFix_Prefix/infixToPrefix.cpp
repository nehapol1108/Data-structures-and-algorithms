#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
string infixToPrefix(string s) {
    string ans="";
    stack<char>st;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]==')') s[i]='(';
        else if(s[i]=='(') s[i]=')';
    }
    cout<<s<<endl;
    for(int i=0;i<s.size();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z')){
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
    reverse(ans.begin(),ans.end());
    return ans;
} 
int evaluatePreFix(string s){
    stack<int>st;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]-'0'>=0 && s[i]-'0'<=9){
            st.push(s[i]-'0');
        }else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            char ch = s[i];
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
    string infix = "(a-b/c)*(a/k-l)";
    string prefix = infixToPrefix(infix);
    cout<<prefix<<endl;
    string prefix2 = "-+7*45+20";
    int ans = evaluatePreFix(prefix2);
    cout<<ans<<endl;
    return 0;
}