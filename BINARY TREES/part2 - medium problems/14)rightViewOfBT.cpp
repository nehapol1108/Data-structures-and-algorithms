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

//TC->O(N) SC->O(H)
void func(Node *root,vector<int>&ans,int level){
    if(root==NULL)return;
    if(ans.size()==level){
        ans.push_back(root->data);
    }
    func(root->right,ans,level+1);
    func(root->left,ans,level+1);
}
vector<int> rightView(Node *root)
{
   vector<int>ans;
   if(root==NULL){
       return ans;
   }
   func(root,ans,0);
   return ans;
} 
int main(){
    
    return 0;
}