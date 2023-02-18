#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool isValid(vector<int>&a,long long int max,int k){
    long long int sum=0;
    for(int i=0;i<a.size();i++){
        if(sum + (ceil((a[i])/(max*1.00)))>k){
            return false;
        }
        sum+= (ceil((a[i])/(max*1.00)));    
    }
    return true;
}
int smallestDivisor(vector<int>&a, int k) {
    int s = 1;
    int e = *max_element(a.begin(),a.end());
    int res = -1;
    while(s<=e){
        long long int mid = s+(e-s)/2;
        if(isValid(a,mid,k)){
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