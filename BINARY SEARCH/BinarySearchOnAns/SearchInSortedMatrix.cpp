#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
    ll n,m;
    cin>>n>>m;
    ll a[n][m];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    ll target;
    cin>>target;
    ll ans1=-1,ans2=-1,i=0,j=m-1;
    while(i>=0 && j>=0 && i<n && j<m){
        if(a[i][j]==target){
            ans1=i;
            ans2=j;
            break;
        }else if(a[i][j]>target){
            j--;
        }else{
            i++;
        }
    }
    return 0;
}