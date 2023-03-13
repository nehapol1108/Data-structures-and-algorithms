#include<bits/stdc++.h>
#define ll long long
using namespace std;
int numberOfSubstrings(string s) 
{
    int n=s.size();
    vector<int>v(3,0);
    int i=0,j=0,count=0;
    while(j<n){
        v[s[j]-'a']++;
        while(v[0] && v[1] && v[2]){
            count+= (n-j);
            v[s[i]-'a']--;
            i++;
        }
        j++;
    }
    return count;
} 
int main(){
    
    return 0;
}