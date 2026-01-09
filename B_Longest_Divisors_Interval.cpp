#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int cnt=1;
        for(int i=2;i<=50;i++){
            if(n%i==0){
                cnt++;
            }
            else{
                break;
            }
        }

        cout<<cnt<<"\n";
    }

    return 0;
}