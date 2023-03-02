// https://www.youtube.com/watch?v=OnlgK0gjtB8&ab_channel=CodeWithHarry
#include<bits/stdc++.h>
#define ll long long
using namespace std;
//ALL OPERATIONS ARE DONE IN O(1)
class Deque{
    public:
        int *a;
        int size;
        int data;
        int rear;
        int front;
    Deque(int size){
        this->size=size;
        a = new int[size];
        rear = -1;
        front = -1;
    }
    void pushBack(int x){
        if(rear==size-1){
            cout<<"queue is fulll from back"<<endl;
            return;
        }
        if(front==-1){
            front=0;
        }
        rear++; 
        a[rear]=x;
        cout<<"Inserted value in back"<<x<<endl;
    
    }
    void pushFront(int x){
        if(front==-1){
            pushBack(x);
        }
        if(front==0){
            cout<<"queue is fulll from front"<<endl;
            return;
        }
        front--; 
        a[front]=x;
        cout<<"Inserted value from front "<<x<<endl;
    
    }
    int popFront(){
        if(rear==front){
            cout<<"queue is empty popfront"<<endl;
            return -1;
        }
        int val = a[front];
        front++;
        return val;
    }
    int popBack(){
        if(rear==front){
            cout<<"queue is empty popback"<<endl;
            return -1;
        }
        int val = a[rear];
        rear--;
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
        for(int i=front;i<=rear;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }

};
int main(){
    Deque q(5);
    q.popBack();
    q.popFront();
    q.pushBack(4);
    q.pushBack(5);
    q.pushBack(3);
    q.pushBack(2);
    q.printqueue();
    q.popFront();
    q.popFront();
    q.pushFront(7);
    q.pushFront(8);
    q.pushBack(10);
    q.popBack();
    q.printqueue();
    return 0;
}