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
class Queue{
    public:
        int size;
        int data;
        node* rear;
        node* front;
        Queue(){
            rear = front = NULL;
            size=0;
        }
        void push(int x){
            node *newnode = new node(x);
            if(front==NULL){
                rear= newnode;
                front = newnode;
                return;
            }
            rear->next= newnode;
            rear = newnode;
        }
        int pop(){
            if(front==NULL){
                cout<<"queue is empty"<<endl;
                return -1;
            }
            int res = front->data;
            front = front->next;
            return res;
        }
        void printqueue(){
            node *temp = front;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
            return;
        }
};
int main(){
    Queue q;
    q.push(5);
    q.push(4);
    q.push(2);
    q.push(1);
    q.push(85);
    q.push(5);
    q.printqueue();
    q.pop();
    q.printqueue();
    
    return 0;
}