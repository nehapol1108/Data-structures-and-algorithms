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

//TC->O(N)
//SC->O(N)
bool detectLoop(Node* head)
{
    if(head==NULL || head->next==NULL){
        return false;
    }
    Node *temp=head;
    unordered_map<Node*,int>m;
    while(temp->next!=NULL){
        if(m[temp])return true;
        m[temp]++;
        temp=temp->next;
    }
    return false;
} 

// https://www.youtube.com/watch?v=jcZtMh_jov0&ab_channel=AnujBhaiya
//Floyd cycle detection algo 
//TC->O(N)
//SC->O(1)
bool detectLoopByFloydCycle(Node* head)
{
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}




//how to detect meeting point of cycle
Node* GetSlowPtr(Node* head)
{
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}
Node* getMeetPoint(Node *head)
{
    Node *meet = GetSlowPtr(head);
    Node *start=head;
    while(start!=meet){
        start=start->next;
        meet=meet->next;
    }
    return start;
}

//how to remove a cycle
Node* getPrevOfSlow(Node* head)
{
    Node* fast=head;
    Node* slow=head;
    Node* prev=NULL;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        prev=slow;
        slow=slow->next;
        if(slow==fast){
            return prev;
        }
    }
    return NULL;
}
Node* removeCycle(Node *head)
{
    Node *prev = getPrevOfSlow(head);
    Node *meet = prev->next;
    Node *start=head;
    while(start!=meet){
        start=start->next;
        meet=meet->next;
        prev=prev->next;
    }
    prev->next=NULL;
    return head;
}
int main(){
    
    return 0;
}