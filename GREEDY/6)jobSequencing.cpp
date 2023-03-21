#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Time Complexity: O(N log N) + O(N*M). => O(N^2)

// O(N log N ) for sorting the jobs in decreasing order of profit. O(N*M) since we are iterating through all N jobs and for every job we are checking from the last deadline, say M deadlines in the worst case.

// Space Complexity: O(M) for an array that keeps track on which day which job is performed if M is the maximum deadline available.
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
static bool comp(Job a,Job b){
    return a.profit>b.profit;
    
    
}
vector<int> JobScheduling(Job a[], int n) 
{ 
    vector<int>ans;
    sort(a,a+n,comp);
    int dead[n+1]={0};
    int profit=0,curr=1,count=0;
    for(int i=0;i<n;i++){
        for(int j=a[i].dead;j>0;j--){
            if(dead[j]==0){
                dead[j]=1;
                count++;
                profit += a[i].profit;
                break;
            }
        }
        
    }
    ans.push_back(count);
    ans.push_back(profit);
    return ans;
} 
int main(){
    
    return 0;
}