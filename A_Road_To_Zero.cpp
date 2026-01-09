#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int t;
    cin>>t;

    while(t--){
        int x,y,a,b;
        cin>>x>>y;
        cin>>a>>b;

        //pehle a and b ko same number p lao 
        //using type 1 op 
        int mixed=abs(x-y)*a;
        mixed+=min(x,y)*b;

        int one=(x+y)*a;

        cout<<min(mixed,one)<<"\n";
        
    }
    return 0;
}