#include<bits/stdc++.h>
#define ll long long
using namespace std;

// 1                 1
// 1 2             2 1
// 1 2 3         3 2 1
// 1 2 3 4     4 3 2 1
// 1 2 3 4 5 5 4 3 2 1 
int main(){
    int n;
    cin>>n;
   for(int row=0;row<n;row++){
        for(int col=0;col<=row;col++){
            cout<<col+1<<" ";
        }
        for(int s=0;s<n*2-((row+1)*2);s++){
            cout<<"  ";
        }
        for(int col=row;col>=0;col--){
            cout<<col+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}