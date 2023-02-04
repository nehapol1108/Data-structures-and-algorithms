#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
    string s1,s2;
    cin>>s1>>s2;  
    vector<int>hs1(26,0);
    vector<int>hs2(26,0);
    for(int i=0;i<s2.size();i++){
        hs2[s2[i]-'a']++;
    }
    int i=0,j=0;
    int n = s1.size(),m = s2.size(),count=0;
    while(j<n){
        hs1[s1[j]-'a']++;
        if((j-i+1)<m){
            j++;
        }else if((j-i+1)==m){
            if(hs1==hs2){
                count++;
            }
            --hs1[s1[i]-'a']; 
            i++;
            j++;
        }
    }
    cout<<count<<endl;
    return 0;
}