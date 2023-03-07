#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Time Complexity :- BigO(N^2)
// Space Complexity :- BigO(N)
 int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    if(n == 0) return 0; // Base Condition
    int maxArea = 0;
    vector<int> left(n); //fill left boundary
    vector<int> right(n); // fill right boundary
    
    left[0] = -1;
    right[n - 1] = n;
    
    for(int i = 1; i < n; i++){
        int prev = i - 1; // previous for comparing the heights
        while(prev >= 0 && heights[prev] >= heights[i]){
            prev = left[prev]; // we have done this to minimise the jumps we make to the left
        }
        left[i] = prev;
    }
    // Similarly we do for right
    for(int i = n - 2; i >= 0; i--){
        int prev = i + 1; 
        while(prev < n && heights[prev] >= heights[i]){
            prev = right[prev]; 
        }
        right[i] = prev;
    }
    // once we have these two arrays fill we need width & area
    for(int i = 0; i < n; i++){
        int width = right[i] - left[i] - 1;
        maxArea = max(maxArea, heights[i] * width);
    }
    return maxArea;
}

//TC->O(3N)
//SC->O(N)
long long getMaxArea(long long a[], int n)
{
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
    long long res=0;
    for(long long i=0;i<n;i++){
        long long area = (nextSmaller[i]-prevSmaller[i]-1)*a[i];
        res = max(res,area);
    }
    return res;
} 
int main(){
    
    return 0;
}