#include<bits/stdc++.h>
#define ll long long
using namespace std;


// Time Complexity: O(n2)
// Space Complexity: O(n) for the extra visited vector
void FindIntersection(vector<int>a,vector<int>b){
   vector<int>ans;
   vector<int>visited(b.size(),0);
   int n=a.size(),m=b.size();
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(a[i]==b[j] && visited[j]==0){
            ans.push_back(a[i]);
            visited[j]=1;
            break;
        }else if(a[i]<b[j]){
            break;
        }
    }
   }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout<<endl;
}


// Time Complexity: O(n) n being the min length of the 2 arrays.
// Space Complexity: O(1)
void FindIntersection2(vector < int > a,vector < int > b){
   vector<int>ans;
   int i=0,j=0,n=a.size(),m=b.size();
   while(i<n && j<m){
        if(a[i]<b[j]){
            i++;
        }else if(b[j]<a[i]){
            j++;
        }else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
   }
   for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout<<endl;

}
int main(){
    vector < int > A {1,2,3,3,4,5,6,7};
    vector < int > B {3,3,4,4,5,8};
    FindIntersection2(A,B);
    FindIntersection(A,B);
    return 0;
}