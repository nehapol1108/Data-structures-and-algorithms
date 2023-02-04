#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
//     *
//    * *
//   * * *
//  * * * *
// * * * * *
// * * * * *
//  * * * *
//   * * *
//    * *
//     *
int main(){
    int n; 
    cin>>n;
     for(int row=0;row<=2*n;row++){ 
            int totalColsInRow = (row>n )? 2*n-row+1:row;
            int spaces = n-totalColsInRow;
         //   cout<<spaces<<" "<<totalColsInRow<<endl;
           if(totalColsInRow>0){
            for(int s=0;s<spaces;s++){
                cout<<" ";
            }
            for(int col = 0;col<totalColsInRow;col++){
                cout<<"* ";
            }
            
                cout<<endl;
            }
            
        }
    return 0;
} 