#include<bits/stdc++.h>
#define ll long long
using namespace std;
void printArray(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
} 


void merge(int *a,int low,int mid,int high,int n){ 
    int i=low,j=mid+1;
    int b[n];
    int k=low;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
            k++;
        }else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=high){
        b[k]=a[j];
        j++;
        k++;
    }
    for(int i=low;i<=high;i++){
        a[i]=b[i];
    }
}

void mergeSort(int *a,int low,int high,int n){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergeSort(a,low,mid,n);
        mergeSort(a,mid+1,high,n);
        merge(a,low,mid,high,n);
    }
}
int main(){
    int a[]={3,2,54,23,7};
    int n=5;
    printArray(a,n);
    mergeSort(a,0,n-1,n);
    printArray(a,n);
    return 0;
}