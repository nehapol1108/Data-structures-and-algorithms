#include<bits/stdc++.h>
#define ll long long
using namespace std;
int longestKSubstr(string a, int k) {
int n=a.size();
unordered_map<char,int>m;
int maxi=INT_MIN;
int i=0,j=0;
    while(j<n){
        m[a[j]]++;
        if(m.size()<k){
            j++;
        }else if(m.size()==k){
            
            maxi = max(maxi,(j-i+1));
            j++;
        }
        else if(m.size()>k){
            while(m.size()>k){
                m[a[i]]--;
                if(m[a[i]]==0){
                    m.erase(a[i]);
                }
                i++;
            }
            
            j++;
        }
    }
    return (maxi!=INT_MIN?maxi:-1);
}
int main(){
    
    return 0;
}