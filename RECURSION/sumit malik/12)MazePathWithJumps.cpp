#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<string> getMazePathWithJumps(int sr,int sc,int dr,int dc){
    if(sr==dr && sc==dc){
        vector<string>v;
        v.push_back("");
        return v;
    }
    vector<string>paths;

    //for horizontal move
    for(int ms = sc ; ms<= (dc-sc); ms++){
        vector<string>hpaths = getMazePathWithJumps(sr,sc+ms,dr,dc);
        for(auto hpath:hpaths){
            string k = to_string(ms);
            paths.push_back('h'+k + hpath);
        }
    }

    //for vertical move
    for(int ms = sr ; ms<= (dr-sr); ms++){
        vector<string>vpaths = getMazePathWithJumps(sr+ms,sc,dr,dc);
        for(auto vpath:vpaths){
            string k = to_string(ms);
            paths.push_back('v'+k + vpath);
        }
    }

    //for diagonal move
    for(int ms = sc ; ms<= (dc-sc) && (dr-sr); ms++){
        vector<string>dpaths = getMazePathWithJumps(sr+ms,sc+ms,dr,dc);
        for(auto dpath:dpaths){
            string k = to_string(ms);
            paths.push_back('d'+k + dpath);
        }
    }
    return paths;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<string>ans = getMazePathWithJumps(1,1,n,m);
    for(auto i:ans){
        cout<<i<<endl;
    }
    cout<<endl;
    return 0;
}