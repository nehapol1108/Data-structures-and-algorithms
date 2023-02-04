#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Stack{  
    public:
    int *a;
    int size;
    int top;
        Stack(){
            top = -1;
            size=1000;
            a = new int[size];
        }
    void push(int x) {
        if(top==size-1){
            cout<<"stack is full"<<endl;
            return;
        }
        top++;
        a[top] = x;
    }
    int pop() {
        if(top==-1){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        int x = a[top];
        top--;
        return x;
    }
    int Top() {
        return a[top];
    }
    int Size() {
        return top + 1;
    }
};
int main(){
    Stack s;
    s.push(6);
    s.push(3);
    s.push(7);
    cout << "Top of stack is before deleting any element " << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;
    return 0;
}