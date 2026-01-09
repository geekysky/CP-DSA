#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
signed main(){
    int n,m;
    cin>>n>>m;

    vector<int> primes(1e5+1,0);
    
    // Sieve for marking prime numbers
    for(int i=2;i<=1e5;i++){
        if(primes[i]==0){
            for(int j=i*i;j<=1e5;j+=i){
                primes[j]=-1;
            }
        }
    }

    // Initialize smallest prime factor array
    vector<int> spf(1e5+1);
    for(int i=2;i<1e5+1;i++){
        spf[i]=i;
    }

    // Calculate smallest prime factors
    for(int i=2;i<=1e5;i++){
        if(spf[i]==i){
            for(int j=2*i;j<=1e5;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }

    map<int,multiset<int>> mp;  // prime factor -> numbers containing it
    vector<int> present(1e5+1,0);  // track which numbers are currently on

    for(int i=0;i<m;i++){
        char t;
        int num;
        cin>>t>>num;

        if(t=='+'){
            if(present[num]){
                cout<<"Already on"<<'\n';
                continue;
            }
            
            // Check for collisions
            int x=num;
            bool collision = false;
            int collider = -1;
            map<int,int> temp;
            
            while(x!=1){
                int p=spf[x];
                int cnt=0;
                while(x%p==0){
                    cnt++;
                    x/=p;
                }
                
                if(!mp[p].empty()){
                    collision = true;
                    collider = p;
                    break;
                }
                temp[p] += cnt;
            }

            if(collision){
                cout<<"Conflict with "<<*mp[collider].begin()<<"\n";
            }
            else{
                present[num]=1;
                cout<<"Success"<<"\n";
                for(auto it:temp){
                    primes[it.first]+=it.second;
                    mp[it.first].insert(num);
                } 
            }
        }
        else{  // '-' operation
            if(present[num]==0){
                cout<<"Already off"<<"\n";
                continue;
            }
            
            cout<<"Success"<<'\n';
            present[num] = 0;
            int x=num;
            
            while(x!=1){
                int p=spf[x];
                int cnt=0;
                while(x%p==0){
                    cnt++;
                    x/=p;
                }
                
                primes[p] = max(primes[p]-cnt,0ll);
                auto it = mp[p].find(num);
                if(it != mp[p].end()){
                    mp[p].erase(it);
                }
            }
        }
    }
    return 0;
}