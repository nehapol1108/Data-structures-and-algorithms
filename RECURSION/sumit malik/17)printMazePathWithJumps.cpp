#include<bits/stdc++.h>
#define ll long long
using namespace std;
//more efficient for storage
void printMazePathWithJumps(int sr,int sc,int dr,int dc,string path){
    if(sr>dc || sc>dc){
        return;
    }
    if(sr==dr && sc==dc){
        cout<<path<<endl;
        return;
    }
    for(int ms =1;ms<=dc-sc;ms++){
        string temp = to_string(ms);
        printMazePathWithJumps(sr,sc+ms,dr,dc,path+'h'+temp);
    }
    for(int ms =1;ms<=dr-sr;ms++){
        string temp = to_string(ms);
        printMazePathWithJumps(sr+ms,sc,dr,dc,path+'v'+temp);
    }
    for(int ms =1;ms<=dc-sc && ms<=dr-sr;ms++){
        string temp = to_string(ms);
        printMazePathWithJumps(sr+ms,sc+ms,dr,dc,path+'d'+temp);
    }
   

} 
int main(){
    
    return 0;
}