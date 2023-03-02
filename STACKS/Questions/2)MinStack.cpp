#include<bits/stdc++.h>
#define ll long long
using namespace std;

//ALL OPERATIONS ARE OF O(1)
class MinStack {
public:
    stack <long long> st;
    long long mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        long long val = value;
        if(st.empty()){
            mini=val;
            st.push(val);
        }else if(val>=mini){
            st.push(val);
        }else{
            st.push(2*val-mini);
            mini = val;
        }   
    }
    
    void pop() {
        if(st.top()<mini){
            mini = 2*mini-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }else{
            if(st.top()>=mini){
                return st.top();
            }else{
                return mini;
            }
        }
    }
    
    int getMin() {
        return mini;
    }
};

 
int main(){
    
    return 0;
}