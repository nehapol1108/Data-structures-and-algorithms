#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://practice.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-length-of-loop
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next = NULL;
        }
};
//for brute force SC->O(n)

//optimised
//TC->O(N) + O(N)+O(N) ~ O(n)
//SC->O(1 )
Node * detectcycle(Node *head){
    Node *fast=head;
    Node *slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return slow;
        }
    }
    return NULL;
}
int countNodesinLoop(struct Node *head)
{
    Node * detect = detectcycle(head);
    if(detect==NULL){
        return 0;
    }
    int count=1;
    Node *start=head;
    while(start!=detect){
        start=start->next;
        detect=detect->next;
    }
    start=start->next;
    while(start!=detect){
        start=start->next;
        count++;
    }
    return count;
    
} 
int main(){
    
    return 0;
}