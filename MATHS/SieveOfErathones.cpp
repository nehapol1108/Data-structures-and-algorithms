#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.youtube.com/watch?v=nDPo9hsDNvU&t=1s&ab_channel=ApnaCollege
//  TC->O(log(log(n)))
//SC->O(n)
void sievePrime(int n){
    int prime[n+1]={0};
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=1;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            cout<<i<<" ";
        }
       
    }
     cout<<endl;
} 
int main(){
    int n;
    cin>>n;
    sievePrime(n);
    return 0;
}