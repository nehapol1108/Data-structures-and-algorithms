#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll binary_search(ll a[],int n,int target,ll s,ll e){
   
    while(s<=e){
        ll m = s+(e-s)/2;
        if(target==a[m]){
            return m;
        }else if(target<a[m]){
            e=m-1;
        }else{
            s=m+1;
        }
    }
    return -1;
}
ll MinIndex(ll a[],ll n){
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
    ll target;
    cin>>target;
    ll MinInd = MinIndex(a,n);
    if(MinInd==0){
        cout<<binary_search(a,n,target,0,n-1);
    }
    else if(target>=a[0]){
        cout<<binary_search(a,n,target,0,MinInd-1);
    }else{
        cout<<binary_search(a,n,target,MinInd,n-1);
    }
    return 0;
}