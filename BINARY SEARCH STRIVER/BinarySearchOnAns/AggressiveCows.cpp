#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://practice.geeksforgeeks.org/problems/aggressive-cows/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=aggressive-cows
bool is_valid(vector<int>&a,int mini,int k){
    int start=0,j=0,ele = 1,n=a.size();
    // cout<<mini<<endl;
    while(j<n && start<n){
        if((abs(a[j]-a[start]))>=mini){
            ele++;
            start=j;
        }
        j++;
    }
    if(ele>=k){
        return true;
    }else{
        return false;
    }
}
int solve(int n, int k, vector<int> &a) {
    int s = 0;
    sort(a.begin(),a.end());
    int e = *max_element(a.begin(),a.end()) - *min_element(a.begin(),a.end());
    // cout<<s<<" "<<e<<endl;
    int res=-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(is_valid(a,mid,k)){
            res=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return res;
} 
int main(){
    
    return 0;
}