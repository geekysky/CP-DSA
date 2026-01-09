#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        //1-1
        //2-1
        //3-2
        //4-3
        //....

        cout<<ceil((double) n/2)<<"\n";

        int i=1;
        int j=3*n;


        while(i<j){
            cout<<i<<" "<<j<<"\n";

            i+=3;
            j-=3;
        }

    }
    return 0;
}