#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
    string a;
    cin>>a;
    int n;
    n=a.size();
    unordered_map<int,int>m;
    int i=0,j=0,ans=-1;
    while(j<n){
        m[a[j]]++;
        if(m.size()==(j-i+1)){
            ans = max(ans,j-i+1);
            j++;
        }else if(m.size()<(j-i+1)){
            while(m.size()<(j-i+1)){
                m[a[i]]--;
                if(m[a[i]]==0){
                    m.erase(a[i]);
                }
                i++;
            }
            if(m.size()==(j-i+1)){
                ans = max(ans,j-i+1);
            }
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}