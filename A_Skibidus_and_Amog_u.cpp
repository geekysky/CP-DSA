#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        int n=s.size();

        if(s[n-1]=='s' and s[n-2]=='u'){
            string ans="";
            for(int i=0;i<n-2;i++){
                ans+=s[i];
            }
            ans+='i';

            cout<<ans<<endl;
        }
    }
    return 0;
}