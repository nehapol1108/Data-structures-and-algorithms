#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/middle-of-the-linked-list/
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next = NULL;
        }
};

//Brute force
//TC->O(n)+O(n/2)
//SC->O(1)
int getMiddle(Node *head)
{
    Node *curr=head;
    int n=0;
    while(curr!=NULL){
        curr=curr->next;
        n++;
    }
    curr=head;
    n=n/2;
    while(n--){
        curr=curr->next;
    }
    return curr->data;
}

//Tortoise hare method
//TC->O(n/2)
//SC->O(1)
int getMiddle(Node *head)
{
    Node *fast=head;
    Node *slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
}
int main(){
    
    return 0;
}