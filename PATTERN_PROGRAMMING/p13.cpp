#include<bits/stdc++.h>
#define ll long long
using namespace std;

//     *
//    ***  
//   *****
//  *******
// *********
int main(){
    int n;
    cin>>n;
    for(int row=0;row<n;row++){
        for(int s=0;s<n-row-1;s++){
            cout<<" ";
        }
        for(int col=0;col<2*row+1;col++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}