#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int n;
    cin>>n;
    
    int ans=0;
    
    for(int i=0;i<n;i++){
        int temp=0;
        int a,b,c;
        cin>>a>>b>>c;
        
        if(a==1)
        temp++;

        if(b==1)
        temp++;

        if(c==1)
        temp++;

        if(temp>=2){
            ans++;
        }
    }

    cout<<ans<<"\n";

    return 0;
}