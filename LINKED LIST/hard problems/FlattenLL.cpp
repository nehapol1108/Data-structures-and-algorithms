#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Node{
    public:
        int data;
        Node *next,*bottom;
        Node(int data){
            data = data;
            next = NULL;
            bottom=NULL;
        }
};
Node * mergeLL(Node *a,Node *b){
    Node *temp = new Node(0);
    Node * res = temp;
    while(a!=NULL && b!=NULL){
        if(a->data<b->data){
            temp->bottom=a;
            temp=a;
            a=a->bottom;
        }else{
            temp->bottom=b;
            temp=b;
            b=b->bottom;
        }
    }
    while(a!=NULL){
        temp->bottom=a;
        temp=a;
        a=a->bottom;
    }
    while(b!=NULL){
        temp->bottom=b;
        temp=b;
        b=b->bottom;
    }
    return res->bottom;
}
Node *flatten(Node *root)
{
  if(root==NULL || root->next==NULL){
      return root;
  }
  root->next = flatten(root->next);
  root = mergeLL(root,root->next);
  return root;
} 
int main(){
    
    return 0;
}