#include<bits/stdc++.h>
#define ll long long
using namespace std;
class node{
    public:
        int data;
        node *next;
        node *prev;
        node(int data){
            this->data = data;
            next=NULL;
            prev =NULL;
        }
};

void deleteKeyNodes(node * &head, int x)
{
    node *temp = head;
    //if head is x
    while(temp->data==x){
        temp = temp->next;
        head = temp;
    }
    while(temp!=NULL){
        if((temp->next->data)==x && temp->next->next==NULL){
            temp->next=NULL;
            temp = temp->next;  
        }
        else if((temp->next->data)==x && temp->next->next!=NULL){
            node * temp2 = temp->next->next;
            temp->next = temp2;
            temp2->prev = temp;
        }else{
            temp = temp->next;  
        }
    }
   
}
int main(){
   
    return 0;
}