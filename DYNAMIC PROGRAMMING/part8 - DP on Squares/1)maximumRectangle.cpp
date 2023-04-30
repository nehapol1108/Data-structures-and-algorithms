#include<bits/stdc++.h>
#define ll long long
using namespace std;
void PreviousSmaller(vector<int> &a, int n,vector<int>&ps)
{
    stack<int> s;
    for (int i = 0; i <n; i++)
    {
        int val = a[i];
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        if(s.empty()){
          ps[i]=-1;
        }else{
            ps[i]=s.top();
        }
        s.push(i);
    }
}
    void nextSmaller(vector<int> &a, int n,vector<int>&ns)
{
    stack<int> s;
    for (int i = n-1; i>=0; i--)
    {
        int val = a[i];
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        if(s.empty()){
           ns[i]=n;
        }else{
            ns[i]=s.top();
        }
        s.push(i);
    }
}
 int largestRectangleArea(vector<int>& a) {
        int maxarea=0;
        int n = a.size();
        vector<int>ps(n);
        vector<int>ns(n);
      
        PreviousSmaller(a,n,ps);
        nextSmaller(a,n,ns);
        for(int i=0;i<n;i++){
            int curr = (ns[i]-ps[i]-1)*a[i];
            maxarea = max(maxarea,curr);
        }
        return maxarea;
    }
class Solution {
public:
   //TC->O(N*(M+N)) 
   //sc->o(N)
    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        int maxarea = 0;
        vector<int>height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='1'){
                    height[j]++;
                }else{
                    height[j] = 0;
                }
            }
            int area = largestRectangleArea(height);
            maxarea = max(maxarea,area);
        }
        return maxarea;
    }
}; 
int main(){
    
    return 0;
}