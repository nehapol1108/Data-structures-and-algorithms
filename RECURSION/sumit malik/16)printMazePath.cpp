#include<bits/stdc++.h>
#define ll long long
using namespace std;
void printMazePath(int sr,int sc,int dr,int dc,string path){
    if(sr>dr || sc>dc){
        return;
    }
    if(sr==dr && sc==dc){
        cout<<path<<endl;
        return;
    }
    printMazePath(sr,sc+1,dr,dc,path+'h');
    printMazePath(sr+1,sc,dr,dc,path+'v');

} 
int main(){
    int n,m;
    cin>>n>>m;
    string path = "";
    printMazePath(1,1,n,m,path);
    return 0;
}