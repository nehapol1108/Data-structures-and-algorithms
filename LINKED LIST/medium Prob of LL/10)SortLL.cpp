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

//TC->O(NlogN) SC->O(N)
ListNode * merge(ListNode * &left,ListNode * &right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    ListNode * ans = new ListNode(-1);
    ListNode * temp = ans;
    while(left!=NULL && right!=NULL){
        if(left->val<right->val){
            temp->next = left;
            temp = left;
            left = left->next;
            
        }else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while(left!=NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }
        while(right!=NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}
ListNode * findMid(ListNode* &head){
    ListNode* fast= head->next;
    ListNode* slow= head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
ListNode* sortList(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode* mid = findMid(head);
    ListNode* left = head;
    ListNode* right = mid->next;
    mid->next=NULL;
    left = sortList(left);
    right = sortList(right);
    ListNode *result = merge(left,right);
    return result;
    
} 
int main(){
    
    return 0;
}