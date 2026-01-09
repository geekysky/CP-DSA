#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int t;
    cin>>t;

    while (t--)
    {
        /* code */
        string s;
        cin>>s;

        int n=s.size();

        int coins=0,a_cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='A')
            a_cnt++;
        }

        if(a_cnt==n or (n-a_cnt)==n)
        cout<<0<<"\n";

        else{
        int min_as=INT_MAX;
        int temp=0;

        for(int i=0;i<n;i++){
            if(s[i]=='B'){
                min_as=min(temp,min_as);
                temp=0;
            }
            else{
                temp++;
            }
        }

        min_as=min(temp,min_as);
        //cout<<min_as<<"\n";
        cout<<a_cnt-min_as<<"\n";

        //cout<<endl;


        }

        
    }
    
    return 0;
}