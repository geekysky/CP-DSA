#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int x1,x2,y1,y2;
    cin>>x1>>y1;
    cin>>x2>>y2;
    
    cout<<max(abs(x2-x1),abs(y2-y1))<<"\n";

    return 0;
}