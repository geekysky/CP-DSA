#include<bits/stdc++.h>
using namespace std;
#define ll long long

string query(int x){
    cout<<x<<endl;
    string res;
    cin>>res;

    return res;
}

int main(){
    vector<int> prime={2,3,4,5,7,9,11,13,17,19,23,25,29,31,37,41,43,47,49};
    int cnt=0;
    bool is_prime=true;
    for(int i=0;i<prime.size();i++){
        if(query(prime[i])=="yes"){
            cnt++;
        }

        if(cnt>1){
            is_prime=false;
            cout<<"composite"<<endl;
            break;
        }
    }

    if(is_prime){
        cout<<"prime"<<endl;
    }

    return 0;
}