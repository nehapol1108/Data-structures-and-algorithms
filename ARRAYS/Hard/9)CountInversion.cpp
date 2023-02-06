#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity:  O(n) 
long long int merge(long long a[],long long temp[],long long l,long long m,long long r){
    long long int count=0;
    long long int i=l,j=m+1,k=l;
    while(i<=m && j<=r){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }else{
            temp[k++]=a[j++];
            count+= (m-(i)+1);
        }
    }
    while(i<=m){
        temp[k++]=a[i++];
    }
    while(j<=r){
        temp[k++]=a[j++];
            
    }
    for(int i=l;i<=r;i++){
        a[i]=temp[i];
    }
    return count;
}
long long int mergesort(long long a[],long long temp[],long long l,long long r){
    long long int mid,count=0;
    if(r>l){
        mid = (l+r)/2;
        count+= mergesort(a,temp,l,mid);
        count+=mergesort(a,temp,mid+1,r);
        count+=merge(a,temp,l,mid,r);
        
    }
    return count;
}
long long int inversionCount(long long a[],long long n){
    
    long long int temp[n];
        long long int ans = mergesort(a,temp,0,n-1);
        return ans;
    
}
int main(){
    
    return 0;
}