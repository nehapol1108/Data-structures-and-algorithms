#include<bits/stdc++.h>
#define ll long long
using namespace std;

//Iterative soln 
//T.C -> O(n)
//S.C -> O(1)
ll factorial(ll n){
    ll res=1;
    for(ll i=2;i<=n;i++){
        res=res*i;
    }
    return res;
}

//Recursion soln 
//T.C -> O(n)
//S.C -> O(n)  //it will take stack
ll factorialRecursive(ll n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}
int main(){
    ll n;
    cout<<"enter n"<<endl;
    cin>>n;
    cout<<factorial(n)<<endl;
    return 0;
}