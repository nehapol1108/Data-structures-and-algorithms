#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
       
    }
    // O(1)->PUSH()
    void push(int x) {
       s1.push(x);
    }
    // O(N)->POP()
    int pop() {
        if(s1.empty()){
            return -1;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;

    }
    // O(N)->PEEK()
    int peek() {
        if(s1.empty()){
            return -1;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int val = s2.top();
        
       while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return val; 
    }
    
    
    bool empty() {
      
        return s1.empty();
    }
};


int main(){
    
    return 0;
}