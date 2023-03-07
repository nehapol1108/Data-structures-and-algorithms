#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> maxSlidingWindow(vector<int>& a, int k) {
    int n=a.size();
    deque<int>q;
    vector<int>ans;
    int j=0,i=0;
    while(j<n){
        while(q.size()>0 && q.back()<a[j]){
            q.pop_back();
        }
        q.push_back(a[j]);
        if((j-i+1)<k){
            j++;
        }else if((j-i+1)==k){
            ans.push_back(q.front());
            if(q.front()==a[i]){
                q.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;

} 
int main(){
    
    return 0;
}