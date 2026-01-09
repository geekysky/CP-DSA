#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    
    double num=a*d;
    double den=a*d + b*c - a*c;

    cout<<setprecision(12)<<fixed<<num/den<<"\n";
    
    return 0;
}