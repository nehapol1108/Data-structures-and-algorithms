#include<bits/stdc++.h>
#define ll long long
using namespace std;
//TC->O(n) SC->O(N)
void print1ToN(int n){
    if(n==1){
        cout<<n<<endl;
        return;
    }
    print1ToN(n-1);
    cout<<n<<endl;

}
int main(){
    print1ToN(7);
    return 0;
}