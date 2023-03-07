#include<bits/stdc++.h>
#define ll long long
using namespace std;
int LargestRec(vector<int>a, int n){
    vector<long long>prevSmaller(n,-1),nextSmaller(n,n);
    stack<long long>s;
    for(long long i=n-1;i>=0;i--){
        while(!s.empty() && a[s.top()]>=a[i]){
            s.pop();
        }
        if(!s.empty()){
            nextSmaller[i] = s.top();
        }
        s.push(i);
    }
    while(!s.empty()){s.pop();}
    
    for(long long i=0;i<n;i++){
        while(!s.empty() && a[s.top()]>=a[i]){
            s.pop();
        }
        if(!s.empty()){
            prevSmaller[i] = s.top();
        }
        s.push(i);
    }
    int res=0;
    for(long long i=0;i<n;i++){
        int area = (nextSmaller[i]-prevSmaller[i]-1)*a[i];
        res = max(res,area);
    }
    return res;
}
int maxArea(int a[INT_MAX][INT_MAX], int n, int m) {
    // Your code here
    int maxarea = 0;
    vector<int>height(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0){
                height[j]=0;
            }else{
                height[j]++;
            }
        }
        int area = LargestRec(height,m);
        maxarea = max(maxarea,area);
    }
    return maxarea;
} 
int main(){
    
    return 0;
}