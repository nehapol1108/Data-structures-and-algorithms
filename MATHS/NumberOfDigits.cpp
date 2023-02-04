#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
//Iterative solution
ll countDigitIterative(ll n){   //time complexity = O(number of digits)
    ll count=0;
    while(n!=0){
        n=n/10;
        count++;
    }
    return count;
} 

//recursive soln
ll countDigitRecusive(ll n){    //time complexity = O(number of digits)
    if(n==0){
        return 0;
    }
    return 1+countDigitRecusive(n/10);
} 

//Logarithmic soln
// log10() Parameters
// The log10() function takes a single mandatory argument in the range [0, ∞].
// If the value is less than 0, log10() returns NaN (Not a Number).

//In mathematics, the logarithm is the inverse function to exponentiation. 
//That means the logarithm of a given number x is the exponent to which another fixed number, 
//the base b, must be raised, to produce that number x.

ll countDigitLogarithmic(ll n){   //time complexity = O(1)
    return (floor(log10(n)+1));
} 

int main(){
    ll n;
    cout<<"enter n"<<endl;
    cin>>n;
    cout<<countDigitLogarithmic(n)<<endl;
    //cout<<ceil(4.8)<<" "<<floor(4.8)<<endl; //ceil gives 5 and floor gives 4
    return 0;
}