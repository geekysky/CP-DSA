#include<bits/stdc++.h>
using namespace std;
#define ll long long

set<char> vowels={'a','e','i','o','y','u','A','E','I','O','U','Y'};

void uc_lc(string &s){
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' and s[i]<='Z'){
            s[i]='a'+(s[i]-'A');
        }
    }
}

string add_dots(string s){
    string res="";
    for(int i=0;i<s.size();i++){
        res+='.';
        res+=s[i];
    }

    return res;
}

string remove_v(string &s){
    string res="";
    for(int i=0;i<s.size();i++){
        if(vowels.find(s[i])==vowels.end()){
            res+=s[i];
        }
    }

    return res;

}
int main(){
    string s;
    cin>>s;
    
    string temp=remove_v(s);
    uc_lc(temp);
    string ans=add_dots(temp);

    cout<<ans<<"\n";


    return 0;
}