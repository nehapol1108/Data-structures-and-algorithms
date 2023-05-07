#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/same-tree/description/
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//TC->O(N) SC->O(N)
bool isIdentical(Node *r1, Node *r2)
{
    if(r1==NULL && r2==NULL){
        return true;
    }else if((r1==NULL && r2!=NULL) || (r2==NULL && r1!=NULL) ){
        return false;
    }else if(r1->data!= r2->data){
        return false;
    }
    bool left = isIdentical(r1->left,r2->left);
    bool right = isIdentical(r1->right,r2->right);
    
    return left && right;
} 
int main(){
    
    return 0;
}