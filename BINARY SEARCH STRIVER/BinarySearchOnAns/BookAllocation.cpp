#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Time Complexity: O(NlogN)
// Auxilliary Space: O(1)
bool isValid(int a[],int n,int m,int k){
    int sum=0,stu=1;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>m){
            sum=a[i];
            stu++;
        }
        if(stu>k){
            return false;
        }
    }
    return true;
}
int findPages(int a[], int n, int k) 
{
    if(n<k){
        return -1;
    }
    int s = *max_element(a,a+n);
    int e = accumulate(a,a+n,0),res=-1;
    while(s<=e){
        int m = s+(e-s)/2;
        if(isValid(a,n,m,k)){
            res=m;
            e=m-1;
        }else{
            s=m+1;
        }
    }
    return res;
}
int main(){
    
    return 0;
}