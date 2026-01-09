#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<int> num(n),den(m);
    map<int,int> p1,p2,p3;
    vector<int> spf(1e7+1);
    for(int i=0;i<1e7+1;i++){
        spf[i]=i;
    }

    for(int i=2;i<=1e7+1;i++){
        if(spf[i]==i){
            //i is a prime no 
            for(int j=i*i;j<=1e7+1;j+=i){
                spf[j]=min(spf[j],i);
            }
        }
    }

    for(int i=0;i<n;i++){
        cin>>num[i];

        int x=num[i];
        while(x!=1){
            int prime=spf[x];
            int cnt=0;
            while(x%prime==0){
                x/=prime;
                cnt++;
            }
            p1[prime]+=cnt;
        }
    }

    for(int i=0;i<m;i++){
        cin>>den[i];

        int x=den[i];
        while(x!=1){
            int prime=spf[x];
            int cnt=0;
            while(x%prime==0){
                x/=prime;
                cnt++;
            }
            p2[prime]+=cnt;
        }
    }
    
    //p3 is the gcd map and stores common powers for the prime factors across both the arrays
    for(auto it:p1){
        p3[it.first]=min(it.second,p2[it.first]);
    }

    //now let's equate the three maps 
    p1=p2=p3;

    for(int i=0;i<n;i++){
        int x=num[i];

        while(x!=1){
            int prime=spf[x];
            int cnt=0;

            while(x%prime==0){
                x/=prime;
                cnt++;
            }

            //now we try to remove the gcd power from this factorization 
            //for eg 2^3 hatana tha...but this no only produces 2^2 
            //so min lena padega 
            cnt=min(cnt,p1[prime]);
            p1[prime]-=cnt;
            while(cnt--){
                num[i]/=prime;
            } 
        }
    }

    for(int i=0;i<m;i++){
        int x=den[i];

        while(x!=1){
            int prime=spf[x];
            int cnt=0;

            while(x%prime==0){
                x/=prime;
                cnt++;
            }

            //now we try to remove the gcd power from this factorization 
            //for eg 2^3 hatana tha...but this no only produces 2^2 
            //so min lena padega 
            cnt=min(cnt,p2[prime]);
            p2[prime]-=cnt;
            while(cnt--){
                den[i]/=prime;
            } 
        }
    }

    cout<<n<<" "<<m<<"\n";
    for(int i=0;i<n;i++){
        cout<<num[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<m;i++){
        cout<<den[i]<<" ";
    }
    
    return 0;
}