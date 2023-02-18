#include<bits/stdc++.h>
#define ll long long
using namespace std;
//TC-> O(min(log n, log m)).
//SC-> O(1)
double findMedianSortedArrays(vector<int>& a1, vector<int>& a2) {
    int n=a1.size(),m=a2.size();
    if(n>m){
        findMedianSortedArrays(a2,a1);
    }
    int k =(1+n+m)/2;
    int low = max(0,k-m), high= min(k,n);
    while(low<=high){
        int cut1 = (low+high)/2;
        int cut2 = k-cut1;
        int l1 = cut1==0?INT_MIN:a1[cut1-1];
        int l2 = cut2==0?INT_MIN:a2[cut2-1];
        int r1 = cut1==n?INT_MAX:a1[cut1];
        int r2 = cut2==m?INT_MAX:a2[cut2];
        if(l1<=r2 && l2<=r1){
            if((n+m)%2==0){
                return ((max(l1,l2))+min(r1,r2))/2.0;
            }else{
                return max(l1,l2)*1.00;
            }   
        }else if(l1>r2){
            high=cut1-1;
        }else{
            low=cut1+1;
        }
    }
    return 1;
}
int main(){
    
    return 0;
}