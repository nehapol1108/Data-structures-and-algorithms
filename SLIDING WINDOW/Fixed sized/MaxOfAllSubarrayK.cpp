#include<bits/stdc++.h>
#define ll long long
using namespace std;
//Maximum of all subarray of size K 
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    deque<int>l;
    int i=0,j=0;
    vector<int>ans;
    while(j<n){
        while(l.size()>0 && l.back()<a[j]){
            l.pop_back();
        }
        l.push_back(a[j]);
        if((j-i+1)<k){
            j++;
        }else if((j-i+1)==k){
            ans.push_back(l.front());
            if(l.front()==a[i]){
                l.pop_front();
            }
            i++;
            j++;
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}