#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Solution 1: Brute-Force
// Time Complexity: O(n^3)
// Space Complexity : O(3*k) // k is the no.of triplets

vector<vector<int>> threeSum(vector<int>&a) {
    int n = a.size();
    set<vector<int>>v;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if((a[i]+a[j]+a[k])==0){
                    vector<int>temp;
                    temp.push_back(a[i]);
                    temp.push_back(a[j]);
                    temp.push_back(a[k]);
                    sort(temp.begin(),temp.end());
                    v.insert(temp);
                    break;
                }
            }
                
        }
    }
    vector<vector<int>>ans;
    for(auto i:v){
        ans.push_back(i);
    }
    return ans;
}

// Solution 2
// Time Complexity: O(n^2 )
// Space Complexity : O(3*k) // k is the no.of triplets
vector<vector<int>> threeSum(vector<int>&a) {
    int n = a.size();
    unordered_map<int,int>m;
    set<vector<int>>v;
    sort(a.begin(),a.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }

    for(int i=0;i<n;i++){
        m[a[i]]--;
        for(int j=i+1;j<n;j++){
            m[a[j]]--;
            vector<int>temp;
            int sum = 0-(a[i]+a[j]);
            if(m[sum]>0){
                temp.push_back(a[i]);
                temp.push_back(a[j]);
                temp.push_back(sum);
                sort(temp.begin(),temp.end());
                v.insert(temp);
            }
            
            m[a[j]]++;
            
        }
            m[a[i]]++;
    }
        for(auto i:v){
        ans.push_back(i);
    }
    return ans;
}

//solution 3: two pointer approach
// Time Complexity: O(n^2)
// Space Complexity:  O(3*k)  // k is the no.of triplets. 
vector<vector<int>> threeSum(vector<int>&a) {
    int n = a.size();
    vector<vector<int>>ans;
    sort(a.begin(),a.end());
    for(int i=0;i<n-2;i++){
        int num = -a[i];
        int low = i+1,high=n-1;
        if(i==0 || (i>0 && a[i]!=a[i-1])){
            while(low<high){
                if((a[low]+a[high])==num){
                    vector<int>temp;
                    temp.push_back(a[i]);
                    temp.push_back(a[low]);
                    temp.push_back(a[high]);
                    ans.push_back(temp);
                    while(low<high && a[low]==a[low+1]){
                        low++;
                    }
                    while(low<high && a[high]==a[high-1]){
                        high--;
                    }
                    low++;
                    high--;
                }else if((a[low]+a[high])>num){
                    high--;
                }else{
                    low++;
                }
            }
        }
    }
    return ans;
}
int main(){
    
    return 0;
}