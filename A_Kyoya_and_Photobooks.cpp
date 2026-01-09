#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    string s;
    cin>>s;
    
    int size=s.size();
    int tot_vacancies=size+1;

    cout<<(tot_vacancies*26)-size<<"\n";
    return 0;
}