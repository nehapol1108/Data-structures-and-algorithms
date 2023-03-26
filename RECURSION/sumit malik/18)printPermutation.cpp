#include<bits/stdc++.h>
#define ll long long
using namespace std;
void printPermutation(string s,string ans){
    if(s.size()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        string left = s.substr(0,i);
        string right = s.substr(i+1);
        printPermutation(left+right,ans+ch);
    }
} 
int main(){
    printPermutation("abc","");
    return 0;
}