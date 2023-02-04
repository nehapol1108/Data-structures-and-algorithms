#include<bits/stdc++.h>
#define ll long long
using namespace std;

//k -> negative for left rotate and positive for right rotate
/*
k=-1->>>b c d e a
k=0 ->>>a b c d e
k=1->>>>e a b c d
*/
// Time Complexity – O(N) where N is the number of elements in an array
// Space Complexity – O(1) since no extra space is required
void rotate(vector<int>&a, int k) {
    int n = a.size();
    k = k%(a.size());
    if(k<0){
        k+=n;
    }
    int num = n-k;
    reverse(a.begin(),a.begin()+num);
    reverse(a.begin()+num,a.end());
    reverse(a.begin(),a.end());  
}
int main(){
    
    return 0;
}