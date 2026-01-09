#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        //chalo brute force 
        int x,k;
        cin>>x>>k;

        vector<bool> is_valid(101,true);
        is_valid[0]=false;
        for(int i=k;i<=101;i+=k){
            is_valid[i]=false;
        }

        if(is_valid[x]){
        cout<<1<<"\n";
        cout<<x<<"\n";
        }

        else{
            cout<<2<<"\n";
            cout<<is_valid[x-1]<<" "<<x-is_valid[x-1]<<"\n";
        }


    }
    return 0;
}