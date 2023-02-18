#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool is_valid(vector<int>&a,int k,int maxi,int n){
    int days=1,sum=0;
    for(int i=0;i<n;i++){
         sum+=a[i];
        if(sum>maxi){
            days++;
            sum=a[i];
        }
        if(days>k){
            return false;
        }
    }
    return true;   
}
int shipWithinDays(vector<int>&a, int days) {
    int n =a.size();
    int s = *max_element(a.begin(),a.end());
    int e = accumulate(a.begin(),a.end(),0);
    int res=-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(is_valid(a,days,mid,n)){
            res=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return res;
} 
int main(){
    
    return 0;
}