#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
bool isValid(vector<int>&a,long long int max,int m,int k){
    long long int c=0;
    long long int piu=0;
    for(int i=0;i<a.size();i++){
        if(a[i]<=max){
            c++;
            if(c==k){
                piu++;
                c=0;
            }
        }else{
            c=0;
        }
        if(piu>=m){
            return true;
        }
    }
    return false;
}
int minDays(vector<int>&a, int m, int k) {
    int s = 0;
    int e = *max_element(a.begin(),a.end());
    int res = -1;
    while(s<=e){
        long long int mid = s+(e-s)/2;
        if(isValid(a,mid,m,k)){
            // cout<<mid<<endl;
            res = mid;
            e = mid-1;
        }else{
            s=mid+1;
        }
    }
    return res;
} 
int main(){
    
    return 0;
}