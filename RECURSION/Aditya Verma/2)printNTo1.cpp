#include<bits/stdc++.h>
#define ll long long
using namespace std;
//TC->O(n) SC->O(N)
void printNTo1(int n){
    if(n==1){
        cout<<n<<endl;
        return;
    }
    cout<<n<<endl;
    printNTo1(n-1);
    

}
int main(){
    printNTo1(7);
    return 0;
}