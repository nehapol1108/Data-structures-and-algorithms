#include<bits/stdc++.h>
#define ll long long
using namespace std;

//space O(m) TC = O(n*m) //space optimisation
int longestCommonSubsequence_space(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<int>prev(m+1,0),curr(m+1,0);
    for(int j=0;j<=m;j++){
        prev[j] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    curr[j] = 1+ prev[j-1];
            }
            else{
                curr[j] = 0 + max(prev[j],curr[j-1]);
            }
        }
        prev = curr;
    }   
    return prev[m];
}
int countMin(string s){
    string t = s;
    reverse(s.begin(),s.end());
    int n  = s.size();
    return n- longestCommonSubsequence_space(s,t);
}
int main(){
    
    return 0;
}