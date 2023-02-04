#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
// LCM
// the least common multiple, lowest common multiple, or smallest common multiple of two integers a and b,
// usually denoted by lcm, is the smallest positive integer that is divisible by both a and b.
//lcm is non zero it can be from 1 to infinity

//GCD
//the greatest common divisor of two or more integers, which are not all zero, is the largest positive integer that divides each of the integers.
//Highest number which exactly dvides both the numbers

//LCM(a, b) = (a x b) / GCD(a, b)


//brute force
//GCD time complexity -> O(min(a,b))
long long gcd_brute_force(long long a,long long b){
    long long num = min(a,b);
    while(num>0){
      if((a%num)==0 && (b%num)==0){
        break;
      }
      num--;
    }
    return num;
}
//LCM  time complexity -> O(a*b-max(a,b))
long long lcm_brute_force(long long a,long long b){
    long long num = max(a,b);
    while(num>0){
      if((num%a)==0 && (num%b)==0){
        break;
      }
      num++;
    }
    return num;
}

//effcient methods  EUCLID's method
//Do division operator and whenever b becomes 0 then whatever is left in value of a is the gcd

long long gcd_first(long long int a, long long int b)
{
  while(a!=b){
    if(a>b){
      a=a-b;
    }else{
      b=b-a;
    }
  }
  return a;
}

//Time complexity -> O(log(min(a,b)))
long long gcd_second(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd_second(b, a % b);
}
 
// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd_second(a, b)) * b;
}
// Time Complexity: O(log(min(a,b))
// Auxiliary Space: O(log(min(a,b))
int main(){
    long long a=12,b=18;
    cout<<"gcd is "<<gcd_brute_force(a,b)<<endl;
    cout<<"gcd is "<<gcd_second(a,b)<<endl;
    cout<<"gcd is "<<gcd_first(a,b)<<endl;

    cout<<"lcm is "<<lcm_brute_force(a,b)<<endl;
    cout<<"lcm is "<<lcm(a,b)<<endl;
    return 0;
}