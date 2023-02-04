#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
        1
      2 1 2
    3 2 1 2 3
  4 3 2 1 2 3 4
5 4 3 2 1 2 3 4 5
*/ 
int main(){
    int n;
    cin>>n;
    for(int row=1;row<=n;row++){
        int spaces = n-row;
        for(int s=0;s<spaces;s++){
            cout<<" ";
        }
        for(int col=row;col>=1;col--){
            cout<<col;
        }
        for(int col=2;col<=row;col++){
            cout<<col;
        }
        cout<<endl;
    }
    return 0;
}