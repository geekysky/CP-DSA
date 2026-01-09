#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int max_width=-1,max_height=-1;
        vector<pair<int,int>> rect;
        for(int i=0;i<n;i++){
            int w,h;
            cin>>w>>h;

            max_width=max(max_width,w);
            max_height=max(max_height,h);
        }

        cout<<(max_width+max_height)*2<<"\n";

    }
    return 0;
}