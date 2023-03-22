#include<bits/stdc++.h>
#define ll long long
using namespace std;
// The subset of a string is the character or the group of characters that are present inside the string. All the possible subsets for a string will be n(n+1)/2. For example, all possible subsets of a string "FUN" will be F, U, N, FU, UN, FUN. 

void printSubset(string ip,string op){
    if(ip.size()==0){
        cout<<op<<" ";
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    printSubset(ip,op1);
    printSubset(ip,op2);
}
int main(){
    string s="abc";
    // cin>>s;
    string op = " ";
    printSubset(s,op);
    return 0;
} 