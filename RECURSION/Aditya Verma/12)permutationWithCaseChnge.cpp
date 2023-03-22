#include<bits/stdc++.h>
#define ll long long
using namespace std;
void permutationWithCaseChnge(string ip,string op){
    if(ip.size()==0){
        cout<<op<<" ";
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back(ip[0]);
    op2.push_back(toupper(ip[0]));
    ip.erase(ip.begin()+0);
    permutationWithCaseChnge(ip,op1);
    permutationWithCaseChnge(ip,op2);
}
int main(){
    string s="abc";
    string op = " ";
    permutationWithCaseChnge(s,op);
    return 0;
} 