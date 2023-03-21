#include <bits/stdc++.h>
#define ll long long
using namespace std;

// https://leetcode.com/problems/find-right-interval/solutions/814263/c-using-map-and-bainary-search/

//TC->O ( N log N ) SC->O(N)
// https://leetcode.com/problems/find-right-interval/description/
vector<int> findRightInterval(vector<vector<int>> &intervals)
{
    vector<int> ans(intervals.size());
    map<int, int> m;
    for (int i = 0; i < intervals.size(); i++)
        m[intervals[i][0]] = i;
    for (int i = 0; i < intervals.size(); i++)
        ans[i] = m.lower_bound(intervals[i][1]) != end(m) ? m.lower_bound(intervals[i][1])->second : -1;
    return ans;
}
int main()
{

    return 0;
}