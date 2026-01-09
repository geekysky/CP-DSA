#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    set<pair<int,pair<int,int>>> s;

    //all 4 will work as set will eliminate those repeated ones 
    s.insert({1,{1,0}});
    s.insert({1,{-1,0}});
    s.insert({0,{0,1}});
    s.insert({0,{0,-1}});

    for(int i=0;i<n;i++){
        set<pair<int,pair<int,int>>> temp;
        for(auto it:s){
            temp.insert({it.first+1,})
        }
    }

    return 0;
}