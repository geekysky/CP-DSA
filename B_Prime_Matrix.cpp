#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<int> is_prime(100004, 1);  
    is_prime[0] = 0;
    is_prime[1] = 0;

    for (int i = 2; i * i <= 100004; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= 100004; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
    vector<int> primes;
    for(int i=2;i<=100004;i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }


    vector<vector<int>> arr(n,vector<int> (m));
    int ans=LLONG_MAX;
    for(int i=0;i<n;i++){
        int rows=0;
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            
            auto it=lower_bound(primes.begin(),primes.end(),arr[i][j]);
            if(it!=primes.end()){
                rows+=(*it - arr[i][j]);
            }
        }
        ans=min(rows,ans);
    }

    //now iterate coloumn wise 
    for(int j=0;j<m;j++){
        int cols=0;
        for(int i=0;i<n;i++){
            auto it=lower_bound(primes.begin(),primes.end(),arr[i][j]);
            if(it!=primes.end()){
                cols+=(*it - arr[i][j]);
            }
        }
        ans=min(cols,ans);
    }

    cout<<ans<<"\n";

    return 0;
}