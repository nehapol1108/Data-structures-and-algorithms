#include<bits/stdc++.h>
#define ll long long;
#define mod 1000000007
using namespace std;
//TC->O(N) SC->O(N)
int power(int x,int n){
    if(n==0){
        return 1;
    }
    return x*power(x,n-1);
}

// TC->O(logN) SC->O(N)
long long powerr(long long x,long long n){
    if(n==0){
        return 1;
    }
    long long xh = powerr(x,n/2)%mod;
    long long ph =( xh%mod *xh%mod)%mod;
    if(n%2){
        ph = ph*x;
    }
    return ph%mod;
}

int main(){
    
    return 0;
}


