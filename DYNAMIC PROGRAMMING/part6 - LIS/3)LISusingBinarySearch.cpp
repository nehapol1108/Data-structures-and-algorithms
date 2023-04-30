#include<bits/stdc++.h>
#define ll long long
using namespace std;

//using binary search TC- > O(n logn) SC-> O(n)
int lengthOfLIS(vector<int>& a) {
    int n =a.size();
    vector<int>temp;
    int len=1;
    temp.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(a[i]>temp.back()){
            temp.push_back(a[i]);
            len++;
        }else{
            vector<int>::iterator low1;
            low1 = lower_bound(temp.begin(),temp.end(),a[i]);
            temp[(low1 - temp.begin())] = a[i];
        }
    }
    return len;
    
}

int main(){
    
    return 0;
}