#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4

distance at a block is min of diff between cell to the walls(4 walls)
*/ 
int main(){
    int n;
    cin>>n;
    int orginalN = n;
    n=n*2;
    for(int row=0;row<n-1;row++){
        for(int col=0;col<n-1;col++){
           // cout<<col<<" "<<row<<" "<<row-n-2<<" "<<col-n-2<<endl;
           cout<<orginalN - min(min(col,n-row-2),min(row,n-col-2))<<" ";
        }
        cout<<endl;
    }
    return 0;
}