#include<bits/stdc++.h>
#define ll long long
using namespace std;
void floodFill(vector<vector<int>>v,int row,int col,vector<vector<bool>>&visited,string ans){
    if(row<0 || col<0 || col>=v[0].size() || row>=v.size() || v[row][col]==1 || visited[row][col]==true){
        return;
    }
    if(row==v.size()-1 && col==v[0].size()-1){
        cout<<ans<<endl;
        return;
    }

    visited[row][col]=true;
    floodFill(v,row-1,col,visited,ans+'L');
    floodFill(v,row,col-1,visited,ans+'U');
    floodFill(v,row+1,col,visited,ans+'D');
    floodFill(v,row,col+1,visited,ans+'R');
    visited[row][col]=false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v;
    vector<vector<bool>>visited;
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<m;j++){
            int num;
            cin>>num;
            temp.push_back(num);
        }
        v.push_back(temp);
    }
    for(int i=0;i<n;i++){
        vector<bool>temp;
        for(int j=0;j<n;j++){
            temp.push_back(false);
        }
        visited.push_back(temp);
    }
    string ans="";
    floodFill(v,0,0,visited,ans);
    return 0;
}