// https://leetcode.com/problems/implement-stack-using-queues/submissions/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
class MyStack {
public:
    queue<int>q1,q2;
    MyStack() {
       
    }
    //O(N)->PUSH
    void push(int x) {
       while(!q1.empty()){
           q2.push(q1.front());
           q1.pop();
       }
        q1.push(x);
         while(!q2.empty()){
           q1.push(q2.front());
            q2.pop();
       }
        
    }
    //O(1)-POP()
    int pop() {
        int val=q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
      
        return q1.empty();;
    }
};


int main(){
    
    return 0;
}