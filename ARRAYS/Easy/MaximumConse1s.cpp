#include<bits/stdc++.h>
#define ll long long
using namespace std;
int findMaxConsecutiveOnes(vector<int>&a) {
    int i=0,n=a.size(),maxi=0,c=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            c++;
        }else{
            maxi = max(c,maxi);
            c=0;
        }
    }
    maxi = max(c,maxi);
    return maxi;
}
int main(){
    
    return 0;
}