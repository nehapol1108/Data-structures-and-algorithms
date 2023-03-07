#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://practice.geeksforgeeks.org/problems/number-of-nges-to-the-right/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-nges-to-the-right
vector<int> count_NGE(int n, vector<int> &a, int q, vector<int> &ind){
    //write your code here
    
    vector<int>ans(q,0);
    for(int i=0;i<q;i++){
        for(int j=ind[i];j<n;j++){
            if(a[ind[i]]<a[j]){
                ans[i]++;
            }
        }
    }
    return ans;
} 
int main(){
    
    return 0;
}