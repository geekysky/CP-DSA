#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int n,m;
    cin>>n;

    vector<int> boys(n);
    for(int i=0; i<n; i++){
        cin>>boys[i];
    }

    cin>>m;
    vector<int> girls(m);
    for(int i=0;i<m;i++){
        cin>>girls[i];
    }

    sort(boys.begin(),boys.end());
    sort(girls.begin(),girls.end());

    int i=0,j=0;
    int pairs=0;

    while(i<n && j<m){
        if(abs(boys[i]-girls[j])<=1){
            pairs++;
            i++;
            j++;
        }
        else if(boys[i]>girls[j]+1){
            j++;
        }
        else{
            i++;
        }
    }

    cout<<pairs<<"\n";

    return 0;
}