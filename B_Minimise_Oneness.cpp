#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        
        string ans="";
        for(int i=1;i<=n;i++){
            ans+='0';
        }

        ans[n-1]='1';

        cout<<ans<<"\n";
    }
    return 0;
}