#include<bits/stdc++.h>
#define ll long long
using namespace std;

//ALL OPERATIONS ARE O(1)
// Time complexity: All the operations have O(1) time complexity.
// Auxiliary Space: O(N) 
class Queue{
    public:
        int *a;
        int size;
        int data;
        int rear;
        int front;
    Queue(int size){
        this->size=size;
        a = new int[size];
        rear = 0;
        front = 0;
    }
    void push(int x){
        if(rear==size){
            cout<<"queue is fulll"<<endl;
            return;
        }
        a[rear]=x;
        rear++; 
        cout<<"Inserted value "<<x<<endl;
    
    }
    int pop(){
        if(rear==front){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        int val = a[front];
        front++;
        return val;
    }
    int getfront(){
        if(rear==front){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return a[front];
    }
    void printqueue(){
        for(int i=front;i<rear;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }

};
int main(){
    Queue q(5);
    q.pop();
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