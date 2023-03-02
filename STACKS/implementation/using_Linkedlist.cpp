#include<bits/stdc++.h>
#define ll long long
using namespace std;
class node{
    public:
        int data;
        node *next;
        node(int data){
            this->data = data;
            next = NULL;
        }
};
class Stack{
    public:
    int size;
    node *top;
        Stack(){
            top = NULL;
            size=0;
        }
        void push(int data){
            node *ele = new node(data);
            ele->next = top;
            top = ele;
            cout << "Element pushed" << "\n";
            size++;
        }
        int pop(){
            if(top==NULL){
                cout<<"empty"<<endl;
                return;
            }
            node * temp = top;
            int val = top->data;
            top = top->next;
            size--;
            delete temp;
            return val;
        }
        bool isEmpty(){
            return top == NULL;
        }
        int size(){
            return size;
        }
        int stackPeek() {
            if (top == NULL) return -1;
            return top -> data;
        }
        bool stackIsEmpty() {
            return top == NULL;
        }
        void printStack() {
            node * current = top;
            while (current != NULL) {
            cout << current -> data << " ";
            current = current -> next;
            }
        }
};
int main(){
    Stack s;
    s.push(10);
    cout << "Element popped: " << s.pop() << "\n";
    cout <<"Stack empty or not? "<<s.stackIsEmpty()<<"\n";
    cout << "stack's top element: " << s.stackPeek() << "\n";
    return 0;
}