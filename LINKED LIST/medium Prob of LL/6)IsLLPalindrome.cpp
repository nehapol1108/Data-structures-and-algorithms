#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=check-if-linked-list-is-pallindrome
class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data){
            this->data = data;
            next = NULL;
            prev=NULL;
        }
};


//Brute force would be to copy the linked list in another linked list and
//reverse it and check for palindrome TC->O(n) SC->O(n)

//Optimised
//TC->O(N)
//SC->O(1)
Node* reverseLinkedList(Node *start){
    Node *prev=NULL;
    Node *curr=start;
    while(curr!=NULL){
        Node *temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    if(head==NULL)return true;
    Node *fast=head;
    Node *slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    } 
    Node *end = reverseLinkedList(slow);
    
    Node *start=head;
    while(end!=NULL){
        if(start->data!=end->data){
            return false;
        }
        start=start->next;
        end=end->next;
    }
    return true;
} 
int main(){
    
    return 0;
}