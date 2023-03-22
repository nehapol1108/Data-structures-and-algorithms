#include<bits/stdc++.h>
#define ll long long
using namespace std;


void insert(vector<int>&a,int temp){
    if(a.size()==0 || a[a.size()-1]<=temp){
        a.push_back(temp);
        return;
    }
    int val = a[a.size()-1];
    a.pop_back();
    insert(a,temp);
    a.push_back(val);
}
//TC->O(N^2) SC->O(2N)
void sort(vector<int>&a){
    if(a.size()==1){
        return;
    }
    int temp = a[a.size()-1];
    a.pop_back();
    sort(a);
    insert(a,temp);
} 
int main(){
    vector<int>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v);
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}