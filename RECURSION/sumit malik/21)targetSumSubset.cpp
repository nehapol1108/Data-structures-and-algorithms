#include<bits/stdc++.h>
#define ll long long
using namespace std;
void targetSumSubset(vector<int>a,int i,int sum,int target,string ans){
    if(i==a.size()){
        if(sum==target){
            cout<<ans<<endl;    
        }
        return;
    }
    targetSumSubset(a,i+1,sum+a[i],target,ans+" "+to_string(a[i]));
    targetSumSubset(a,i+1,sum,target,ans);
    
} 
int main(){
    vector<int>a = {10,20,30,40,50};
    targetSumSubset(a,0,0,30,"");
    return 0;
}