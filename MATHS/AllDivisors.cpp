#include<bits/stdc++.h>
#define ll long long
using namespace std;

//time complexity -> O(n)
void all_divisors(int n){
    for(int i=1;i<=n;i++){
        int x=i;
        if((n%x)==0){ 
            cout<<i<<" ";
        }       
    }
    cout<<endl;
}
//time complexity -> O(root n)
void all_divisors_efficient_non_sorted(int n){
    for(int i=1;i*i<=n;i++){
        int x=i;
        if((n%x)==0){ 
            cout<<i<<" ";
            if(i!=n/i){
                cout<<n/i<<" ";
            }
        }       
    }
    cout<<endl;
}

//time complexity -> O(root n)
//space complexity -> O(1)
void all_divisors_efficient_sorted(int n){
    int i;
    //print all divisors from 1(inclusive) to n(exclusive)
    for( i=1;i*i<n;++i){
        if((n%i)==0){ 
            cout<<i<<" ";
        }       
     }
    i--;
    //print all divisors from root n(inclusive) to n(inclusive)
    for(;i>=1;i--){
        if((n%i)==0){ 
            cout<<n/i<<" ";
        }       
    }
    cout<<endl;
}

int main(){
    int n=12;
    all_divisors(n);
    all_divisors_efficient_non_sorted(n);
    all_divisors_efficient_sorted(n);
    return 0;
}