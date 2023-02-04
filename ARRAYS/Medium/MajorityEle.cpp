#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N) SC->O(N)
int majorityElement(vector<int>& nums) {
    unordered_map<int,int>m;
    for(int i=0;i<nums.size();i++){
        m[nums[i]]++;
    }
    int maxi = INT_MIN,ans;
    for(auto i:m){
        if(i.second>maxi){
            maxi=i.second;
            ans=i.first;
        }
    }
    return ans;
}
//TC->O(N) SC->O(1)  More voting problem 
int majorityElement(int a[], int n)
{
    int count=0,num=a[0];
    for(int i=0;i<n;i++){
        if(count==0){
            num=a[i];
        }
        if(a[i]==num){
            count++;
        }else{
            count--;
        }
    }
    return num;
    
} 
int main(){
    
    return 0;
}