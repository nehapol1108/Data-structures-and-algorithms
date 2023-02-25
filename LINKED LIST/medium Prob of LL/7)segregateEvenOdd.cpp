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
// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=segregate-even-and-odd-nodes-in-a-linked-list

// https://www.youtube.com/watch?v=Gm8gHjYyNwo&ab_channel=Yogesh%26Shailesh%28CodeLibrary%29

//gfg TC->O(N) SC->O(1)
Node* divide(int N, Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *evenl=NULL;
    Node *oddl=NULL;
    Node *even=NULL;
    Node *odd=NULL;
    Node *curr=head;
    while(curr!=NULL){
        if((curr->data)%2==0){
            if(even==NULL){
                even=curr;
                evenl=curr;
            }else{
                evenl->next=curr;
                evenl=evenl->next;
            }
        }else{
            if(odd==NULL){
                odd=curr;
                oddl=curr;
            }else{
                oddl->next=curr;
                oddl=oddl->next;
            }
        }
        curr=curr->next;
    }
    if(evenl!=NULL){
            evenl->next=odd;
    }
    if(oddl!=NULL){
        oddl->next=NULL;
    }
    if(even)return even;
    return odd;
}


// https://leetcode.com/problems/odd-even-linked-list/description/
//leetcode TC->O(N) SC->O(1)
Node* oddEvenList(Node* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *odd = head;
    Node *even = head->next;
    Node *evenstart = head->next;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
        
    }
    odd->next = evenstart;
    if(odd->next==NULL){
        even->next=NULL;
    }
    return head;
    
    
}
int main(){
    
    return 0;
}