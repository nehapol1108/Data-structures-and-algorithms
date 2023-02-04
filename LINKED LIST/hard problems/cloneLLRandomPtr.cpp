#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Node{
    public:
        int val;
        Node *next,*random;
        Node(int data){
            val = data;
            next = NULL;
            random=NULL;
        }
};
//TC-O(N) SC->O(1)
Node* copyRandomList(Node* head) {
    Node* temp = head;
    while(temp!=NULL){
        Node* newnode = new Node(temp->val);
        newnode->next = temp->next;
        temp->next = newnode;
        temp = temp->next->next;
    }
    
    //step2
    Node *itr = head;
    while(itr!=NULL){
        if(itr->random!=NULL){
            itr->next->random = itr->random->next;
        }
        itr=itr->next->next;
    }
    //step 3
    Node *dummy =new Node(-1);
    temp=dummy;
    itr = head;
    Node *fast;
    while(itr!=NULL){
        fast = itr->next->next;
        temp->next = itr->next;
        temp = temp->next;
        itr->next=fast;
        itr = fast;
    }
    return dummy->next;
} 

//TC-O(N) SC->O(N)
Node* copyRandomList(Node* head) {
    unordered_map<Node*,Node*> hashMap;
    Node* temp = head;
    while(temp!=NULL){
        Node* newNode = new Node(temp->val);
        hashMap[temp] = newNode;
        temp = temp->next;
    }
    Node* t = head;
    while(t!=NULL){
        Node* node = hashMap[t];
        node->next = (t->next!=NULL?hashMap[t->next]:NULL);
        node->random = (t->random!=NULL?hashMap[t->random]:NULL);
        t = t->next;
    }
    return hashMap[head];
}
int main(){
    
    return 0;
}