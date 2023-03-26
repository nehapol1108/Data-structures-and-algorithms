#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<string> getMazePath(int sr,int sc,int dr,int dc){
    if(sr==dr && sc==dc){
        vector<string>v;
        v.push_back("");
        return v;
    }
    vector<string>hpath;
    vector<string>vpath;
    vector<string>paths;
    if(sr<dr){
        hpath = getMazePath(sr+1,sc,dr,dc);
    }

    if(sc<dc){
        vpath = getMazePath(sr,sc+1,dr,dc);
    }
    for(auto path:hpath){
        paths.push_back('h' + path);
    }
    for(auto path:vpath){
        paths.push_back('v' + path);
    }
    return paths;
} 
int main(){
    int n,m;
    cin>>n>>m;
    vector<string>ans = getMazePath(1,1,n,m);
    for(auto i:ans){
        cout<<i<<endl;
    }
    cout<<endl;
    return 0;
}