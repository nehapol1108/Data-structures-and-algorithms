#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/max-consecutive-ones-iii/description/
//TC->O(N) SC->O(1)
int longestOnes(vector<int>&a, int k){
    int i=0,j=0,maxi =0,sum=0,num=k;
    int count=0;
    while(j<a.size()){
        if(a[j]==0){
            num=num-1;
        }
        if(num>=0 && num<=k){
            maxi = max(maxi,(j-i+1));
            
        }else if(num<0){
                while(num<0){
                    if(a[i]==0){
                    num++;
                }
                i++;
            }
        }
        j++;
    }
    return maxi;
} 
int main(){
    
    return 0;
}