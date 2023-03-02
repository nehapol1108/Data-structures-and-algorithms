#include <bits/stdc++.h>
#define ll long long
using namespace std;

class MyStack
{
public:
    queue<int> q1;
    MyStack()
    {
    }
    // O(N)->PUSH
    void push(int x)
    {
        q1.push(x);
        int n = q1.size() - 1;
        while (n--)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }
    // O(1)-POP()
    int pop()
    {
        if (q1.empty())
            return -1;
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
        ;
    }
};

int main()
{

    return 0;
}