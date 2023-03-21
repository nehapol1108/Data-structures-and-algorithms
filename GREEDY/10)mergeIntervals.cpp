#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N) SC->O(1)
vector<vector<int>> merge(vector<vector<int>>& v) {
        if(v.size()<=1){
        return v;
    }
    vector<vector<int>>ans;
    sort(v.begin(),v.end());
    vector<int>temp=v[0];
    for(auto i:v){
        if(i[0]<=temp[1]){
            temp[1] = max(temp[1],i[1]);
        }else{
            ans.push_back(temp);
            temp=i;
        }
    }
    ans.push_back(temp);
    return ans;
}
int main(){
    
    return 0;
}