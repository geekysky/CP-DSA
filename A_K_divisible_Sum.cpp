#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while (t--)
    {
        /* code */
        int n,k;
        cin>>n>>k;
        
        int ans;
        if(k>=n){
            ans=k/n;

            if(k%n){
                ans++;
            }

        }
        else{
            int to_make=((n+(k-1))/k)*k;
            ans=to_make/n;

            if(to_make%n)
            ans++;

        }

        cout<<ans<<"\n";
    }
    
    return 0;
}