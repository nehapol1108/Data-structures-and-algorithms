#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
    string a;
    cin>>a;
    int k,n;
    cin>>k;
    n=a.size();
    unordered_map<int,int>m;
    int i=0,j=0,ans=-1;
    while(j<n){
        m[a[j]]++;
        if(m.size()<k){
            j++;
        }else if(m.size()==k){
            ans = max(ans,j-i+1);
            j++;
        }else if(m.size()>k){
            while(m.size()>k){
                m[a[i]]--;
                if(m[a[i]]==0){
                    m.erase(a[i]);
                }
                i++;
            }
            if(m.size()==k){
                ans = max(ans,j-i+1);
            }
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}