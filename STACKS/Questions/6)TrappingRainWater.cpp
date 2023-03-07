#include<bits/stdc++.h>
#define ll long long
using namespace std;

//brute force  
//TC->O(3N)~O(N) SC->O(2N)
int trap(vector<int>& a) {
    int n = a.size();
    int pm[n];
    int sm[n];
    pm[0]=a[0];
    sm[n-1]=a[n-1];
    for(int i=1;i<n;i++){
        if(a[i]>pm[i-1]){
            pm[i]=a[i];
        }else{
            pm[i]=pm[i-1];
        }
    }
    for(int i=n-2;i>=0;i--){
        if(a[i]>sm[i+1]){
            sm[i]=a[i];
        }else{
            sm[i]=sm[i+1];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+= min(pm[i],sm[i])-a[i];
    }
    return ans;
}
//TC->O(N) SC->O(1)
int trap(vector<int>& a) {
    int n = a.size();
    int l=0,r=n-1;
    int res=0;
    int maxleft=0,maxright=0;
    while(l<=r){
        if(a[l]<=a[r]){
            if(a[l]>=maxleft){
                maxleft = a[l];
            }else{
                res+=maxleft-a[l];
            }
            l++;
        }else{
            if(a[r]>=maxright){
                maxright=a[r];
            }else{
                res+=maxright-a[r];
            }
            r--;
        }
        
    }
    return res;
} 
int main(){
    
    return 0;
}