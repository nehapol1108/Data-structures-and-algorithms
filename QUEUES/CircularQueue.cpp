#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
        rear = -1;
        front = -1;
    }
    void push(int x){
        if((rear+1)%size == front){
            cout<<"queue is full"<<endl;
            return;
        }
        if(front==-1){  //incase the queue is empty
            front=0;
        }
        rear=(rear+1)%size; 
        a[rear]=x;
        cout<<"Inserted value "<<x<<endl;
        // incase the rear is intialized with 0
        // a[rear]=x;
        // rear++;
    }
    int pop(){
        if(front==-1){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        int val = a[front];
        if(front==rear){
            front = rear = -1;
        }else{
            front = (front+1)%size;
        }
        return val;
    }
    void getfront(){
        if(rear==-1){
            cout<<"queue is empty"<<endl;
            return ;
        }
        cout<<"front "<<a[front]<<endl;
    }
    void printqueue(){
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
                cout<<a[i]<<" ";
        }else{
            for(int i=front;i<size;i++){
                cout<<a[i]<<" ";
            }
            for (int i = 0; i <= rear; i++){
                    cout<<a[i]<<" ";
            }
        }
        
        cout<<endl;
        return;
    }

};
int main(){
    Queue q(5);
    q.push(5);
    q.push(4);
    q.push(2);
    q.push(1);
    q.push(85);
    q.push(5);
    q.printqueue();
    q.pop();
    q.pop();
    q.pop();
    q.push(21);
    q.push(6);
    q.printqueue();
    q.pop();
    q.printqueue();
    q.pop();
    q.printqueue();
    q.getfront();
    return 0;
}