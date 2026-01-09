#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int x;
    cin>>x;

    vector<pair<int,int>> factors;
    int maximum=LLONG_MAX;
    int a=-1,b=-1;
    for(int i=1;i*i<=x;i++){
        if((x%i)==0){
            if(__gcd(i,x/i)==1){
                if(max(i,x/i)<maximum){
                    maximum=max(i,x/i);
                    a=i;
                    b=x/i;
                }
            }
        }
    }

    cout<<a<<" "<<b<<"\n";
    
    return 0;
}