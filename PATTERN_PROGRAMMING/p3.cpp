#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
// 1
// 1 2 
// 1 2 3 
// 1 2 3 4 
// 1 2 3 4 5
int main(){
    int n;
    cin>>n;
    for(int row=0;row<n;row++){
        for(int col=0;col<=row;col++){
            cout<<col+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}