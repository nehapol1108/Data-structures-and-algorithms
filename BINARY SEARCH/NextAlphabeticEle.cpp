#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll NextAlphabeticEle(char a[],int n,char target){
    ll s=0,e=n-1;
    ll res=-1;
    while(s<=e){
        ll m = s+(e-s)/2;
        if(target==a[m]){
            s=m+1;
        }else if(target<a[m]){
            res=m;
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
    char a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    char target;
    cin>>target;
    if(NextAlphabeticEle(a,n,target)!=-1){
        cout<<"NextAlphabeticEle of "<<target<<" is "<<a[NextAlphabeticEle(a,n,target)]<<endl;
    }else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}