#include<bits/stdc++.h>
#define ll long long
using namespace std;
void printKeyPad(string s,string ans,unordered_map<int,string>m ){
    if(s.size()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string rem  = s.substr(1);
    string code = m[ch-'0'];

    for(int i=0;i<code.size();i++){
        char ch1 = code[i];
        printKeyPad(rem,ans+ch1,m);
    }
} 
int main(){
    string digits;
    cin>>digits;
    if(digits.size()==0){
        cout<<"[]"<<endl;
    }
    unordered_map<int,string>m;
    m[2]="abc";
    m[3]="def";
    m[4]="ghi";
    m[5]="jkl";
    m[6]="mno";
    m[7]="pqrs";
    m[8]="tuv";
    m[9]="wxyz";
    string anss="";
    printKeyPad(digits,anss,m);
    return 0;
}