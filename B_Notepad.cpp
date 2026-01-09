#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;
        
        //rather than count let's see if it is found and what was it's index 
        map<string,int> mp;

        if(n==1)
        cout<<"NO"<<"\n";

        else{
            
            bool found=false;

            for(int i=0;i<n-1;i++){
            string sub=s.substr(i,2);
 
            if(mp.find(sub)!=mp.end()){
                if(i-mp[sub]>1){
                    found=true;
                    break;
                }
            }
            else{
                    //initialize n update if already present 
                    //dono ho jaenge 
                    mp[sub]=i;
                }
            }

            if(found)
            cout<<"YES"<<"\n";

            else
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}