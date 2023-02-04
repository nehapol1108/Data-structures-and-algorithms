#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Time complexity: o(n)
// Space complexity: o(n)
void zerosToEnd(int arr[],int n) {
    int temp[n];
    int k=0;
    for (int i=0;i<n;i++){
        if (arr[i]!=0){
            temp[k]=arr[i];
            k++;
        }
    }
    
    while (k<n){
        temp[k]=0;
        k++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<temp[i]<<" ";
    }
}

// Time complexity: O(n)
// Space complexity: O(1)
void moveZeroes(vector<int>&a) {
    int z=-1;
    for(int i=0;i<a.size();i++){
        if(z==-1 && a[i]==0){
            z=i;
            
        }else if(z>=0 && a[i]!=0){
            a[z] = a[i];
            z++;   
        }
    }
    for(int i=z;i<a.size();i++){
        a[i]=0;
    }
    return ;
} 
int main(){
    
    return 0;
}