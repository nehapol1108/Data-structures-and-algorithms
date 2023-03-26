#include<bits/stdc++.h>
#define ll long long
using namespace std;
void printEncoding(string s,string ans){
    if(s.size()==0){
        cout<<ans<<endl;
        return;
    }else if(s.size()==1){
        if(s[0]=='0'){
            return;
        }else{
            int num = s[0]-'0';
            char ch = char('a' +num - 1);
            ans = ans+ch;
            cout<<ans<<endl;
        }
    }else{
        char ch = s[0];
        string ros = s.substr(1);
        
        //for one character
        if(ch=='0'){
            return;
        }else{
            int num = ch-'0';
            char code = char('a' +num - 1);
            printEncoding(ros,ans+code);
        }

        //for two character

        string ch12 = s.substr(0,2);
        string roq = s.substr(2);
        int ch1 = stoi(ch12);
        if(ch1<=26){
            char code = char('a' + ch1- 1);
            printEncoding(roq,ans+code);
        }
    }
} 
int main(){
    string s;
    cin>>s;
    string ans="";
    printEncoding(s,ans);
    return 0;
}