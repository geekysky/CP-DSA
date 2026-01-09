#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        if(n==2 or n==3)
        cout<<-1<<"\n";

        else if(n==4 or n==5){
            if(n==4)
            cout<<3<<" "<<1<<" "<<4<<" "<<2;

            else
            cout<<5<<" "<<3<<" "<<1<<" "<<4<<" "<<2;

            cout<<"\n";
        }

        else{
            //first all odd then 4 2 ...even nos 

            if(n%2){
                for(int i=n;i>=1;i-=2){
                    cout<<i<<" ";
                }

            }
            else{
                for(int i=n-1;i>=1;i-=2){
                    cout<<i<<" ";
                }
            }

            cout<<4<<" "<<2<<" ";

            for(int i=6;i<=n;i+=2){
                cout<<i<<" ";
            }

            cout<<"\n";


        }

        
    }
    return 0;
}