#include<bits/stdc++.h>
#define ll long long
using namespace std;
void printZigzag(int n){
    if(n==0){
        return;
    }
    cout<<"Pre : "<<n<<endl;
    printZigzag(n-1);
    cout<<"In : "<<n<<endl;
    printZigzag(n-1);
    cout<<"Post : "<<n<<endl;
} 
int main(){
    printZigzag(2);
    return 0;
}