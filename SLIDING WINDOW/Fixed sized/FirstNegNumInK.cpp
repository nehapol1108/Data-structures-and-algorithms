//Print first negative number in every window of size K
#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //number of windows = size-k+1 
    deque<int>l;
    vector<int>ans;
    int i=0,j=0;
    while(j<n){
        if(a[j]<0){
            l.push_back(a[j]);
        }
        if((j-i+1)<k){
            j++;
        }else if((j-i+1)==k){
            if(l.size()==0){
                cout<<'0'<<" ";
            }else{
                cout<<l.front()<<" ";
            }
            if(a[i]<0){
                l.pop_front();
            }
            i++;
            j++;
        }
    }
    cout<<endl;
    return 0;
}