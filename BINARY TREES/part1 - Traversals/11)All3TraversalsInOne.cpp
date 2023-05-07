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

//TC->O(3N) SC->O(4N)
void preInPost(Node *root){
    stack<pair<Node*,int>>s;
    s.push({root,1});
    vector<int>pre,inorder,post;
    while(!s.empty()){
        auto it = s.top();
        s.pop();
        if(it.second==1){
            it.second++;
            pre.push_back(it.first->data);
            s.push(it);
            if(it.first->left!=NULL){
                s.push({it.first->left,1});
            }
        }else if(it.second==2){
            it.second++;
            inorder.push_back(it.first->data);
            s.push(it);
            if(it.first->right!=NULL){
                s.push({it.first->right,1});
            }
        }else if(it.second==3){
            post.push_back(it.first->data);
        }
    }
    for(auto i:pre){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:inorder){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:post){
        cout<<i<<" ";
    }
    cout<<endl;
} 
int main(){
    
    return 0;
}