#include<bits/stdc++.h>
#define ll long long
using namespace std;

// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        * 
int main(){
    int n;
    cin>>n;
     for(int row=0;row<n;row++){
        for(int col=0;col<=row;col++){
            cout<<"*";
        }
        // cout<<2*n-(num+1)*2<<endl;
        for(int s=0;s<(2*n-(row+1)*2);s++){
            cout<<" ";
        }
        for(int col=0;col<=row;col++){
            cout<<"*";
        }
        cout<<endl;
    }
    int p=1;
    for(int row=0;row<n-1;row++){
        for(int col=0;col<n-1-row;col++){
            cout<<"*";
        }
        // cout<<2*n-(num+1)*2<<endl;
        for(int s=0;s<(p*2);s++){
            cout<<" ";
        }
        p++;
        for(int col=0;col<n-row-1;col++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}