#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://practice.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1
int totalFruits(int n, vector<int> &a) {
    //  { 0, 1, 2, 2, 2, 2 }
    unordered_map<int,int>m;
    int j=0,i=0,maxi=0;
    while(j<n){
        m[a[j]]++;
        if(m.size()<=2){
            //cout<<j<<endl;
            maxi = max(maxi,j-i+1);
            j++;
        }else if(m.size()>2){
            while(m.size()>2){
                m[a[i]]--;
                if(m[a[i]]==0){
                    m.erase(a[i]);
                }
                i++;
            }
            j++;
        }
    }
    return maxi;
} 
int main(){
    
    return 0;
}