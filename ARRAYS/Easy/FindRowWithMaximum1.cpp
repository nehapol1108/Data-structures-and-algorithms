#include<bits/stdc++.h>
#define ll long long
using namespace std;
int rowWithMax1s(vector<vector<int> > a, int n, int m) {
    int i=0,j=m-1,count=0,ind=-1;
    while(i>=0 && j>=0 && i<n && j<m){
        if(a[i][j]==1){
            count++;
            ind=i;
            j--;
        }else if(a[i][j]==0){
            i++;
        }else{
            j--;
        }
    }
    return ind;
}
int main(){
    
    return 0;
}