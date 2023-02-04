#include<bits/stdc++.h>
#define ll long long
using namespace std;
// ****
// *  *
// *  *
// ****
int main(){
    int n;
    cin>>n;
    for(int row=0;row<n;row++){
        int num = (row==0 || row==n-1)?1:0;
        if(num==1){
            for(int col=0;col<n;col++){
                cout<<"*";
            }
        }else{
            for(int col=0;col<n;col++){
                if(col==0 || col==n-1){
                    cout<<"*";
                }else{
                    cout<<" ";
                }
            }
        } 
        cout<<endl;
    }
    return 0;
}