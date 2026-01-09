#include <bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);


void CoderAbhi27(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) 
            cin>>a[i][j];
      
            
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            int mx=0;
            if(i>0) mx=max(mx, a[i-1][j]);
            if(i<n-1) mx=max(mx, a[i+1][j]);
            if(j>0) mx=max(mx, a[i][j-1]);
            if(j<m-1) mx=max(mx, a[i][j+1]);
            if(mx!=0 && mx<a[i][j]) a[i][j]=mx;
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    //O(n*m)
    
}

int32_t main() {
    fastIO;

    int t=1;
    cin>>t;
    while(t--){
        CoderAbhi27();
    }
    return 0;
}