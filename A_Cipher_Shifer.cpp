#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        int ind=0;
        string ans="";
        int j;
        while(ind<n){
            char ch=s[ind];

            for(j=ind+1;j<n;j++){
                if(s[j]==ch){
                    ans+=ch;
                    break;
                }
            }
            ind=j+1;
        }

        cout<<ans<<"\n";
    }
    return 0;
}