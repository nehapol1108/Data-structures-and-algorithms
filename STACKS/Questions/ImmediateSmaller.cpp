#include <bits/stdc++.h>
#define ll long long
using namespace std;
void immediateSmaller(vector<int> &a, int n)
{
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        int val = a[i];
        if (!s.empty() && s.top() < a[i])
        {
            a[i] = s.top();
            s.pop();
        }
        else
        {
            a[i] = -1;
        }
        s.push(val);
    }
}
int main()
{

    return 0;
}
// Given an integer array Arr of size N.For each element in the array, check whether the right adjacent element(on the next immediate position) of the array is smaller.If next element is smaller, update the current index to that element.If not, then - 1.
//                                                                                                                                                   
// https://practice.geeksforgeeks.org/problems/immediate-smaller-element1142/1?utm_source=youtubeutm_medium=collab_striver_ytdescriptionutm_campaign=immediate-smaller-element