#include<bits/stdc++.h>
#define ll long long
using namespace std;
int all_occ(int a[],int n,int pos,int k,vector<int>&v){
    if(pos==n){
        return -1;
    }
    int occ = all_occ(a,n,pos+1,k,v);
    if(a[pos]==k){
        v.push_back(pos);
        return pos;
    }else{
        return -1;
    }   
}
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>v;
    int nu;
    nu= all_occ(a,n,0,k,v);
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}