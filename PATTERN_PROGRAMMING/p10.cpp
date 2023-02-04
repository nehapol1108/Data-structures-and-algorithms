#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
      1
    2 1 2
  3 2 1 2 3
4 3 2 1 2 3 4
  3 2 1 2 3
    2 1 2
      1

*/ 
int main(){
    int n;
    cin>>n;
    for(int row=1;row<=2*n-1;row++){
       
        int c = row>n? 2*n-row:row;
         int spaces = n-c;
        for(int s=0;s<spaces;s++){
            cout<<" ";
        }
        for(int col=c;col>=1;col--){
            cout<<col;
        }
        for(int col=2;col<=c;col++){
            cout<<col;
        }
        cout<<endl;
    }
    return 0;
}