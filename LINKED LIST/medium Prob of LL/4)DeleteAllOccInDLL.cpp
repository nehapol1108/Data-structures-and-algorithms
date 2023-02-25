#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://practice.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list
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

//TC->O(N)
//SC->O(1)
void deleteAllOccurOfX(Node* head, int x) {
    if(head==NULL)return;
    Node *temp=head;
    Node *prev=NULL;
    while(temp!=NULL){
        if(temp->data==x){
            if(temp==head){ //when it is the first node
                head=temp->next;
            }else if(temp->next==NULL){   //when it is the last node
                prev=temp->prev;
                prev->next=NULL;
            }else{   //when it is the middle node
                prev=temp->prev;
                prev->next=temp->next;
                temp->next->prev=prev;
            }
        }
        temp=temp->next;
    }
} 
int main(){
    
    return 0;
}