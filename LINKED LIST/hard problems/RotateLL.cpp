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

ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL ||k==0 || head->next==NULL){
        return head;
    }
    int len=1;
    ListNode* temp = head;
    while(temp->next!=NULL){
        len++;
        temp = temp->next;
    }
    temp->next=head;
    k = k%len;
    k = len-k-1;
    temp = head;
    while(k--){
        temp = temp->next;
    }
    head = temp->next;
    temp->next=NULL;
    return head;
}
int main(){
    
    return 0;
}