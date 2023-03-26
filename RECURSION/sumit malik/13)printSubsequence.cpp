#include<bits/stdc++.h>
#define ll long long
using namespace std;
//there are total 2^n subsequences
//and 2^n / 2 = 2^n-1 pairs
// in every pair there are 3 characters
//therefore memory required subsequences for n length string = 2^n-1 * n bytes

void printSS(string s,int i,string ans){
    if(i==s.size()){
        cout<<ans<<endl;
        return;
    }
    printSS(s,i+1,ans+s[i]);
    printSS(s,i+1,ans+"");
}
int main(){
    string ans="";
    printSS("abc",0,ans);
    return 0;
}