#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next = NULL;
        }
};

//Non Recursive
//TC->O(N)
//SC->O(1)
Node* reverseList(Node *head)
{
    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL){
        Node* temp = curr->next;
        curr->next=prev;
        prev = curr;
        curr=temp;
    }
    return prev;
}

//Recursive
//TC->O(N)
//SC->O(N)
// https://www.youtube.com/watch?v=ugQ2DVJJroc&ab_channel=AnujBhaiya
Node* reverseListt(Node *head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *newhead  = reverseListt(head->next);
    Node *headNext = head->next;
    headNext->next = head;
    head->next=NULL;
    return newhead;
}

int main(){
    
    return 0;
}