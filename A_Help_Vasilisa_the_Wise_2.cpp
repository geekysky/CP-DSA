#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    #define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
    
    int r1,r2,c1,c2,d1,d2;
    cin>>r1>>r2;
    cin>>c1>>c2;
    cin>>d1>>d2;

    int two_y=c2+d1-r1;
    for(int a=1;a<=9;a++){
        for(int b=1;b<=9;b++){
            for(int c=1;c<=9;c++){
                for(int d=1;d<=9;d++){
                    if(a!=b and a!=c and a!=d and b!=c and b!=d and c!=d){
                        if(a+b==r1 and a+d==d1 and a+c==c1 and b+d==c2 and b+c==d2 and c+d==r2){
                            cout<<a<<" "<<b<<"\n";
                            cout<<c<<" "<<d<<"\n";

                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout<<-1<<"\n";


    //and one>0 and one<10 and two>0 and two<10 and three>0 and three<10 and four>0 and four<10

    return 0;
}