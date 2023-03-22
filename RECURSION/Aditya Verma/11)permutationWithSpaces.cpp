#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
//TC->O(N) S->O(N)
void permutationWithSpaces(string ip,string op){
    if(ip.size()==0){
        cout<<op<<" ";
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back('_');
    op2.push_back(ip[0]);
    op1.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    permutationWithSpaces(ip,op1);
    permutationWithSpaces(ip,op2);
}
int main(){
    string s="abc";
    string op = " ";
    op.push_back(s[0]);
    s.erase(s.begin()+0);
    permutationWithSpaces(s,op);
    return 0;
} 