#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ll n;
    cin>>n;

    string s;
    cin>>s;

    //sabse negative n sabse positive ka diff+1 - to include the positions as well 
    int right=0,left=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='L')
        left++;

        else 
        right++;
    }

    cout<<abs(left*-1 - right*1) + 1 <<"\n";


    return 0;
}