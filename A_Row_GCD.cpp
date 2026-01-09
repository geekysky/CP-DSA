#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    #define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);

    int n,m;
    cin>>n>>m;

    int a[n],b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    //let's precomute value of gcd(a2-1,a3-a1...an-a1) 
    //to make sure values aren't negative we must sort the array a and subtract a[0]
    //from all other values 
    sort(a,a+n);
    int rest_gcd=0;
    for(int i=1;i<n;i++){
        rest_gcd= __gcd(rest_gcd,a[i]-a[0]);
    }

    for(int i=0;i<m;i++){
        cout<<__gcd((a[0]+b[i]),rest_gcd)<<" ";
    }
    cout<<"\n";

    return 0;
}