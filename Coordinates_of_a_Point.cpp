#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double

signed main(){
    int t;
    cin>>t;

    while(t--){
        double a,b;
        cin>>a>>b;

        if(a==0.0 and b!=0.0){
            cout<<"Eixo Y"<<endl;
        }
        else if(a!=0 and b==0.0){
            cout<<"Eixo X"<<endl;
        }
        else if(a==0.0 and b==0.0){
            cout<<"Origem"<<endl;
        }
        else {
            if(a>0.0){
                if(b>0.0){
                    //Q1
                    cout<<"Q1"<<endl;
                }
                else{
                    cout<<"Q4"<<endl;
                }
            }
            else{
                if(b>0.0){
                    //Q1
                    cout<<"Q2"<<endl;
                }
                else{
                    cout<<"Q3"<<endl;
                }
            }
        }


    }
    return 0;
}