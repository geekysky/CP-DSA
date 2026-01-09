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

        //n/2 '(' and n/2 ')'
        //just a modified version of valid parenthesis 

        stack<char> st;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.empty())
                ans++;

                else{
                    st.pop();
                }
            }
        }

        while(!st.empty()){
            st.pop();
            ans++;
        }

        cout<<ans/2<<"\n";
    }
    return 0;
}