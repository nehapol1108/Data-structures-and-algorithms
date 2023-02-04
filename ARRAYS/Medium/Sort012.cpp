#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC-> O(2N) SC->O(1)
void sortColors(vector<int>&a) {
    int c1=0,c2=0,c0=0,n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]==0){
            c0++;
        }else if(a[i]==1){
            c1++;
        }else{
            c2++;
        }
    }
    int j=0;
    while(c0--){
        a[j]=0;
        j++;
    }
        while(c1--){
        a[j]=1;
        j++;
    } 
    while(c2--){
        a[j]=2;
        j++;
    }
}
//TC-> O(N) SC->O(1)  DUTCH NATIONAL FLAG ALGORITHM
void sortColors(vector<int>&a) {
    int n=a.size();
    int low=0,high=n-1,mid=0;
    while(mid<=high){
        switch(a[mid]){
            case 0:
                swap(a[low++],a[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(a[mid],a[high--]);
                break;
        }
    }
}
int main(){
    
    return 0;
}