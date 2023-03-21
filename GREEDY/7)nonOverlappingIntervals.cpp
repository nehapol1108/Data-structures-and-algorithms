#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.youtube.com/watch?v=BTObFnHbD4U&ab_channel=TECHDOSE
int eraseOverlapIntervals(vector<vector<int>>& a) {
    sort(a.begin(),a.end());
    int count=0;
    int n=a.size();
    int left = 0,right=1;
    while(right<n){
        if(a[left][1]<=a[right][0]){  //non overlapping case
            left=right;
            right++;
        }else if(a[left][1]<=a[right][1]){ //overlapping case 1
            count++;
            right++;
        }else if(a[left][1]>a[right][1]){ //overlapping case 1
            count++;
            left=right;
            right++;
        }
    }
    return count;
}



bool comp(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}
class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int ans=-1;      
		if(intervals.size()==0) return 0;       
		sort(intervals.begin(),intervals.end(),comp);      //custom comperator is used.
		vector<int> prev= intervals[0];

		for(vector<int> i: intervals) {
			if(prev[1]>i[0]) {
				ans++;                //we dont update previous, because i[1] will be grater then prev[1]
			}else prev=i;           // we want the end point to be minimum
		}
		return ans;                 //ans was initially made -1 because our prev and intervals[0] will always match
	}
};
int main(){
    
    return 0;
}