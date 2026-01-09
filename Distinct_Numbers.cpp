#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t;
    cin>>t;

    set<int> dis;
    for(int i=0;i<t;i++){
        int x;
        cin>>x;

        dis.insert(x);
    }

    cout<<dis.size()<<"\n";
    return 0;
}