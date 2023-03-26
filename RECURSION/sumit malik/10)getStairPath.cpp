#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<string> getStairPath(int n){
    if(n==0){
        vector<string>v;
        v.push_back(""); // not moving so blank string
        return v;
    }else if(n<0){
        vector<string>v;
        return v;
    }

    vector<string>path1 = getStairPath(n-1);
    vector<string>path2 = getStairPath(n-2);
    vector<string>path3 = getStairPath(n-3);
    vector<string>paths;
    for(auto path:path1){
        paths.push_back('1' + path);
    }
    for(auto path:path2){
        paths.push_back('2' +path);
    }
    for(auto path:path3){
        paths.push_back('3' +path);
    }
    return paths;
}

int main(){
    vector<string>ans = getStairPath(3);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}