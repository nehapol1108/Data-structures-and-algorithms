#include<bits/stdc++.h>
#define ll long long
using namespace std;

// ABCDE
// ABCD
// ABC
// AB
// A
int main(){
    int n;
    cin>>n;
    for(int row=0;row<n;row++){
        for(int col=0;col<n-row;col++){
            cout<<char(col+'A');
        }
        cout<<endl;
    }
    return 0;
}