#include<bits/stdc++.h>
#define ll long long
using namespace std;
int singleNonDuplicate(vector<int>&a) {
    int n=a.size();
    if(a.size()==1){
        return a[0];
    }  
    if(a[0]!=a[1]){
        return a[0];
    }
    if(a[n-1]!=a[n-2]){
        return a[n-1];
    }
    int s=0,e=a.size()-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(a[mid]!=a[mid-1] && a[mid]!=a[mid+1]){
            return a[mid];
        }else if((a[mid]==a[mid+1] && mid%2==0) || (a[mid]==a[mid-1] && mid%2!=0)){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return -1;
}
int main(){
    
    return 0;
}