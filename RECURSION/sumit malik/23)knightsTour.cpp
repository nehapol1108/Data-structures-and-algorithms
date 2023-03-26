#include<bits/stdc++.h>
#define ll long long
using namespace std;
void Display_Board(vector<vector<int>>v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void KnightsTour(vector<vector<int>>v,int r,int c,int move) {
    if(r<0 || c<0 || r>=v.size() || c>=v[0].size() || v[r][c]>0){
        return;
    }else if(move==v.size()*v.size()){
        v[r][c]=move;
        Display_Board(v);
        v[r][c]=0;
    }

    v[r][c]=move;

    //calls must be done in this order only
    KnightsTour(v,r-2,c+1,move+1);
    KnightsTour(v,r-1,c+2,move+1);
    KnightsTour(v,r+1,c+2,move+1);
    KnightsTour(v,r+2,c+1,move+1);
    KnightsTour(v,r+2,c-1,move+1);
    KnightsTour(v,r+1,c-2,move+1);
    KnightsTour(v,r-1,c-2,move+1);
    KnightsTour(v,r-2,c-1,move+1);
    v[r][c]=0;
}
int main(){
    int n,row,col;
    cin>>n>>row>>col;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<n;j++){
            temp.push_back(0);
        }
        v.push_back(temp);
    }
    KnightsTour(v,row,col,1);
    return 0;
}