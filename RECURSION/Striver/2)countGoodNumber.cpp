#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/count-good-numbers/

// https://www.youtube.com/watch?v=CctVpEGgNf0&ab_channel=Fraz

//TC->O(logn)
long long int mod = 1e9+7;

//even = 0 2 4 6 8
//prime = 2 3 5 7
long long power(long long x,long long n){
    if(n==0){
        return 1;
    }
    long long xh = power(x,n/2)%mod;
    long long ph =( xh%mod *xh%mod)%mod;
    if(n%2){
        ph = ph*x;
    }
    return ph%mod;
}
int countGoodNumbers(long long n) {
    long long odd = n/2 , even = n/2 + n%2;
    return (power(5,even) * power(4,odd)) %mod;
}


//GFG wala
// https://practice.geeksforgeeks.org/problems/good-numbers4629/1

bool isGood(int n,int D,int sum){
    if(n<=0)return true;
    if(n%10 <=sum)return false;
    if(n%10 ==D)return false;
    return isGood(n/10,D,sum+n%10);
}
vector<int> goodNumbers(int L, int R, int D) {
    vector<int>ans;
    for(int i=L;i<=R;i++){
        int sum = i%10;
        if(sum==D)continue;
        
        if(isGood(i/10,D,sum)){
            ans.push_back(i);
        }
    }
    return ans;
}
int main(){
    
    return 0;
}