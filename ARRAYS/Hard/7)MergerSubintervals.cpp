#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/merge-intervals/

// Time Complexity: O(nlogn)
// Space Complexity:  O(n)  
vector<vector<int>> merge(vector<vector<int>>& v) {
    sort(v.begin(),v.end());
    vector<vector<int>>::iterator it = v.begin();
    for(int i=0;i<v.size()-1;){
        // cout<<v[i][1]<<" "<<v[i+1][0]<<endl;
        if(v[i][1]>=v[i+1][0]){
            v[i][1]=(v[i][1]<v[i+1][1])?v[i+1][1]:v[i][1];
            v.erase(it + i+1);
        }else{
            i++;
        }
    }
    return v;
}

// Time Complexity: O(nlogn + n)
// Space Complexity:  O(n) 
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