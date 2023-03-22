#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC->O(N^2) SC->O(N)
void insert(stack<int>&s,int temp){
    if(s.size()==0 || s.top()<=temp){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
}
void sort(stack<int>&s){
    if(s.size()==1){
        return;
    }
    int temp = s.top();
    s.pop();
    sort(s);
    insert(s,temp);
}
int main(){
    stack<int>s;
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(1);
    s.push(4);
    s.push(3);
    sort(s);
    while(s.size()>0){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
    
}
// The idea of the solution is to hold all values in Function Call Stack until the stack becomes empty. When the stack becomes empty, insert all held items one by one in sorted order. Here sorted order is important.
// Illustration: 

// Let given stack be
// -3    <-- top of the stack
// 14
// 18
// -5
// 30 
// Let us illustrate sorting of stack using the above example:
// First pop all the elements from the stack and store popped element in the variable ‘temp’. After popping all the elements function’s stack frame will look like this:

// temp = -3    --> stack frame #1
// temp = 14    --> stack frame #2
// temp = 18    --> stack frame #3
// temp = -5    --> stack frame #4
// temp = 30    --> stack frame #5
// Now stack is empty and ‘insert_in_sorted_order()’ function is called and it inserts 30 (from stack frame #5) at the bottom of the stack. Now stack looks like the below:

// 30    <-- top of the stack 
// Now next element i.e. -5 (from stack frame #4) is picked. Since -5 < 30, -5 is inserted at the bottom of the stack. Now stack becomes: 

// 30    <-- top of the stack
// -5
// Next 18 (from stack frame #3) is picked. Since 18 < 30, 18 is inserted below 30. Now stack becomes:

// 30    <-- top of the stack
// 18    
// -5
// Next 14 (from stack frame #2) is picked. Since 14 < 30 and 14 < 18, it is inserted below 18. Now stack becomes: 

// 30    <-- top of the stack
// 18
// 14    
// -5
// Now -3 (from stack frame #1) is picked, as -3 < 30 and -3 < 18 and -3 < 14, it is inserted below 14. Now stack becomes:

// 30    <-- top of the stack
// 18
// 14
// -3    
// -5