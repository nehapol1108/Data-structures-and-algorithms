#include <bits/stdc++.h>
#define ll long long
using namespace std;
void PreviousSmaller(vector<int> &a, int n)
{
    stack<int> s;
    for (int i = 0; i <n; i++)
    {
        int val = a[i];
        while (!s.empty() && s.top() >= a[i])
        {
            s.pop();
        }
        if(s.empty()){
            cout<<-1<<" ";
        }else{
            cout<<s.top()<<" ";
        }
        s.push(val);
    }
    cout<<endl;
}
int main()
{
    vector<int>a = {4,10,5,8,20,15,3,12};
    PreviousSmaller(a,8);
    return 0;
}
