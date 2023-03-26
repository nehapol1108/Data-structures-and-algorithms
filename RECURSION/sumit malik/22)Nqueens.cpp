#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool isSafe(vector<vector<int>>v,int row,int col){
    //for upper
    for(int i=row-1;i>=0;i--){
        if(v[i][col]==1){
            return false;
        }
    }

    //for left diagnoal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(v[i][j]==1){
            return false;
        }
    }

    //for right diagnoal
    for(int i=row-1,j=col+1;i>=0 && j<v.size();i--,j++){
        if(v[i][j]==1){
            return false;
        }
    }

    return true;
}
void Nqueens(vector<vector<int>>v,string ans,int row) {
    if(row==v.size()){
        cout<<ans<<endl;
        return;
    }
    for(int col=0;col<v.size();col++){
        if(isSafe(v,row,col)){
            v[row][col]=1;
            Nqueens(v,ans+to_string(row)+"->"+to_string(col)+", ", row+1);
            v[row][col]=0;
        }
    }
}
int main(){
    
    return 0;
}