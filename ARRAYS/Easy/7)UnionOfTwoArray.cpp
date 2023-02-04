#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Time Compleixty : O( (m+n)log(m+n) ) . Inserting a key in map takes logN times, where N is no of elements in map. At max map can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation across insertion of all elements in worst it would take O((m+n)log(m+n) time.

// Using unordered_map also takes the same time, On average insertion in unordered_map takes O(1) time but sorting the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.

// Space Complexity : O(m+n) {If Space of Union Vector is considered} 
// O(1) {If Space of union Vector is not considered}
vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  map < int, int > freq;
  vector < int > Union;
  for (int i = 0; i < n; i++)
    freq[arr1[i]]++;
  for (int i = 0; i < m; i++)
    freq[arr2[i]]++;
  for (auto & it: freq)
    Union.push_back(it.first);
  return Union;
}

// Time Compleixty : O( (m+n)log(m+n) ) . Inserting a element in set takes logN time, where N is no of elements in set. At max set can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation across inserting all elements in worst it would take O((m+n)log(m+n) time.

// Using unordered_set also takes the same time, On average insertion in unordered_set takes O(1) time but sorting the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.

// Space Complexity : O(m+n) {If Space of Union Vector is considered} 

// O(1) {If Space of union Vector is not considered}
vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  set < int > s;
  vector < int > Union;
  for (int i = 0; i < n; i++)
    s.insert(arr1[i]);
  for (int i = 0; i < m; i++)
    s.insert(arr2[i]);
  for (auto & it: s)
    Union.push_back(it);
  return Union;
}

// Time Complexity: O(m+n), Because at max i runs for n times and j runs for m times. When there are no common elements in arr1 and arr2 and all elements in arr1, arr2 are distinct. 

// Space Complexity : O(m+n) {If Space of Union Vector is considered} 

// O(1) {If Space of union Vector is not considered}

vector<int> findUnion(int a1[], int a2[], int n, int m)
{
    vector<int>ans;
    int i=0,j=0;
    while(i<n && j<m){
        if(a1[i]<=a2[j]){
            if(!ans.size() || ans.back()!=a1[i]){
                ans.push_back(a1[i]);
            }
            i++;
        }else{
            if(!ans.size() || ans.back()!=a2[j]){
                ans.push_back(a2[j]);
            }
            j++;
        }
    }
    while(i<n){
            if(!ans.size() || ans.back()!=a1[i]){
                ans.push_back(a1[i]);
            }
            i++;
        
    }
    while(j<m){
            if(!ans.size() || ans.back()!=a2[j]){
                ans.push_back(a2[j]);
            }
            j++;
        
    }
    return ans;
} 
int main(){
    
    return 0;
}