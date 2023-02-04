#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll NumberOfTimesSortedArrayRotated(ll a[],ll n){
    ll s=0,e=n-1;
    while(s<=e){
        ll m = s+(e-s)/2;
        ll next = (m+1)%n;
        ll prev=(m+n-1)%n;
       
        if(a[m]<a[prev] && a[m]<a[next]){
            return m;
        }else if(a[m]<a[e]){
            e=m-1;
        }else{
            s=m+1;
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
    cout<<NumberOfTimesSortedArrayRotated(a,n)<<endl;
    return 0;
}