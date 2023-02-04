#include<bits/stdc++.h>
#define ll long long
using namespace std;
void printArray(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
} 
int binary_search(int *a,int key,int low,int high){
    while(low<=high){
        int mid = low + (high-low)/2;
        if(key==a[mid]){
            return mid+1;
        }else if(key<a[mid]){
            high=mid-1;
        }else{
            low = mid+1;
        }
    }
    return low;
}
//TC - O(N^2) SC - O(1)
void insertionSort(int *a,int n){
    for(int i=1;i<n;i++){   //for passes
        int j=i-1;
        int key = a[i];
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
} 
void BinarySearch_insertionSort(int *a,int n){
    for(int i=1;i<n;i++){   //for passes
        int j=i-1;
        int key = a[i];
        int loc = binary_search(a,key,0,j);
        while(j>=loc){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
} 
void RecursiveInsertionSort(int *a,int n){
    if(n<=1){
        return;
    }
    RecursiveInsertionSort(a,n-1);
    int key = a[n-1];
    int j = n-2;  //as it is one based 
    while(j>=0 && a[j]>key){
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=key;
} 

int main(){
    int a[] = {12, 54, 65, 7, 23, 9};
    int n=5;
    printArray(a,n);
    
    insertionSort(a,n);
    printArray(a,n);

    BinarySearch_insertionSort(a,n);
    printArray(a,n);

    RecursiveInsertionSort(a,n);
    printArray(a,n);
    return 0;
}
// -1   0    1   2   3   4   5
//      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
//      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

//      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
//      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

//      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
//      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
//      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
//      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
//      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

// Fast forwarding and 4th and 5th pass will give:
//      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
//      07, 12, 23, 54,| 65, 09 --> After the 4th pass

//      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
//      07, 09, 12, 23, 54, 65| --> After the 5th pass 