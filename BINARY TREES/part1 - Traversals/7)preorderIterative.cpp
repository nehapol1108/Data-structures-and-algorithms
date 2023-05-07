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
vector <int> preorder(Node* root)
{
    vector<int>ans;
    stack<Node*>s;
    s.push(root);
    while(!s.empty()){
        Node* temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        if(temp->right!=NULL){
            s.push(temp->right);
        }
        if(temp->left!=NULL){
            s.push(temp->left);
        }
       
    }
    return ans;
} 
int main(){
    
    return 0;
}