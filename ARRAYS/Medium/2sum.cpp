#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice

// Time Complexity: O(N2)
// Space Complexity: O(1)
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
   	 for (int j = i + 1; j < nums.size(); ++j) {
   		 if (nums[i] + nums[j] == target) {
   			 res.emplace_back(i);
   			 res.emplace_back(j);
   			 break;
   		 }
   	 }
   	 if (res.size() == 2)
   		 break;
    }
    return res;
} 


// Time Complexity: O(NlogN)
// Space Complexity: O(N)
vector<int> TwoSumTwoPointer(vector<int>&a, int target){
    vector<int>b = a;
    sort(b.begin(),b.end());
    int i=0,j=a.size()-1,n1,n2;
    vector<int>ans;
    while(i<j){
        if(b[i]+b[j]==target){
            n1=b[i];
            n2=b[j];
            break;
        }else if((b[i]+b[j])>target){
            j--;
        }else{
            i++;
        }
    }
    for(int i=0;i<a.size();i++){
        if(a[i]==n1){
            ans.push_back(i);
        }else if(a[i]==n2){
            ans.push_back(i);
        }
    }
    return ans;
}

//using HASHING
// Time Complexity: O(N)
// Space Complexity: O(N)
vector<int> twoSum(vector<int>& nums, int target) {

    vector<int> res;
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); ++i) {

   	 if (mp.find(target - nums[i]) != mp.end()) {

   		 res.emplace_back(i);
   		 res.emplace_back(mp[target - nums[i]]);
   		 return res;
   	 }

   	 mp[nums[i]] = i;
    }

    return res;
}

//Total number of pairs with sum k
vector<pair<int,int>> allPairs(int a[], int b[], int n, int m, int x)
{
    unordered_map<int,int>mi;
    for(int i=0;i<n;i++){
        mi[a[i]]++;
    }
    vector<pair<int,int>>v;
    for(int i=0;i<m;i++){
        
        if(mi.find(x-b[i])!=mi.end()){
            v.push_back({x-b[i],b[i]});
        }
    }
    sort(v.begin(),v.end());
    return v;
} 
int main(){
    
    return 0;
}