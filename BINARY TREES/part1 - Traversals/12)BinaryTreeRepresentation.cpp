#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
    
    node(int x){
        data = x;
        left = right = NULL;
    }
};
struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

//TC->O(N) SC->O(N)
void create_tree(node* root0, vector<int> &vec){
        //Your code goes here
        queue<node*> q;
        q.push(root0);
        for(int i=1; i<vec.size(); i+=2) {
            auto temp = q.front();
            q.pop();
            temp->left = newNode(vec[i]);
            q.push(temp->left);
            temp->right = newNode(vec[i+1]);
            q.push(temp->right);
        }
       
    }
 
int main(){
    
    return 0;
}