#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        if(a==0)
        //koi b,c,d m se ek bhi joke suna diya to -1 ho jayega 
        //saare 0 nahi honge as a+b+c+d>=1
        cout<<1<<"\n";

        else{
            int curr_score=a;
            //one pair of b n c to balance ths scores  
            int balance=min(b,c)*2;
            int till_neg=curr_score+1;

            int rem_jokes=abs(b-c)+d;

            cout<<curr_score+balance+min(till_neg,rem_jokes)<<'\n';

        }


    }
    return 0;
}