#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector <int> calculateSpan(int a[], int n)
{
    vector<int>ans;
    stack<int>s;
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top()<=a[i]){
            s.pop();
        }
        if(s.empty()){
            ans.push_back(-1);
            
        }else{
            ans.push_back(s.top());
        }
        s.push(a[i]);
    }
    return ans;
} 
//returns the number of elements smaller in prev
vector <int> calculateSpan(int a[], int n)
{
    vector<int>ans;
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top().second<=a[i]){
            s.pop();
        }
        if(s.empty()){
            ans.push_back(i+1);
            
        }else{
            ans.push_back(i-s.top().first);
        }
        
        
        s.push({i,a[i]});
    }
    return ans;
} 
int main(){
    
    return 0;
}