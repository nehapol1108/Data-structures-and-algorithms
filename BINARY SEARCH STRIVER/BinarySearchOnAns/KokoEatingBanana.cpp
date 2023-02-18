#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool isValid(vector<int>&a,long long int max,int h){
    long long int minhour=0;
    for(int i=0;i<a.size();i++){
        if(minhour + (ceil((a[i])/(max*1.00)))>h){
            return false;
        }
        minhour+= (ceil((a[i])/(max*1.00)));
        // cout<<minhour<<endl;
        
    }
    return true;
}
int minEatingSpeed(vector<int>&a, int h) {
    int s = 0;
    int e = *max_element(a.begin(),a.end());
    int res = INT_MAX;
    while(s<=e){
        long long int mid = s+(e-s)/2;
        if(isValid(a,mid,h)){
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