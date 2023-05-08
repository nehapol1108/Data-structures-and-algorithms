#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://practice.geeksforgeeks.org/problems/unique-binary-tree-requirements/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=unique-binary-tree-requirements

//  Time Complexity: O(1)
//  Auxiliary Space: O(1)
bool isPossible(int a,int b)
{
    if((a==2 && b!=2) || (b==2 && a!=2))return true;
    return false;
} 
int main(){
    
    return 0;
}