#include<bits/stdc++.h>
#define ll long long
using namespace std;
// 1 
// 2 3 
// 4 5 6 
// 7 8 9 10 
// 11 12 13 14 15 
int main(){
    int n;
    cin>>n;
    int c=1;
    for(int row=0;row<n;row++){
        for(int col=0;col<=row;col++){
            cout<<c<<" ";
            c++;
        }
        cout<<endl;
    }
    return 0;
}