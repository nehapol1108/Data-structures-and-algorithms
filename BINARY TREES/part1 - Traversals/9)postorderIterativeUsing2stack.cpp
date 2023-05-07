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

//USING TWO STACKS
//TC->O(N) SC->O(2N)
vector <int> postOrder(Node* root)
{
      vector<int>ans;
      stack<Node *>s1;
      stack<Node *>s2;
      if(root==NULL){
          return ans;
      }
      s1.push(root);
      Node *temp = root;
      while(!s1.empty()){
          temp = s1.top();
          s1.pop();
          s2.push(temp);
          if(temp->left!=NULL){
              s1.push(temp->left);
          }
          if(temp->right!=NULL){
              s1.push(temp->right);
          }
          
      }
      while(!s2.empty()){
          ans.push_back(s2.top()->data);
          s2.pop();
      }
      return ans;
}

//USING ONE STACk
vector <int> postOrder(Node* root)
{
      vector<int>ans;
      stack<Node *>s1;
      if(root==NULL){
          return ans;
      }
      s1.push(root);
      Node *temp = root;
      while(!s1.empty()){
          temp = s1.top();
          s1.pop();
          ans.push_back(temp->data);
          if(temp->left!=NULL){
              s1.push(temp->left);
          }
          if(temp->right!=NULL){
              s1.push(temp->right);
          }
          
      }
      reverse(ans.begin(),ans.end());
      return ans;
}
int main(){
    
    return 0;
}