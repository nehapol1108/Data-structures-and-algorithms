#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll LastOccurenceOfAnEle(ll a[],int n,int target){
    ll s=0,e=n-1,res=-1;
    while(s<=e){
        ll m = s+(e-s)/2;
        if(target==a[m]){
            res=m;
            s=m+1;
        }else if(target<a[m]){
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
    if(LastOccurenceOfAnEle(a,n,target)!=-1){
        cout<<"Element found at index "<<LastOccurenceOfAnEle(a,n,target)<<endl;
    }else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}