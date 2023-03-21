#include<bits/stdc++.h>
#define ll long long
using namespace std;

// https://www.youtube.com/watch?v=h6_lIwZYHQw&ab_channel=TECHDOSE
//TC->O(N) SC->O(n)
int minCandy(int N, vector<int> &a) {
    int n=a.size();
    vector<int> lefts(n, 1);
    vector<int> rights(n, 1);
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1]){
            lefts[i] = lefts[i-1] + 1;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(a[i]>a[i+1]){
            rights[i] = rights[i+1] + 1;
        }
    }

    long long ans=0;
    for(int i = 0 ; i < n; i++) {
        ans += max(lefts[i], rights[i]);
    }
    return ans;
}
int main(){
    
    return 0;
}