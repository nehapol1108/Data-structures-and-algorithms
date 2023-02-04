//get the maximum sum of k size subarray from the array
#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int i=0,j=0,sum=0,maxi=INT_MIN;
    while(j<n){
        sum+=a[j];
        if((j-i+1)<k){
            j++;
        }else if((j-i+1)==k){
            maxi = max(maxi,sum);
            sum-=a[i];
            i++;
            j++;
        }
    }
    cout<<maxi<<endl;
    return 0;
}