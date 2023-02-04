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
void reverse(ListNode* &s, ListNode *&e) {
    ListNode * prev=NULL;
    ListNode *curr = s;
    ListNode *nextp=s->next;
    while(prev!=e){
        curr->next = prev;
        prev = curr;
        curr = nextp;
        if(nextp!=NULL){
            nextp=nextp->next;
        }
    }          
}
ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==NULL || head->next==NULL || k==1){
        return head;
    }
    ListNode* dummy=new ListNode(-1);
    dummy->next = head;
        ListNode *beforestart = dummy;
    ListNode *e=head;
    int i=0;
    while(e!=NULL){
        i++;
        if((i%k)==0){
            ListNode *s = beforestart->next;
            ListNode *temp = e->next;
            reverse(s,e);
            beforestart->next=e;
            s->next = temp;
            beforestart = s;
            e = temp;
        }else{
            e=e->next;
        }
    }
    return dummy->next;
    
}
int main(){
    
    return 0;
}