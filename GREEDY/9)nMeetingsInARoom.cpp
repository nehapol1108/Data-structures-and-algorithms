#include<bits/stdc++.h>
#define ll long long
using namespace std;


//TC->O(NLOGN) SC->O(N)
static bool comp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}
int maxMeetings(int a[], int b[], int n)
{
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        v.push_back({a[i],b[i]});
    }
    sort(v.begin(),v.end(),comp);
    int curr =-1;
    int ans=0;
    for(auto i:v){
        if(i.first>curr){
            ans++;
            curr = i.second;
        }
    }
    return ans;
}

//sorting acc to ending time
//1 3 0 5 8 5
    //2 4 6 7 9 9 
int main(){
    
    return 0;
}