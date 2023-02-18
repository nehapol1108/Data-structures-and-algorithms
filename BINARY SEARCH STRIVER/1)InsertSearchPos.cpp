#include<bits/stdc++.h>
#define ll long long
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int low =0,high = nums.size()-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(target==nums[mid]){
            return mid;
        }
        else if(target<nums[mid]){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout<<mid<<endl;
    if(nums[mid]>target){
        return mid;
        }
    else{
        return mid+1;
    }
} 
int main(){
    
    return 0;
}