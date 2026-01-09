#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int n=8;
    int black=0,white=0;

    while(n--){
        string s;
        cin>>s;
        
        for(int i=0;i<8;i++){
            if(s[i]>='a' and s[i]<='z'){
                if(s[i]=='r')
                black+=5;

                else if(s[i]=='q')
                black+=9;

                else if(s[i]=='b')
                black+=3;

                else if(s[i]=='n')
                black+=3;

                else if(s[i]=='p')
                black+=1;
            }
            else{
                if(s[i]=='R')
                white+=5;

                else if(s[i]=='Q')
                white+=9;

                else if(s[i]=='B')
                white+=3;

                else if(s[i]=='N')
                white+=3;

                else if(s[i]=='P')
                white+=1;
            }

        }
    }

    if(black>white)
     cout<<"Black"<<"\n";

    else if(white>black)
    cout<<"White"<<"\n";

    else 
    cout<<"Draw"<<"\n";


    return 0;
}