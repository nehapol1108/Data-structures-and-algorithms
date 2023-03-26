#include<bits/stdc++.h>
#define ll long long
using namespace std;

//TC-> O(4N * N).
//SC->O(N)
vector<string> return_keypad(string s,unordered_map<int,string>m){
    if(s.size()==0){
        vector<string>v;
        v.push_back("");
        return v;
    }
    char ch = s[0];
    string res = s.substr(1);
    vector<string>temp2 = return_keypad(res,m);
    vector<string>temp3;
    string temp = m[ch-'0'];
    for(int i=0;i<temp.size();i++){
        char k = temp[i];
        for(auto j:temp2){
            temp3.push_back(k+j);
        }
    }
    return temp3;
    
}
int main(){
    string digits;
    cin>>digits;
    if(digits.size()==0){
        cout<<"[]"<<endl;
    }
    unordered_map<int,string>m;
    m[2]="abc";
    m[3]="def";
    m[4]="ghi";
    m[5]="jkl";
    m[6]="mno";
    m[7]="pqrs";
    m[8]="tuv";
    m[9]="wxyz";
    vector<string>ans = return_keypad(digits,m);
    for(auto i:ans){
        cout<<i<<endl;
    }
    cout<<endl;
    string anss="";
    // print_keypadd(digits,anss,m);
    return 0;
}