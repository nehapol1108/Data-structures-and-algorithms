#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool is_Prime(int n){
    if(n==1){
        return false;
    }
    if(n==2 || n==3){
        return true;
    }
    if(n%2==0 || n%3==0){
        return false;
    }
    for(int i=5;i*i<n;i=i+6){
        if((n%i)==0 || (n%(i+2))==0){
            return false;
        }
    }
    return true;
} 

//time complexity -> O(nsquare(log(n)))
void prime_factors(int n){
    for(int i=2;i<n;i++){
        if(is_Prime(i)){
            int x=i;
            while((n%x)==0){ //this loop takes at most log(n) complexity
               // cout<<i<<" ";
                x=x*i;             
            }
        }
    }
}

//time complexity -> O(root(n)))
void prime_factors_square_root(int n){
    if(n<=1)return;
    for(int i=2;i*i<=n;i++){
        while((n%i)==0){
            cout<<i<<" ";
            n=n/i;
        }
    }
    // This condition is to handle the case when n  
    // is a prime number
    if(n>1){
        cout<<n<<endl;
    }
}

//time complexity -> O(root(n)))

void prime_factors_square_root_more_efficient(int n){
    if(n<=1)return;
    while((n%2)==0){
        cout<<2<<" ";
        n=n/2;
    }
    while((n%3)==0){
        cout<<3<<" ";
        n=n/3;
    }
    for(int i=5;i*i<=n;i=i+6){
        while((n%i)==0){
            cout<<i<<" ";
            n=n/i;
        }
        while((n%(i+2))==0){
            cout<<i+2<<" ";
            n=n/(i+2);
        }
    }
    // This condition is to handle the case when n  
    // is a prime number greater than 3
    if(n>3){
        cout<<n<<endl;
    }
}
//  TC->O(log(log(n)))
//SC->O(n)
void primeFactorsUsingSieve(int n){
    // https://www.youtube.com/watch?v=nDPo9hsDNvU&t=1s&ab_channel=ApnaCollege
    int spf[n+1];
    for(int i=2;i<=n;i++){
        spf[i]=i;
    }
    // 20 -> 10 -> 5 -> 1
    // 2      2    5    

    for(int i=2;i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
    while(n!=1){
        cout<<spf[n]<<" ";
        n = n/spf[n];
    }
    return;
}

int main(){
    int n=12;
    prime_factors_square_root_more_efficient(n);
    cout<<endl;
    primeFactorsUsingSieve(n);
    return 0;
}