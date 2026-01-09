#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int s,n;
    cin>>s>>n;

    vector<pair<int,int>> str_bon;
    while(n--){
        int st,bo;
        cin>>st>>bo;

        str_bon.push_back({st,bo});
    }

    sort(str_bon.begin(),str_bon.end());

    //dragons are sorted in ascending order of their strengths 
    //we should start from smallest strength dragon and go till last 

    int slain=0;
    for(int i=0;i<str_bon.size();i++){
        pair<int,int> curr_drag=str_bon[i];

        if(curr_drag.first<s){
            s+=curr_drag.second;
            slain++;
        }
        else{
            break;
        }
    }

    if(slain==str_bon.size())
    cout<<"YES"<<"\n";

    else
    cout<<"NO"<<"\n";

    return 0;
}