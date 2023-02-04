#include<bits/stdc++.h>
#define ll long long
using namespace std;

//    A
//   ABA
//  ABCBA
// ABCDCBA

int main(){
    int n;
    cin>>n;
    for(int row=0;row<n;row++){
        for(int s=0;s<n-row-1;s++){
            cout<<" ";
        }
        int num = 2*row+1;
        for(int col=0;col<=num/2;col++){
            cout<<char(col+'A');
        }
        for(int col=num/2-1;col>=0;col--){
            cout<<char(col+'A');
        }
        cout<<endl;
    }
    return 0;
}