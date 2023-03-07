#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N^2)
//SC->O(1)
long long subArrayRanges(vector<int>& nums) 
{
        long long ans =0;
        for(int i=0;i<nums.size();i++)
        {
            long long max = INT_MIN;
            long long min = INT_MAX;
            
            for(int j=i;j<nums.size();j++)
            {
                if(nums[j] > max)
                {
                    max = nums[j];	
                }
                if(nums[j] < min)
                {
                    min = nums[j];
                }
                ans = ans + (max - min);
            }	
        }    
        return ans;
}


//TC->O(4N)
//SC->O(N)
long long subArrayRanges(vector<int>&a) {
    int n=a.size();
    vector<int>prevsmaller(n,-1),nextsmaller(n,n),prevMax(n,-1),nextMax(n,n);
    stack<int>s;
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && a[s.top()]>a[i]){
            s.pop();
        }
        if(!s.empty()){
            nextsmaller[i] =s.top()-i;
        }else{
            nextsmaller[i] = nextsmaller[i]-i;
        }
        s.push(i);
    }
        while(!s.empty()){s.pop();}
    for(int i=n-1;i>=0;i--){
        
        while(!s.empty() && a[s.top()]<a[i]){
            s.pop();
        }
        if(!s.empty()){
            nextMax[i] =s.top()-i;
        }else{
            nextMax[i] = nextMax[i]-i;
        }
        s.push(i);
    }
        while(!s.empty()){s.pop();}

    for(int i=0;i<n;i++){
        while(!s.empty() && a[s.top()]>=a[i]){
            s.pop();
        }
        if(!s.empty()){
            prevsmaller[i] =i-s.top();
        }else{
            prevsmaller[i] = i-prevsmaller[i];
        }
        s.push(i);
    }
        while(!s.empty()){s.pop();}
    for(int i=0;i<n;i++){
        while(!s.empty() && a[s.top()]<=a[i]){
            s.pop();
        }
        if(!s.empty()){
            prevMax[i] =i-s.top();
        }else{
            prevMax[i] = i-prevMax[i];
        }
        s.push(i);
    }
    
    long long ans=0;
    long long mod = 1e9+7;
    for(int i=0;i<n;i++){
        // ans+=(a[i]%mod*((prevsmaller[i]+1)%mod*(nextsmaller[i]+1)%mod)%mod)%mod;
        long long leftMin=prevsmaller[i],rightMin=nextsmaller[i];
        long long leftMax=prevMax[i],rightMax=nextMax[i];
        ans+=(leftMax*rightMax-leftMin*rightMin)*a[i];
        
    }
    
    return ans;
} 
int main(){
    
    return 0;
}