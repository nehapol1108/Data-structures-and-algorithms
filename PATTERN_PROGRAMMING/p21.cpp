#include<bits/stdc++.h>
#define ll long long
using namespace std;
// E
// E D
// E D C
// E D C B
// E D C B A 
int main(){
    int n;
    cin>>n;
    for(int row=0;row<n;row++){
        int ch = n-1;
        for(int col=0;col<=row;col++){
            cout<<char(ch+'A')<<" ";
            ch--;
        }
        cout<<endl;
    }
    return 0;
}