#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    public:
        int k;
        int v;
        int cnt;
        node *prev;
        node *next;
        node(int k,int v){
            this->k=k;
            this->v=v;     
            cnt = 1;   
        }
        
};
struct List{
    public:
        int size;
        node *head;
        node *tail;
        List(){
            head = new node(-1,-1);
            tail = new node(-1,-1);
            head->next=tail;
            tail->prev=head;
            size=0;
        }

        void addFront(node *&newnode){
            newnode->next=head->next;
            head->next->prev=newnode;
            head->next = newnode;
            newnode->prev=head;   
            size++; 
        }
        void deleteNode(node *&delnode){
            node *delprev =  delnode->prev;
            node *delnext = delnode->next;
            delprev->next = delnext;
            delnext->prev=delprev;
            size--;
        }
        
};
class LFUCache {
public:
    unordered_map<int,node*>keyNode;
    unordered_map<int,List*>freqList;
    int maxSizeCache;
    int minFreq; 
    int curSize; 
    LFUCache(int capacity) {
        maxSizeCache = capacity; 
        minFreq = 0;
        curSize = 0; 
    }
    void updateFreqListMap(node *upnode) {
        keyNode.erase(upnode->k);
        freqList[upnode->cnt]->deleteNode(upnode);
        if(upnode->cnt == minFreq && freqList[upnode->cnt]->size==0){
            minFreq++;
        }
        List* nextHigherFreqList = new List();
        if(freqList.find(upnode->cnt + 1) != freqList.end()) {
            nextHigherFreqList = freqList[upnode->cnt + 1];
        } 
        upnode->cnt += 1; 
        nextHigherFreqList->addFront(upnode); 
        freqList[upnode->cnt] = nextHigherFreqList; 
        keyNode[upnode->k] = upnode;
    }
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            node * currNode = keyNode[key];
            int val = currNode->v;
            updateFreqListMap(currNode);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (maxSizeCache == 0) {
            return;
        }
        if(keyNode.find(key) != keyNode.end()) {
            node* newnode = keyNode[key]; 
            newnode->v = value; 
            updateFreqListMap(newnode); 
        }
        else {
            if(curSize == maxSizeCache) {
                List* list = freqList[minFreq]; 
                keyNode.erase(list->tail->prev->k); 
                freqList[minFreq]->deleteNode(list->tail->prev);
                curSize--; 
            }
            curSize++; 
            // new value has to be added who is not there previously 
            minFreq = 1; 
            List* listFreq = new List(); 
            if(freqList.find(minFreq) != freqList.end()) {
                listFreq = freqList[minFreq]; 
            }
            node* newnode = new node(key, value); 
            listFreq->addFront(newnode);
            keyNode[key] = newnode; 
            freqList[minFreq] = listFreq; 
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */ 
int main(){
    
    return 0;
}