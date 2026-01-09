#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    //to count no of divisors 
    vector<pair<int,int>> arr={{1,3},{2,7},{3,2}};
    sort(arr.begin(),arr.end(),[](pair<int,int> &a,pair<int,int> &b){
        return a.second < b.second;
    });
    
    for(auto it:arr){
        cout<<it.first<<" "<<it.second<<" ";
    }

    //ISKA matlab ye hai ki return a.second < b.second means pehle a.second fir b.second where a.second < b.second 
    //if the sign is changed then it sorts in descending order 



    return 0;
}