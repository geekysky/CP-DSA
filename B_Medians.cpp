#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        if(k==(n+1)/2){
            cout<<1<<"\n";
            cout<<1<<"\n";
        }
        else if(k==1 or k==n){
            cout<<-1<<"\n";
        }
        else{
            if(k%2){
                cout<<3<<"\n";
                cout<<1<<" "<<k-1<<" "<<k+2<<"\n";
            }
            else{
                cout<<3<<"\n";
                cout<<1<<" "<<k<<" "<<k+1<<"\n";
            }
        }
    }
    return 0;
}