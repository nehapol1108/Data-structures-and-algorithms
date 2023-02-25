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
};

//leetcode wala
//TC-> O(MAX(n1,n2) ) n1=len of l1 and m=len of l2
Node* addTwoNumbers(Node* l1, Node* l2) {
        Node * dummy = new Node(-1);
        Node *temp = dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry==1){
            int sum=0;
            if(l1!=NULL){
                sum+= l1->data;
                l1 = l1->next;
            }
            if(l2!=NULL){
                sum+= l2->data;
                l2 = l2->next;
            }
            sum+=carry;
            carry = sum/10;
            Node *node = new Node(sum%10);
            temp->next= node;
            temp = temp->next;
        }
        return dummy->next;
    }

//github wala
struct Node* reverse(struct Node *head){
    Node *prev=NULL;
    Node *curr=head;
    while(curr!=NULL){
        Node *temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
struct Node* addTwoLists(struct Node* l1, struct Node* l2)
{
    l1=reverse(l1);
    l2=reverse(l2);
    struct Node * dummy = new Node(-1);
    struct Node* temp=dummy;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry>0){
        int sum=0;
        if(l1!=NULL){
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->data;
            l2=l2->next;
        }
        sum+=carry;
        carry = sum/10;
        struct Node *newnode = new Node(sum%10);
        temp->next = newnode;
        temp=temp->next;
    }
    dummy->next=reverse(dummy->next);
    return dummy->next;
}

int main(){
    
    return 0;
}