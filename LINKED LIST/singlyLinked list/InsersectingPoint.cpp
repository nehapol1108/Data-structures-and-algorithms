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
//tc - O(N) sc - O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *d1 = headA;
    ListNode *d2 = headB;
    int n1=0,n2=0;  
    while(d1!=NULL){
        n1++;
        d1 = d1->next;    
    }
    while(d2!=NULL){
        n2++;
        d2 = d2->next;
    }
    int d=0,big;
    if(n1>=n2){
        d = n1-n2;
        big = 1;
    }else{
        d = n2-n1;
        big = 2;
    }
    d1 = headA;
    d2 = headB;
    if(big==1){
        while(d--){
            d1 = d1->next;    
        }
        while(d1!=NULL && d2!=NULL){
            if(d1==d2){
                return d1;
            }
            d2 = d2->next;
            d1 = d1->next;  
        }
    }else{
        while(d--){
            d2 = d2->next;    
        }
        while(d1!=NULL && d2!=NULL){
            if(d1==d2){
                return d1;
            }
            d2 = d2->next;
            d1 = d1->next;  
        }
    }
    return NULL;
}

//tc - O(N+M) sc - O(N)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode *,int>m;
    ListNode *temp;
    ListNode *temp1 = headA;
    ListNode *temp2 = headB;
    while(temp1!=NULL){
        m[temp1]++;
        temp1 = temp1->next;
        
    }
    while(temp2!=NULL){
        if(m[temp2]){
            return temp2;
        }
        m[temp2]++;
        temp2 = temp2->next;
    }
    return NULL;
}
int main(){
    
    return 0;
}