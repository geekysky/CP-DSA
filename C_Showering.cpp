#include<bits/stdc++.h>
using namespace std;
#define int long long int 
 
signed main(){
    int t;
    cin>>t;

    while(t--){
        int n,s,m;
        cin>>n>>s>>m;

        int prev_end=0;
        int lar=-1;

        while(n--){
            int l,r;
            cin>>l>>r;

            lar=max(lar,l-prev_end);
            prev_end=r;
        }
        
        //now till the end remains after last task 
        lar=max(lar,(m-prev_end));
        
        if(lar>=s){
            cout<<"YES"<<"\n";
        }

        else{
            cout<<"NO"<<"\n";
        }



    }
    return 0;
}