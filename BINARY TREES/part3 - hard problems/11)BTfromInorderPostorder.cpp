#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
//TC->O(N)logn SC->O(N)   we can omit this Logn complexity by mannually finding the index through O(n) but then complexity would be O(n^2)
Node * constructTree(int post[],int postStart,int postEnd,int in[],int inStart,int inEnd,map<int,int>&m){
    if(postStart>postEnd || inStart>inEnd){
        return NULL;
    }
    Node *root = new Node(post[postEnd]);
    int inRoot = m[post[postEnd]];
    int numsLeft = inRoot-inStart;
    
    root->left = constructTree(post,postStart,postStart+numsLeft-1,in,inStart,inRoot-1,m);
    root->right = constructTree(post,postStart+numsLeft,postEnd-1,in,inRoot+1,inEnd,m);
    return root;
}
Node *buildTree(int inorder[], int postorder[], int n) {
    int postStart = 0,postEnd =n - 1;
    int inStart = 0, inEnd = n- 1;

    map < int, int > mp;
    for (int i = inStart; i <= inEnd; i++) {
        mp[inorder[i]] = i;
    }
    return constructTree(postorder, postStart, postEnd, inorder, inStart, inEnd, mp);
}
 
int main(){
    
    return 0;
}