#include<bits/stdc++.h>
#define ll long long
using namespace std;

//Brute force would to check if to remove or keep an interval TC->O(2^n)

//TC->O(N) SC->O(N)
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<int>temp=newInterval;
    vector<vector<int>>ans;
    for(auto i:intervals){
        if(i[0]>temp[1]){
            ans.push_back(temp);
            temp=i;
        }else if(temp[0]>i[1]){
            ans.push_back(i);
        }else{
            i[0]=min(i[0],temp[0]);
            i[1]=max(i[1],temp[1]);
            temp=i;
        }
    }
    ans.push_back(temp);
    return ans;
}
int main(){
    
    return 0;
}