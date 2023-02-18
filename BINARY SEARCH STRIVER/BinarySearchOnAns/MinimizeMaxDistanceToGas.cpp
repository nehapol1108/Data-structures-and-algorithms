#include<bits/stdc++.h>
#define ll long long
using namespace std;

// https://www.youtube.com/watch?v=gcDUAw3vQlg&t=1137s&ab_channel=HappyCoding
bool isValid(vector<int>&a,double dis,int k){
    int n=a.size(),countstation=0;
    for(int i=1;i<n;i++){
        //calculating need of stations to be filled in order to keep the distance as dis
        countstation+= floor((a[i]-a[i-1])/dis*1.0);
    }
    return countstation<=k;
}
double findSmallestMaxDist(vector<int> &a, int k){
    // Code here
    double s = 0;
    int n=a.size();
    double e = a[n-1]-a[0];
    double res = -1;
    while((e-s)>1e-6){
        double mid = s+(e-s)/2.00;
        if(isValid(a,mid,k)){
            res = mid;
            e = mid;
        }else{
            s=mid;
        }
    }
    return res;
} 
int main(){
    
    return 0;
}