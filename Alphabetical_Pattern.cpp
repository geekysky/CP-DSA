#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        for(int i=1;i<=n;i++){
            string res="";
            for(int j=1;j<=i;j++){
                res+=('A'+(j-1));
            }

            cout<<res<<endl;
        }
    }
    return 0;
}