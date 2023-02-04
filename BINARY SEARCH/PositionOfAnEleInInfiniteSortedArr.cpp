#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll BinarySearchInInfiniteSortedAray(ll a[],int n,int target,ll s,ll e){
    while(s<=e){
        ll m = s+(e-s)/2;
        if(target==a[m]){
            return m;
        }else if(target>a[m]){
            e=m-1;
        }else{
            s=m+1;
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
    ll s=0,e=1;
    while(target>a[e]){
        s=e;
        e = e*2;
    }
    if(BinarySearchInInfiniteSortedAray(a,n,target,s,e)!=-1){
        cout<<"Element found at index "<<BinarySearchInInfiniteSortedAray(a,n,target,s,e)<<endl;
    }else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}