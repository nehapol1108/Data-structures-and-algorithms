#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll FindCeil(ll a[],int n,int target){
    ll s=0,e=n-1,res=INT_MAX;
    while(s<=e){
        ll m = s+(e-s)/2;
        if(target==a[m]){
            return a[m];
        }else if(target<a[m]){
            res = min(res,a[m]);
            e=m-1;
        }else{
           
            s=m+1;
        }
    }
    return res;
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
    if(FindCeil(a,n,target)!=INT_MAX){
        cout<<"ceil of "<<target<<" is "<<FindCeil(a,n,target)<<endl;
    }else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}