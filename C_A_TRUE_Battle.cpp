#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int good_pairs = 0;
        if (s[0] == '1' or s[n - 1] == '1')
        {
            cout << "YES" << '\n';
        }
        // else if(n==2){
        //     if(s[0]=='1' or s[1]=='1'){
        //         cout<<"YES"<<"\n";
        //     }
        //     else{
        //         cout<<"NO"<<"\n";
        //     }

        // }

        else
        {   
            int longest_one=0;
            int temp=0;
            for(int i=0;i<n;i++){
                if(s[i]!='1'){
                    longest_one=max(longest_one,temp);
                    temp=0;
                }
                else{
                    temp++;
                }
            }

            if(longest_one>1){
                cout<<"YES"<<"\n";
            }
            else{
                cout<<"NO"<<"\n";
            }

            
        }
    }
    return 0;
}