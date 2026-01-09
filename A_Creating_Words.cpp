#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        string a,b;
        cin>>a>>b;

        string one="";
        string two="";

        for(int i=0;i<3;i++){
            if(i==0){
                one+=b[i];
                two+=a[i];
            }
            else{
                one+=a[i];
                two+=b[i];
            }
        }

        cout<<one<<" "<<two<<"\n";
        
    }
    return 0;
}