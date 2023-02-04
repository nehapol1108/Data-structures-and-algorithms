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
            next=NULL;
            prev =NULL;
        }
};
Node* reverseDLL(Node * head)
{
    Node *pre = NULL;
    Node *curr = head;
    while(curr!=NULL){
        Node *temp =curr->next;
        curr->next = pre;
        curr->prev = temp;
        pre = curr;
        curr = temp;       
    }
    return pre;
}
int main(){
    
    return 0;
}