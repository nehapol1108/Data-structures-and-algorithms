#include<bits/stdc++.h>
#define ll long long
using namespace std;


//TC->O(N*M)
//SC->O(1)
int celebrity(vector<vector<int> >&a, int n) 
{
    int res=0,curr_ind=-1;
    for(int i=0;i<n;i++){
        if(a[i][0]==0){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(a[i][j]==0){
                    cnt++;
                }else if(a[i][j]==1){
                    break;
                }
            }
            if(cnt==n){
                curr_ind = i;
                res++;
            }
        }
    }
    if(res>1 || curr_ind==-1)return -1;
    int cnt = 0;
    for(int j=0;j<n;j++){
        if(a[j][curr_ind]==1){
            cnt++;
        }
    }
    
    return cnt==n-1?curr_ind:-1;
} 

// https://www.youtube.com/watch?v=Z5AEc12ieOs&ab_channel=Yogesh%26Shailesh%28CodeLibrary%29


//BRUTE FORCE 
//TC->O(N*N) SC->O(2N)
int celebrity(vector<vector<int> >&a, int n) 
{ 
    int in[n] = {0}; //in stores who knows the ith person in stores ith person knows which person
    int out[n] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1){
                in[j]++;
                out[i]++;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(in[i]==n-1 && out[i]==0){
            return i;
        }
    }
    return -1;
}

//TC->O(N) SC->O(1)
int celebrity(vector<vector<int> >&a, int n) 
{ 
    int c=0;
    for(int i=1;i<n;i++){
        if(a[c][i]==1){
            c=i;
        }
    }
    for(int i=0;i<n;i++){
        if(i!=c && (a[c][i]==1 || a[i][c]==0))return -1;
    }
    return c;
}
int main(){
    
    return 0;
}