#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        int j=0,ans=0;
        for(int i=0;i<n;i++){
            //for that problem no smaller difficulty was available
            if(b[i]<a[j])
            ans++;

            else
            j++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}