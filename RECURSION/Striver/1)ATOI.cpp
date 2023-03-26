#include<bits/stdc++.h>
#define ll long long
using namespace std;


void ATOI(string s,int i,int &ans){
    if(i==s.size()){
        return;
    }
    ans = ans*10 + s[i]-'0';
    ATOI(s,i+1,ans);
}
int main(){
    int ans=0;
    ATOI("123456",0,ans);
    cout<<ans<<endl;
    return 0;
}