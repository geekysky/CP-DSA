#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        
        int n=s.size();
        int last_one=-1,last_two=-1,last_three=-1 ;
        int smallest_len=INT_MAX;

        for(int i=0;i<n;i++){
            if(s[i]=='1')
            last_one=i;

            else if(s[i]=='2')
            last_two=i;

            else
            last_three=i;

            if(i>=2){
                if(last_one!=-1 and last_two!=-1 and last_three!=-1){
                    //all three have been found 
                    smallest_len=min(smallest_len,max({last_one,last_two,last_three})-min({last_one,last_two,last_three}) + 1);
                }
            }
        }

        if(n==1 or n==2 or smallest_len==INT_MAX)
        cout<<0<<"\n";

        else
        cout<<smallest_len<<"\n";


    }

    return 0;
}