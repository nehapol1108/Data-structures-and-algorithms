#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N) SC->O(N)
int kthGrammar(int n, int k) {
    if(n==1 && k==1){
        return 0;
    } 
    int mid = pow(2,n-1)/2;
    if(k<=mid){
        return kthGrammar(n-1,k);
    }else{
        return !kthGrammar(n-1,k-mid);
    }
}
int main(){
    int n=4,k=8;
    cout<<kthGrammar(n,k)<<endl;
    return 0;
}