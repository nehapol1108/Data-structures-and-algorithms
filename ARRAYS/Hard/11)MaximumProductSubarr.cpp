#include<bits/stdc++.h>
#define ll long long
using namespace std;

// https://leetcode.com/problems/maximum-product-subarray/
// Time Complexity: O(n)
// Space Complexity:  O(1) 
int maxProduct(vector<int>& a) {
    int ans=a[0];
    int n=a.size();
    int ma=ans,mi=ans;
    for(int i=1;i<n;i++){
        if(a[i]<0){
            swap(ma,mi);
        }
        ma = max(a[i],a[i]*ma);
        mi = min(a[i],a[i]*mi);
        ans=max(ans,ma);
    }
    return ans;
    
} 
int main(){
    
    return 0;
}