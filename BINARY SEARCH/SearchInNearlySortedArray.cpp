#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll SearchInNearlySortedArray(ll a[],ll n,ll target){
    ll s=0,e=n-1;
    while(s<=e){
        ll m = s+(e-s)/2;
        if(a[m]==target){
            return m;
        }else if(m>0 && a[m-1]==target){
            return m-1;
        }
        else if(m<n-1 && a[m+1]==target){
            return m+1;
        }else if(target<a[m]){
            e=m-2;
        }else{
            s=m+2;
        }
    }
    return -1;
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
    cout<<SearchInNearlySortedArray(a,n,target)<<endl;
    return 0;
}