#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long int floorSqrt(long long int x) 
{
    long long int s=1,e=x,res=-1;
    while(s<=e){
        long long int m=s+ (e-s)/2;
        if(pow(m,2)==(x)){
            return m;
        }else if(pow(m,2)<x){
            res = max(res,m);
            s=m+1;
        }else{
            e=m-1;
        }
    }
    return res;
} 

//For nth root
int NthRoot(int n, int x)
{
    long long int s=1,e=x,res=-1;
    while(s<=e){
        long long int m=s+ (e-s)/2;
        if(pow(m,n)==(x)){
            return m;
        }else if(pow(m,n)<x){
            s=m+1;
        }else{
            e=m-1;
        }
    }
    return res;
}  
int main(){
    
    return 0;
}