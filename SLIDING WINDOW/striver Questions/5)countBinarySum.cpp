#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/binary-subarrays-with-sum/
int numSubarraysWithSum(vector<int> &a, int k)
{
    int n = a.size();
    int pf[n];
    pf[0] = a[0];
    unordered_map<int, int> m;
    //  m[pf[0]]++;
    for (int i = 1; i < n; i++)
    {
        pf[i] = pf[i - 1] + a[i];
        // m[pf[i]]++;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {

        // cout<<pf[i]<<" ";
        if (pf[i] == k)
        {
            res++;
            if ((pf[i] - k == 0) && (m.find(pf[i] - k) != m.end()))
            {
                res += m[pf[i] - k];
            }
        }
        else if (m.find(pf[i] - k) != m.end())
        {
            res += m[pf[i] - k];
        }

        m[pf[i]]++;
    }
    cout << endl;
    return res;
}
int main()
{

    return 0;
}