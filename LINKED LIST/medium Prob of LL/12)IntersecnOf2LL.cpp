#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next = NULL;
        }
};

//1st approach 
//to check for each node of LL1 if present in LL2
//TC->O(n*m) SC->O(1)

// 2nd approach
//TC->O(m+n) SC->O(n)
Node *getIntersectionNode(Node *headA, Node *headB) {
    unordered_map<Node *,int>m;
    Node *temp;
    Node *temp1 = headA;
    Node *temp2 = headB;
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


//3rd approach
//TC->O(m)+O(m-n) + O(n) ~ O(2m) SC->O(1)
Node *func(Node *d1,Node *d2,int n,int m){
    int num=n-m;
    while((num)--){
        d1=d1->next;
    }
    while(d1!=NULL && d2!=NULL){
        if(d1==d2){
            cout<<d1->data;
            return d1;
        }
        d1=d1->next;
        d2=d2->next;
    }
    return NULL;
}
Node* findIntersection(Node* headA, Node* headB)
{
    if(headA== NULL || headB==NULL){
        return NULL;
    }
    int n=0,m=0;
    Node *d1 = headA;
    Node *d2 = headB;
    while(d1!=NULL){
        d1=d1->next;
        n++;
    }
    while(d2!=NULL){
        d2=d2->next;
        m++;
    }
    
    if(n>=m){
        return func(headA,headB,n,m);
    }
    return func(headB,headA,m,n);
}

//4th approach
//TC->O(N) SC->O(1)
Node* findIntersection(Node* headA, Node* headB)
{
    if(headA== NULL || headB==NULL){
        return NULL;
    }
    Node *d1 = headA;
    Node *d2 = headB;
    while(d1!=d2){
        if(d1==NULL){
            d1 = headB;
        }else{
            d1 = d1->next;
        }
        if(d2==NULL){
            d2 = headA;
        }else{
            d2 = d2->next;
        }
    }
    return d1;
}
int main(){
    
    return 0;
}