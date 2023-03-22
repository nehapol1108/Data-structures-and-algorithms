#include<bits/stdc++.h>
#define ll long long
using namespace std;

void tower_of_hanoi(int n,char source,char desti,char helper,int &count){
    if(n==0)return;
    tower_of_hanoi(n-1,source,helper,desti,count);
    count++;
    cout << "Move disk " << n << " from rod " << source <<" to rod " << desti << endl; 
    tower_of_hanoi(n-1,helper,desti,source,count);
}
int main(){
    int n;
    cin>>n;
    char source='a',desti='c',helper='b';
    int count=0;
    tower_of_hanoi(n,source,desti,helper,count);
    cout<<count<<endl;
    return 0;
}