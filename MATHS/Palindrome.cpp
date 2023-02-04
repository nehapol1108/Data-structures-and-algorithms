#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
//time complexity -> O(no. of digits)
bool isPalindrome(ll n){
    ll reverse=0;
    ll temp=n;
    while(temp!=0){
        ll ld = temp%10;
        reverse = reverse*10 + ld;
        temp = temp/10;
    }
    return reverse==n;
}


int main(){
    ll n;
    cout<<"enter n"<<endl;
    cin>>n;
    if(isPalindrome(n)){
        cout<<"PALINDROME"<<endl;
    }else{
         cout<<"NOT PALINDROME"<<endl;
    }
    return 0;
}