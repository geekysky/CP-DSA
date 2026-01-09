#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> primeFactors(int n) 
{   
    vector<int> factors;
    // Print the number of 2s that divide n 
    while (n % 2 == 0) 
    { 
        factors.push_back(2); 
        n = n/2; 
    } 
 
    // n must be odd at this point. So we can skip 
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        // While i divides n, print i and divide n 
        while (n % i == 0) 
        { 
            factors.push_back(i);
            n = n/i; 
        } 
    } 
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2 
    if(n>2)
    factors.push_back(n);

    return factors;
} 
int main(){
    int n,k;
    cin>>n>>k;

    vector<int> store = primeFactors(n);

    if(store.size()<k)
    cout<<-1<<"\n";

    else{
        int temp=1;
        for(int i=0;i<store.size();i++){
            if(k==1){
                temp*=store[i];
            }

            else{
                k--;
                cout<<store[i]<<" ";
                
            }
        }
        cout<<temp<<"\n";
    }
    return 0;
}