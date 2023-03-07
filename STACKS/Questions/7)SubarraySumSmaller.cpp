#include<bits/stdc++.h>
#define ll long long
using namespace std;
//TC->O(3N)
//SC->O(2N)
int sumSubarrayMins(vector<int>& a) {
    int n=a.size();
    vector<int>prevsmaller(n),nextsmaller(n);
    for(int i=0;i<n;i++){
        prevsmaller[i]=i;
        nextsmaller[i]=n-i-1;
    }
    stack<int>s1,s2;
    for(int i=n-1;i>=0;i--){
        int top=-1;
        while(!s1.empty() && a[s1.top()]>=a[i]){
            top=s1.top();
            s1.pop();
        }
        if(!s1.empty()){
            nextsmaller[i] =s1.top()-i-1;
        }
        s1.push(i);
    }
    for(int i=0;i<n;i++){
            int top=-1;
        while(!s2.empty() && a[s2.top()]>a[i]){
            s2.pop();
        }
        if(!s2.empty()){
            prevsmaller[i] =i-s2.top()-1;
        }
        s2.push(i);
    }
    
    for(int i=0;i<n;i++){
        cout<<prevsmaller[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<nextsmaller[i]<<" ";
    }
    cout<<endl;
    long long ans=0;
    long long mod = 1e9+7;
    for(int i=0;i<n;i++){
        ans+=(a[i]%mod*((prevsmaller[i]+1)%mod*(nextsmaller[i]+1)%mod)%mod)%mod;
        ans%=mod;
    }
    
    return ans;
}
int main(){
    
    return 0;
}