#include<bits/stdc++.h>
#define ll long long
using namespace std;
//TC->O(n) SC->O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m;
    for(auto i:matrix){
        m = i.size();
        break;
    }
    int i=0,j=m-1;
    while(i<n && i>=0 && j<m && j>=0){
        if(matrix[i][j]==target){
            return true;
        }else if(matrix[i][j]>target){
            j--;
        }else if(matrix[i][j]<target){
            i++;
        }
    }
    
    return false;
} 
int main(){
    
    return 0;
}