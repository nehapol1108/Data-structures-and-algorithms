#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Given a sorted array A[] of N positive integers having all the numbers occurring exactly twice, except for one number which will occur only once. Find the number occurring only once. 

//TC->O(LOG(N)) SC->O(1)
int search(int a[], int n){
    int s=0,e=n-1;
    
    while(s<=e){
        int m = s+(e-s)/2;
        if(m>0 && m<n-1){
            if(a[m]!=a[m-1] && a[m]!=a[m+1]){
                return a[m];
            }else if(a[m]==a[m-1]){
                if((m+1)%2==0){
                    s=m+1;
                }else{
                    e=m-1;
                }
            }else if(a[m]==a[m+1]){
                if((m+1)%2==0){
                    e=m-1;
                }else{
                    s=m+1;
                }
            }
        }else{
            return a[m];
        }
    }
    return -1;
}
int main(){
    
    return 0;
}