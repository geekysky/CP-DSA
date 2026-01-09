#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        if(n%2!=0){
            for(int i=1;i<=n;i++){
                cout<<1<<" ";
            }
            cout<<"\n";
        }
        else{
            cout<<1<<" "<<3<<" ";
            for(int i=1;i<=(n-2);i++){
                cout<<2<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}