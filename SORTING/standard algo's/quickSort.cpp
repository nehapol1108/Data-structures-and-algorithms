#include<bits/stdc++.h>
#define ll long long
using namespace std;
void printArray(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
} 


int partition(int *a,int low,int high){ //pivot is first ele
    int pivot = a[low];
    int i = low+1;
    int j=high;
    do{
        while(a[i]<=pivot){
            i++; 
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<j){
            swap(a[i],a[j]);
        }
        
    }while(i<j);
    swap(a[low],a[j]);
    return j;
}
int partition_pivotlastele(int *a,int low,int high){
    int pivot = a[high];
    int i = low;
    int j=high-1;
    while(i<=j){
        while(a[i]<pivot){
            i++;
        }
        while(a[j]>=pivot){
            j--;
        }
        if(i<=j){
            swap(a[i],a[j]);
        }
        
    }
    swap(a[high],a[i]);
    return i;
}
void QuickSort(int *a,int low,int high){
    int partitionIndex;
    if(low<high){
        partitionIndex = partition_pivotlastele(a,low,high);
        QuickSort(a,low,partitionIndex-1);
        QuickSort(a,partitionIndex+1,high);
    }
}
int main(){
    int a[]={3,2,54,23,7};
    int n=5;
    printArray(a,n);
    QuickSort(a,0,n-1);
    printArray(a,n);
    return 0;
}