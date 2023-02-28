#include<bits/stdc++.h>
#define ll long long
using namespace std;
class ListNode{
    public:
        int val;
        ListNode *next;
        ListNode(int data){
            val = data;
            next = NULL;
        }
};
//recursive TC- O(N) SC- O(N/K)
ListNode* reverseK(ListNode* head, int k,int len) {
    if(len<k){
        return head;
    }
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* nextp;
    int count=0;
    while(curr!=NULL && count<k){
        nextp = curr->next;
        curr->next = prev;
        prev = curr;
        curr  = nextp;
        count++;
    }
    if(nextp!=NULL){
        head->next = reverseK(nextp,k,len-k);
    }
    return prev;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* curr=head;
    int count=0;
    while(curr!=NULL){
        curr  = curr->next;
        count++;
    }
    return reverseK(head,k,count);
}


//iterative recursive TC- O(N) SC- O(1)
ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL||head->next == NULL) return head;
    int len = 0;
    ListNode *curr=head;
    while(curr!=NULL){
        len++;
        curr=curr->next;
    }

    ListNode *dummy = new ListNode(-1);
    dummy->next=head;
    ListNode *prev=dummy;
    curr=dummy;
    ListNode *nex=dummy;
    while(len>=k){
        curr = prev->next;
        nex = curr->next;
        for(int i=1;i<k;i++){
            curr->next = nex->next;
            nex->next=prev->next;
            prev->next=nex;
            nex=curr->next;
        }
        prev =curr;
        len-=k;
    }
    return dummy->next;
}
int main(){
    
    return 0;
}