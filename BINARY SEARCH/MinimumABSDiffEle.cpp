#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll target;
    cin>>target;
    ll s=0,e=n-1,ans=-1;
    while(s<=e){
        ll m = s+(e-s)/2;
        if(target==a[m]){
            ans=a[m];
            break;
        }else if(target<a[m]){
            e=m-1;
        }else{
            s=m+1;
        }
    }
    cout<<(abs(a[s]-target)<abs(a[e]-target)?a[s]:a[e])<<endl;
    return 0;
}