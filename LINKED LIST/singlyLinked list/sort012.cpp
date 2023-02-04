#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            data = data;
            next = NULL;
        }
};
//brute 
Node* segregate(Node* head) {
    int c0=0,c1=0,c2=0;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==0){
            c0++;
        }else if(temp->data==1){
            c1++;
        }
        else if(temp->data==2){
            c2++;
        }
        temp = temp->next;
    }
    temp = head;
    while(c0--){
        temp->data = 0;
        temp = temp->next;
    }
    while(c1--){
        temp->data = 1;
        temp = temp->next;
    }
    while(c2--){
        temp->data = 2;
        temp = temp->next;
    }
    return head;
} 
int main(){
    
    return 0;
}