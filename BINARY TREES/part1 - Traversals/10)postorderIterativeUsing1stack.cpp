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

//USING ONE STACKS
//TC->O(2N) ->forleft or right skewed SC->O(N)

//idea is to go to extreme left and then right and then again left of curr right
vector <int> postOrder(Node* curr)
{
      vector<int>ans;
      stack<Node *>s;
      if(curr==NULL){
          return ans;
      }
      while(curr!=NULL || !s.empty()){
          if(curr!=NULL){
              s.push(curr);
              curr = curr->left;
          }else{
              Node * temp = s.top()->right;
              if(temp==NULL){
                  temp = s.top();
                  s.pop();
                  ans.push_back(temp->data);
                  while(!s.empty() && temp==s.top()->right){
                      temp = s.top();
                      s.pop();
                      ans.push_back(temp->data);
                  }
              }else{
                  curr = temp;
              }
          }
      }
      return ans;
} 
int main(){
    
    return 0;
}