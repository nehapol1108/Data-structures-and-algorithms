#include<bits/stdc++.h>
#define ll long long
using namespace std;

// https://leetcode.com/problems/pascals-triangle/description/
// https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/

vector<vector<int>> generate(int n) {
    vector<vector<int>>v(n);
    for(int i=0;i<n;i++){
        vector<int>temp(i+1);
        if(i==0){
            temp[i]=1;
            v[i] = temp;
        }else{
            temp[0]=1;
            temp[temp.size()-1]=1;
            for(int j=1;j<temp.size()-1;j++){
                temp[j]=v[i-1][j] + v[i-1][j-1];
            }
            v[i]=temp;
        }

    }
    return v;

}
// Time Complexity: We are creating a 2D array of size (numRows * numCols) (where 1 <= numCols <= numRows), 
// and we are traversing through each of the cells to update it with its correct value, so Time Complexity = O(n^2).

// Space Complexity: Since we are creating a 2D array, space complexity = O(n^2).
int main(){
    
    return 0;
}