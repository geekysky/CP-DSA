#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define max_size 1000001

ll is_prime[max_size];
ll prime_factors[max_size];

void pre_compute(){
    for(ll i=0;i<max_size;i++){
    is_prime[i]=1;
    prime_factors[i]=0;
    }
        
    is_prime[0]=0;
    is_prime[1]=0;

        //now sieve to calculate the prime nos n prime factors of numbes from a to b 
        for(ll i=2;i<=max_size;i++){

            if(is_prime[i]){
                //i is a prime no 
                prime_factors[i]++;
                for(ll j=2*i;j<=max_size;j+=i){
                    is_prime[j]=0;
                    prime_factors[j]++;
                }
            }
        }
}
int main(){
    ll t;
    cin>>t;
    
    pre_compute();

    while(t--){
    ll a,b,n;
    cin>>a>>b>>n;

    ll cnt=0;
    for(ll i=a;i<=b;i++){
        if(prime_factors[i]==n)
        cnt++;
    }

    cout<<cnt<<"\n";

    }
    return 0;
}