#include<bits/stdc++.h>
#define ll long long
using namespace std;
void printArray(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
} 

//TC - O(N^2) SC - O(1)
void selectionSort(int *a,int n){
    for(int i=0;i<n-1;i++){   //for passes
        int indexOfMin = i;
        for(int j=i+1;j<n;j++){  //for comparisons
            if(a[j]<a[indexOfMin]){
                indexOfMin = j;
            }
        }
        if(indexOfMin!=i){
            swap(a[i],a[indexOfMin]);
        }
    }
} 
//TC - O(N^2) SC - O(1)
void stableSelectionSort(int *a,int n){
    for(int i=0;i<n-1;i++){   //for passes
        int indexOfMin = i;
        for(int j=i+1;j<n;j++){  //for comparisons
            if(a[j]<a[indexOfMin]){
                indexOfMin = j;
            }
        }
        int key = a[indexOfMin];
        while(indexOfMin>i){
            a[indexOfMin] = a[indexOfMin-1];
            indexOfMin--;
        }
        a[i] = key;
    }
} 
int main(){
    int a[]={3,2,54,23,7};
    int n=5;
    printArray(a,n);
    stableSelectionSort(a,n);
    printArray(a,n);
    return 0;
}