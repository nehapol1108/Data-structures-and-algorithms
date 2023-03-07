#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(2N)
//SC->O(2N)
vector<int> asteroidCollision(int n, vector<int> &a) {
    stack<int>s;
    vector<int>v;
    for(int i=0;i<n;i++){
        if(a[i]>0){
            s.push(a[i]);
        }else{
            while(!s.empty() && s.top()>0 && s.top()<(-a[i])){
                s.pop();
            }
            if(!s.empty() && s.top()==(-a[i])){
                s.pop();
            }
            else if(!s.empty() && s.top()>(-a[i])){
                
            }else{
                s.push(a[i]);
            }
        }
    }
    
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }
    reverse(v.begin(),v.end());
    return v;
} 
int main(){
    
    return 0;
}