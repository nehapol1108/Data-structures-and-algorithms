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
void bubbleSort(int *a,int n){
    for(int i=0;i<n-1;i++){   //for passes
        for(int j=0;j<n-i-1;j++){  //for comparisons
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
       
    }
} 
//TC - O(N^2) best case - O(n) SC - O(1)
void adaptiveBubbleSort(int *a,int n){
    int issorted=0;
    for(int i=0;i<n-1;i++){   //for passes
        cout<<"pass "<<i+1<<endl;
        issorted=1;
        for(int j=0;j<n-i-1;j++){  //for comparisons
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                issorted=0;
            }
        }
        if(issorted){
            return;
        }
       
    }
} 
//TC - O(N^2) best case - O(n) SC - O(n)
void recursiveBubbleSort(int *a,int i){
    if(i==0 || i==1){
        return;
    }
   
    for(int j=0;j<i-1;j++){  //for comparisons
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
        }
    }
    recursiveBubbleSort(a,i-1);
        
} 
int main(){
    int a[]={3,2,54,23,7};
    int b[]={1,2,3,4,5};
    int n=5;
    // printArray(a,n);
    // bubbleSort(a,n);
    // printArray(a,n);

    // printArray(b,n);
    // adaptiveBubbleSort(b,n);
    // printArray(b,n);

    printArray(a,n);
    recursiveBubbleSort(a,n);
    printArray(a,n);
    return 0;
}