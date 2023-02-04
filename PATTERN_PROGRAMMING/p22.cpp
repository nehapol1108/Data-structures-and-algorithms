#include<bits/stdc++.h>
#define ll long long
using namespace std;
// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// ********** 
int main(){
    int n;
    cin>>n;
    for(int row=0;row<n;row++){
        for(int col=0;col<n-row;col++){
            cout<<"*";
        }
        for(int s=0;s<(row)*2;s++){
            cout<<" ";
        }
        for(int col=n-row-1;col>=0;col--){
            cout<<"*";
        }
        cout<<endl;
    }
    int p = n-1;
    for(int row=0;row<n;row++){
        for(int col=0;col<=row;col++){
            cout<<"*";
        }
        for(int s=0;s<(p)*2;s++){
            cout<<" ";
        }
        p--;
        for(int col=row;col>=0;col--){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}