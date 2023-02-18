#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool isValid(vector<int>& a,long long int m, int k){
    long long int subarr=1,sum=0,n=a.size();
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>m){
            subarr++;
            sum=a[i];
        }
        if(subarr>k){
            return false;
        }
    }
    return true;
}
int splitArray(vector<int>& a, int k) {
    long long int s=*max_element(a.begin(),a.end()),e=accumulate(a.begin(),a.end(),0);
    long long int res=-1;
    while(s<=e){
        long long int m= s + (e-s)/2;
        if(isValid(a,m,k)){
            res=m;
            e=m-1;
        }else{
            s = m+1;
        }
    }
    return res;
} 
int main(){
    
    return 0;
}