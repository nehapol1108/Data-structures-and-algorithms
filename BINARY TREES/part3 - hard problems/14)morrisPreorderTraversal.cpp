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
vector <int> preorder(Node* root)
{
    vector<int>ans;
    Node *curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }else{
            Node * prev = curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev = prev->right;
            }
            if(prev->right==NULL){
                prev->right=curr;
                ans.push_back(curr->data);
                curr = curr->left;
            }else{
                prev->right = NULL;
                
                curr = curr->right;
            }
        }
    }
    return ans;
} 
int main(){
    
    return 0;
}