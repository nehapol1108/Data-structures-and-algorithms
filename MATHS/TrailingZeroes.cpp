#include<bits/stdc++.h>
#define ll long long
using namespace std;

//Time complexity-> O(n)  It will cause overflow for slightly large integer
int brute_force_trailing_zero(int n){
    int res=1;
    for(int i=2;i<=n;i++){
        res=res*i;
    }
    int ans=0;
    while((res%10)==0){
        ans++;
        res = res/10;
    }
    return ans;
}

//efficient method O(log(n))
//explaination in notebook (we are basically counting number of 5's)
// https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
int efficient_trailing_zero(int n){
    int res=0;
    for(int i=5;i<=n;i=i*5){
        res = res + n/i;
    }
    return res;
}
int main(){
    int num=5;
    int n = 5;
    cout<<"number of trailing zeroes(brute force) are "<<brute_force_trailing_zero(n)<<endl;
    cout<<"number of trailing zeroes(efficient) are "<<efficient_trailing_zero(num)<<endl;
    
    return 0;
}