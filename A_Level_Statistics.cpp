#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int a=0,b=0;
        bool correct = true;

        for(int i=0; i<n; i++){
            int x,y;
            cin>>x>>y;
            
            if(x<a || y<b || y-b>x-a){
                correct=false;
            }

            //update the values 
            //we can't break in the middle of taking inputs 
            a=x;
            b=y;

        }

        if(correct){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
    return 0;
}
