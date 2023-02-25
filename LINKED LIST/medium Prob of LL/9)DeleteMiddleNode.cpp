#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
        Node(){
            next = NULL;
            prev=NULL;
        }
};
//Brute force -> to find len of LL and then traverse till N/2 and delete that node TC->O(N+N/2) SC->O(1)

//Optimised
//TC->O(n/2) SC->O(1)
Node* deleteMid(Node* head)
{
    Node *slow=head;
    Node *fast=head;
    Node *prev=NULL;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        prev=slow;
        slow=slow->next;
    }
    prev->next=prev->next->next;
    return head;
} 
int main(){
    
    return 0;
}