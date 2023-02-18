#include<bits/stdc++.h>
#define ll long long
using namespace std;
//TC->O(m+n) SC->O(1)
int kthElement(int a1[], int a2[], int n, int m, int k)
{
    int i=0,j=0,count=0,ans1=-1,ans2=-1;
    while(i<n && j<m && count<k){
        if(a1[i]<=a2[j]){
            count++;
            if(count==k){
                ans1=i;
            }
            i++;
            
        }else{
            count++;
            if(count==k){
                ans2=j;
            }
            
            j++;
        }
        
    }
    while(i<n && count<k){
        count++;
        if(count==k){
                ans1=i;
            }
        i++;
    }
    while(j<m && count<k){
        count++;
        if(count==k){
            ans2=j;
        }
            j++;
    }
    // cout<<ans<<endl;
    return ans1==-1?a2[ans2]:a1[ans1];
}

//TC->O(logn) SC->O(1)
int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if(n>m)
    {
        return kthElement(arr2, arr1, m, n, k);
    }
    long long low= max(0,k-m); int high=min(k,n);
    
    while(low<=high)
    {
        long long mid1 = low+(high-low)/2;
        long long mid2 = k-mid1;
        long long l1 = (mid1==0? INT_MIN : arr1[mid1-1]);
        long long l2 = (mid2==0? INT_MIN : arr2[mid2-1]);
        long long r1 = (mid1==n? INT_MAX : arr1[mid1]);
        long long r2 = (mid2==m? INT_MAX : arr2[mid2]);
        
        if(l1<=r2 && l2<=r1)
            return max(l1, l2);
        else if(l1>r2)
            high = mid1-1;
            else
            low = mid1+1;
    }
    return 1;
}
int main(){
    
    return 0;
}