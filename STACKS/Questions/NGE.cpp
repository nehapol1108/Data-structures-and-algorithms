#include<bits/stdc++.h>
#define ll long long
using namespace std;


//TC->O(N^2) SC->(N)
vector<int> bruteNge(vector<int>a){
    vector<int>ans;
    for(int i=0;i<a.size();i++){
        int flag=0;
        for(int j=i+1;j<a.size();j++){
            if(a[j]>a[i]){
                flag=1;
                ans.push_back(a[j]);
                break;
            }
        }
        if(flag==0){
            ans.push_back(-1);
        }
    }
    return ans;
}

vector<int> nge(vector<int>a){
    stack<int>s;
    vector<int>ans;
    for(int i=a.size()-1;i>=0;i--){
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
    reverse(ans.begin(),ans.end());
    return ans;
}



vector<int> circularnge(vector<int>a){
    stack<int>s;
    vector<int>ans;
    for(int i=2*a.size()-1;i>=0;i--){
        while(!s.empty() && s.top()<=a[i%a.size()]){
            s.pop();
        }
        if(i<a.size()){
            if(s.empty()){
                ans.push_back(-1);
            }else{
                ans.push_back(s.top());
            }
        }
        
        s.push(a[i%a.size()]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<int>v = {3,10,4,2,1,2,6,1,7,2,9};
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int>ans = nge(v);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int>v1={2,10,12,1,11};
    vector<int>ans2 = circularnge(v1);
    for(auto i:v1){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:ans2){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}