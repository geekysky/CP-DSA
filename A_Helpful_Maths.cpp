#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    string s;
    cin>>s;

    vector<int> res;
    for(int i=0;i<s.size();i++){
        if(s[i]!='+'){
            res.push_back(s[i]-'0');
        }
    }

    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        if(i==res.size()-1){
            cout<<res[i];
        }
        else{
            cout<<res[i]<<'+';
        }
    }
    cout<<"\n";
    
    return 0;
}