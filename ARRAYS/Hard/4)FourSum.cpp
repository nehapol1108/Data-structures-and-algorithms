#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Solution 1: Brute-Force
// Time Complexity: O(N log N + N³ logN)
// Space Complexity : O(4*k) (extra)

vector<vector<int>> fourSum(vector<int>&a, long long int target) {
    int n = a.size();
    set<vector<int>>temp;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                long long x = (long long)target - (long long)a[i]- (long long)a[j]-(long long)a[k];
                if(binary_search(a.begin()+k+1,a.end(),x)){
                    vector<int>v;
                    v.push_back(a[i]);
                    v.push_back(a[j]);
                    v.push_back(a[k]);
                    v.push_back(x);
                    temp.insert(v);
                }
            }
        }
    }
    vector<vector<int>> res(temp.begin(),temp.end());
    return res;
}

// Solution 2
// Time Complexity: O(n^2 )
// Space Complexity : O(4*k) // k is the no.of triplets
vector<vector<int>> fourSum(vector<int>&a, long long int target) {
    int n = a.size();
    vector<vector<int>> res;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int low = j+1,high=n-1;
            long long find = target-a[i]-a[j];
            while(low<high){
                if((a[low]+a[high])==find){
                    vector<int>v;
                    v.push_back(a[i]);
                    v.push_back(a[j]);
                    v.push_back(a[low]);
                    v.push_back(a[high]);
                    res.push_back(v);
                    while(low<high && a[low]==v[2]){
                        low++;
                    }
                    while(low<high && a[high]==v[3]){
                        high--;
                    }
                }else if((a[low]+a[high])>find){
                    high--;
                }else{
                    low++;
                }
            }
            while(j+1<n && a[j]==a[j+1]){
                j++;
            }
        }
        while(i+1<n && a[i]==a[i+1]){
            i++;
        }
    }
    
    return res;
}


int main(){
    
    return 0;
}