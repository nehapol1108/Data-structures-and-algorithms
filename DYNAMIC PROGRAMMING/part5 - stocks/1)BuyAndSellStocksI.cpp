#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N) SC->O(1)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int maxp = 0, minp = INT_MAX;
    for(int i = 0; i < n; i++){
        minp = min(minp, prices[i]);
        maxp = max(maxp, prices[i] - minp);
    }
    return maxp;
    
} 
int main(){
    
    return 0;
}