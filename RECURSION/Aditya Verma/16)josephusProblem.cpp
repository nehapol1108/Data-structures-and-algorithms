#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve(vector<int>&v,int index,int k,int &ans){
    if(v.size()==1){
        ans = v[0];
        return;
    }
    index = (index+k)%v.size();
    v.erase(v.begin()+index);
    solve(v,index,k,ans);
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v;
    for(int i=0;i<n;i++){
        v.push_back(i+1);
    }
    k--;
    int ans=-1;
    solve(v,0,k,ans);
    cout<<ans<<endl;
    return 0;
}