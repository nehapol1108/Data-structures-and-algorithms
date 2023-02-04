#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
    string s1,s2;
    cin>>s1>>s2;
    unordered_map<char,int>m;
    int n=s1.size(),m1=s2.size();

    for(int i=0;i<s2.size();i++){
        m[s2[i]]++;
    } 
    int i=0,len=INT_MAX,count=m.size();
    string ans;
    for(int j=0;j<n;j++){
        if(m.find(s1[j])!=m.end()){
            m[s1[j]]--;
            if(m[s1[j]]==0){
                count--;
            }
        }
        while(count==0){
            if(len>(j-i+1)){
                len = j-i+1;
                ans = s1.substr(i,len);
            }
            if(m.find(s1[i])!=m.end()){
                m[s1[i]]++;
                if(m[s1[i]]==1){
                    count++;
                }
            }
            i++;
        }
    }
    cout<<((len==INT_MAX)?" ":ans)<<endl;
    return 0;
}