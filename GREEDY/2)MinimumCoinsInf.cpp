#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N) SC-> o(N)
static bool comp(int a,int b){
    return a>b;
}
vector<int> minPartition(int N)
{
    vector<int>v={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } ;
    sort(v.begin(),v.end(),comp);
    int n=v.size();
    int temp = N;
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(temp<=0){
            return ans;
        }
        int coins = (temp/v[i]);
        temp = temp - coins*v[i];
        if(coins>0){
            while(coins>0){
                ans.push_back(v[i]);
                coins--;
            }
        }
    }
    
    return ans;
} 
int main(){
    
    return 0;
}