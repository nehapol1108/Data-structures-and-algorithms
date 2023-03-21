#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.youtube.com/watch?v=dxVcMDI7vyI&ab_channel=takeUforward

// https://takeuforward.org/data-structure/minimum-number-of-platforms-required-for-a-railway/

// Time Complexity:O(2n) + O(nlogn) Sorting takes O(nlogn) and traversal of arrays takes O(n) so overall time complexity is O(nlogn).
// Space complexity: O(1)  (No extra space used).

//keeping the count of platforms currently needed and then updating the maximum
//we are sorting both arriving and departing array because we are just scrolling through the time in the day 

int findPlatform(int a[], int d[], int n)
{
    sort(a,a+n);
    sort(d,d+n);
    
    int i=1,j=0;
    int plat=1;
    int ans=1;
    while(i<n){
        if(a[i]<=d[j]){
            plat++;
            i++;
        }else{
            plat--;
            j++;
        }
        ans = max(ans,plat);
        
    }
    return ans;
}

// Time Complexity: O(n^2)  (due to two nested loops).
// Space Complexity: O(1)  (no extra space used).
int countPlatforms(int n,int arr[],int dep[])
 {
    int ans=1; //final value
    for(int i=0;i<=n-1;i++)
    {
        int count=1; // count of overlapping interval of only this   iteration
        for(int j=i+1;j<=n-1;j++)
        {
            if((arr[i]>=arr[j] && arr[i]<=dep[j]) ||
           (arr[j]>=arr[i] && arr[j]<=dep[i]))
           {
               count++;
           }
        }
        ans=max(ans,count); //updating the value
    }
    return ans;
 }
 
int main(){
    
    return 0;
}