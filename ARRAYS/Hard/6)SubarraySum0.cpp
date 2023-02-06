#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?category[]=Hash&category[]=Hash&company[]=Amazon&company[]=Amazon&page=1&query=category[]Hashcompany[]Amazonpage1company[]Amazoncategory[]Hash&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-subarray-with-0-sum

//solution of Largest subarray with 0 sum
// Time Complexity: O(nlogn)
// Space Complexity:  O(n)  
int maxLen(vector<int>&a, int n)
{   
    
    unordered_map<int,int>m;
    int sum=0;
    int maxlen=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum==0){
            maxlen = i+1;
        }else{
            if(m.find(sum)!=m.end()){
                maxlen = max(maxlen,i-m[sum]);
            }else{
                m[sum]=i;
            }
        }
        
    }
    return maxlen;
} 
int main(){
    
    return 0;
}