#include<bits/stdc++.h>
#define ll long long
using namespace std;
//TC->O(N) SC->O(N)
 int lengthOfLongestSubstring(string a) {
    int n=a.size();
    unordered_map<char,int>m;
    int maxi=0;
        
    int i=0,j=0;
        while(j<n){
            m[a[j]]++;
            if(m.size()==(j-i+1)){
                maxi = max(maxi,(j-i+1));
                j++;
            }
            else if(m.size()<(j-i+1)){
                while(m.size()<(j-i+1)){
                    m[a[i]]--;
                    if(m[a[i]]==0){
                        m.erase(a[i]);
                    }
                    i++;
                }
                
                j++;
            }
        }
    return maxi;
} 
int main(){
    
    return 0;
}