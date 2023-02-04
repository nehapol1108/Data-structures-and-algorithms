#include<bits/stdc++.h>
#define ll long long
using namespace std;
void nextSmaller(vector<int>&a, int n) {
stack<int> s;
for(int i=n-1;i>=0;i--)
{
    int val = a[i];
    while (!s.empty() && s.top()>=a[i])
    {
        s.pop();
    }
    if(s.empty()){
        a[i]=-1;
    }else{
        a[i] = s.top();
    }
    s.push(val);
}
cout<<endl;
    
}
 
int main(){
    vector<int>a = {1,4,3,2,2,1,9};
    //output - >    1   5  1 -1  10   7  6 -1 
    nextSmaller(a,7);
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
// "1432219"
// 3