#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while (t--)
    {
        /* code */
        int n;
        cin>>n;

        if(n%4==0)
        cout<<n/4<<'\n';

        else if(n==2)
        cout<<1<<'\n';

        else{
            int ans=n/4;
            int rem=n%4;
            
            ans+=(rem/2);

            cout<<ans<<'\n';

        }
    }
    
    return 0;
}