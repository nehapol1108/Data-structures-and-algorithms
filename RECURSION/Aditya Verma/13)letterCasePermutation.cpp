#include<bits/stdc++.h>
#define ll long long
using namespace std;


//TC->O(N) SC->O(N)
void letterCasePermutation(string ip,string op){
    if(ip.size()==0){
        cout<<op<<" ";
        return;
    }
    if(isdigit(ip[0])){
        string op1 = op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        letterCasePermutation(ip,op1);
    }else{
        string op1 = op;
        string op2 = op;
        op1.push_back(toupper(ip[0]));
        op2.push_back(tolower(ip[0]));
        ip.erase(ip.begin()+0);
        letterCasePermutation(ip,op1);
        letterCasePermutation(ip,op2);
    }

}
int main(){
    string s="a1B2";
    string op = " ";
    letterCasePermutation(s,op);
    return 0;
} 