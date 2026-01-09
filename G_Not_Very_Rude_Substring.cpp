#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int n,c;
    cin>>n>>c;
    
    string s;
    cin>>s;

    int a=0,b=0;
    int left=0,ans=0;
    int rudeness=0;

    for(int right=0;right<n;right++){
        if(s[right]=='a'){
            a++;
        }
        else if(s[right]=='b'){
            rudeness+=a;
            b++;
        }

        while(rudeness>c){
            if(s[left]=='a'){
                //check how many pairs are getting affected 
                //rudeness gets decreased by b 
                rudeness-=b;
                a--;
            }
            else if(s[left]=='b'){
                b--;
            }

            left++;
        }

        ans=max(ans,right-left+1);
    }

    cout<<ans<<"\n";

    return 0;
}