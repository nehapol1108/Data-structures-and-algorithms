#include<bits/stdc++.h>
#define ll long long
using namespace std;
int characterReplacement(string s, int k) {
    int j=0,i=0;
    int n=s.size();
    unordered_map<char,int>m;
    int ans=0,piu=0;
    while(j<n){
        m[s[j]]++;
        if(m[s[j]]>piu){
            piu=m[s[j]];
        } 
        while(((j-i+1)-piu)>k){
            m[s[i]]--;
            if(m[s[i]]==0){
                m.erase(s[i]);
            }
            i++;
        }
        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
} 
int main(){
    
    return 0;
}