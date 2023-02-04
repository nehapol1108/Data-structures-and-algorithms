#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
// * 
// * * 
// * * * 
// * * * * 
// * * * * *
// * * * *
// * * *
// * *
// *
int main(){
    int n;
    cin>>n;
     for(int row=0;row<2*n-1;row++){ 
        if(row<n){
            for(int col=0;col<=row;col++){
                    cout<<"* ";
            }
        }else{
            for(int col=0;col<2*n-row-1;col++){
                    cout<<"* ";
            }
        }
        cout<<endl;
        
    }
    return 0;
} 