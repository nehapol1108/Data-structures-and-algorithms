#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data){
            this->data = data;
            next=NULL;
            prev =NULL;
        }
};

//TC->O(n) SC->O(n)
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    unordered_map<int,int>m;
    vector<pair<int, int>>v;
    Node *curr=head;
    while(curr!=NULL){
        if(m[target-curr->data]>0){
            v.push_back({target-curr->data,curr->data});
            m[target-(curr->data)]--;
        }
        else{
            m[curr->data]++;
        }    
        curr=curr->next;
    }
    sort(v.begin(),v.end());
    return v;
}

//TC->O(n + n/2) SC->O(1)
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        Node *start = head;
        Node *end = head;
        while(end->next!=NULL){
            end=end->next;
        }
        vector<pair<int, int>>v;
        while(start!=end && end->next!=start){  //end->next!=start means j crosses i
            if((start->data+end->data)==target){
                v.push_back({start->data,end->data});
                start=start->next;
                end=end->prev;
               
            }else if((start->data+end->data)>target){
                end=end->prev;
            }else{
                start=start->next;
            }
        }
        
        return v;
    }
int main(){
    
    return 0;
}