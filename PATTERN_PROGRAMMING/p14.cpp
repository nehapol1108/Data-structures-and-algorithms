#include<bits/stdc++.h>
#define ll long long
using namespace std;

// *********
//  *******
//   *****
//    ***
//     *
int main(){
    int n;
    cin>>n;
    int rowr=n;
    for(int row=0;row<n;row++){
        for(int s=0;s<row;s++){
            cout<<" ";
        }
        for(int col=0;col<2*rowr-1;col++){
            cout<<"*";
           
        }
         rowr--;
        cout<<endl;
    }
    return 0;
}