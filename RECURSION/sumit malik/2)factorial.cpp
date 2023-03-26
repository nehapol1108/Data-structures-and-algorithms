#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N) SC->O(N)
int factorial(int n){
    if(n==1){
        return 1;
    }
    return n*factorial(n-1);
}
int main(){
    cout<<factorial(4)<<endl;
    return 0;
}