#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll peakElement(ll a[],ll n){
    ll l=0,h=n-1;
    while(l<=h){
        ll m = l+(h-l)/2;
        if(m>0 && m<n-1){
            if(a[m]>a[m-1] && a[m]>a[m+1]){
                return m;
            }else if(a[m+1]>a[m]){
                l=m+1;
            }else{
                h=m-1;
            }
        }else if(m==0){
            if(a[0]>a[1]){
                return 0;
            }else{
                return 1;
            }
        }
        else if(m==n-1){
            if(a[n-1]>a[n-2]){
                return n-1;
            }else{
                return n-2;
            }
        }
    }
}
int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<peakElement(a,n)<<endl;
    return 0;
}