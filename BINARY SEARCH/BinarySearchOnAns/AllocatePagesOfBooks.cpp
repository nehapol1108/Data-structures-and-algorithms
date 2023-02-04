#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool is_Valid(ll a[],ll n,ll k,ll max){
    ll student=1,sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>max){
            student++;
            sum=a[i];
        }
        if(student>k){
            return false;
        }
    }
    return true;
}
ll AllocatePagesOfBooks(ll a[],ll n,ll k){
    ll start = *max_element(a,a+n);
    ll end = accumulate(a,a+n,0);
    ll res=-1;
    if(n<k){
        return -1;
    }
    while(start<=end){
        ll mid=start+(end-start)/2;
        if(is_Valid(a,n,k,mid)){
            res=mid;
            end = mid-1;
        }else{
            start=mid+1;
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
    ll k;
    cin>>k;
    cout<<AllocatePagesOfBooks(a,n,k)<<endl;
    return 0;
}