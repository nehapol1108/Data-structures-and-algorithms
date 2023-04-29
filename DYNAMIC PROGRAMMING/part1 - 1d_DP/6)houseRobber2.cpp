#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/house-robber-ii/description/

//TC->O(N) 
//SC->O(2N)
//tabulation
int findMax(vector<int>a, int n) {
    int prev=a[0],prev2=0;
    for(int i=1;i<n;i++){
        int take = a[i];
        if(i>1){
            take += prev2;
        }
        int nottake = prev;
        int curr = max(take,nottake);
        prev2= prev;
        prev = curr;
    }
    return prev;
}
int rob(vector<int>&a) {
    int n =a.size();
    if(n==1)return a[0];
    vector<int>temp1,temp2;
    for(int i=0;i<n;i++){
        if(i!=0){temp1.push_back(a[i]);}
        if(i!=n-1){temp2.push_back(a[i]);}
    }
    return max(findMax(temp1,n-1),findMax(temp2,n-1));
}


//without using extra array
//TC->O(N) 
//SC->O(1)
//tabulation
int rob(vector<int>& nums) {    
    int n = nums.size();
    if(n==1){
        return nums[0];
    }
    int prev2=0;
    int prev=nums[0];
    for(int i=1;i<n-1;i++){
        int take = nums[i];
        if(i>1){
            take+= prev2;
        } 
        int not_take;
        not_take = prev;
            int curr = max(take,not_take);
        prev2 = prev;
        prev=curr;
        
        
    }
    prev2=0;
    int prev3=nums[1];
    for(int i=2;i<n;i++){
        int take = nums[i];
        if(i>1){
            take+= prev2;
        } 
        int not_take;
        not_take = prev3;
            int curr = max(take,not_take);
        prev2 = prev3;
        prev3=curr;
        
        
    }
    return max(prev,prev3);
}
int main(){
    
    return 0;
}