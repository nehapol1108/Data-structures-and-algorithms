#include<bits/stdc++.h>
#define ll long long
using namespace std;
//size of largest subarrray of sum K 

//when there are negative elements in the array
//TC->O(N)  SC->O(N)
int lenOfLongSubarr(int arr[],  int n, int k) 
{ 
    unordered_map<int, int> mp;
    mp[0] = -1;
    int ans=0, sum =0;
    for(int i=0; i < n; i++){
        sum +=arr[i];
        if(mp.find(sum -k) != mp.end()){
            ans = max(ans, i - mp[sum -k]);
        }
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }
    return ans;
}

//when there are only positive integers ->sliding window
//TC->O(N)  SC->O(1)
int lenOfLongSubarr2(int a[],  int n, int k) 
{ 
    int i=0,j=0,sum=0,ans=-1;
    while(j<n){
        sum+=a[j];
        if(sum<k){
            j++;
        }else if(sum==k){
            ans = max(ans,j-i+1);
            j++;
        }else if(sum>k){
            while(sum>k){
                sum-=a[i];
                i++;
            }
            if(sum==k){
                ans = max(ans,j-i+1);
            }
            j++;
        }
    }
    return ans;
} 
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    return 0;
}