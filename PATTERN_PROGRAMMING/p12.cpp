#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
// 1 
// 0 1 
// 1 0 1
// 0 1 0 1 
// 1 0 1 0 1
int main(){
    int n;
    cin>>n;
    int prev=0;
    for(int row=0;row<n;row++){
        if(row%2==0){
            prev=0;
        }else{
            prev=1;
        }
        for(int col=0;col<=row;col++){
            if(prev==0){
                 cout<<1<<" ";
                 prev=1;
            }else{
                cout<<0<<" ";
                prev=0;
            }
           
        }
        cout<<endl;
    }
    return 0;
}