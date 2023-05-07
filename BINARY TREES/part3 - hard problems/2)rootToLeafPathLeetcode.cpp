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

//TC->O(N) SC->O(N)
bool func(Node *root, vector<int>&v,int val){
     if(root==NULL){
         return false;
     }
     
     v.push_back(root->data);
     if(root->data==val){
        return true;
     }    
     if(func(root->left,v,val) || func(root->right,v,val)){
        return true;
     }
     v.pop_back();
     return false;
     
 }
vector<int> Paths(Node* root)
{
    
    vector<int>v;
    
    if(root==NULL)return v;
    int val;
    bool ans = func(root,v,val);
    return v;
}
 
int main(){
    
    return 0;
}