#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Time Complexity : O( N log N ) + O (N) + O (N)   

// Reason : O(N) – Merge operation , O(N) – counting operation ( at each iteration of i , j doesn’t start from 0 . Both of them move linearly ) 

// Space Complexity : O(N) 

// Reason : O(N) – Temporary vector
int merge(vector<int>&a,vector<int>&temp,int s,int m,int e){
        int count=0,j=m+1;
        for(int i=s;i<=m;i++){
            while(j<=e && (a[i])>(a[j]*2)){
                j++;
            }
            count+= (j-(m+1));
        }
        int k=s,i=s;
        j=m+1;
    while(i<=m && j<=e){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }else{
            temp[k++]=a[j++];
        }
    }
    while(i<=m){
        temp[k++]=a[i++];
    }
    while(j<=e){
        temp[k++]=a[j++];
    }
    for(int i=s;i<=e;i++){
        a[i]=temp[i];
    }
    return count;
}
int mergesort( vector<int>&a,vector<int>&temp,int start,int end){
    int count=0;
    if(start<end){
        int mid = (start+end)/2;
        count=mergesort(a,temp,start,mid);
        count+=mergesort(a,temp,mid+1,end);
        count+=merge(a,temp,start,mid,end);
        
    }
    return count;
}
int countRevPairs(int n, vector<int> a) {
    vector<int>temp(n);
    return mergesort(a,temp,0,n-1);
}
int main(){
    
    return 0;
}