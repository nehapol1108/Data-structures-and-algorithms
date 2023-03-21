#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Item{
    int value;
    int weight;
};
class Solution
{
    public:
    static bool comp(Item i1,Item i2){
        double wpv1 = (i1.value*1.0)/i1.weight;
        double wpv2 = (i2.value*1.0)/i2.weight;
        return wpv1>wpv2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item a[], int n)
    {
        double sum=0;
        sort(a,a+n,comp);
        for(int i=0;i<n;i++){
           // cout<<a[i].weight<<endl;
            if(a[i].weight<=W){
                sum+= a[i].value;
                W = W- a[i].weight;
            }
            else{
                double rem = (W/double(a[i].weight));
                //cout<<W<<" "<<a[i].weight<<endl;
                sum+= (double(a[i].value))*rem;
                break;
            }
        }
        return sum;
    }
};
int main(){
    
    return 0;
}