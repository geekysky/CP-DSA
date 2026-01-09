#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool all_four_directions(vector<pair<int,int>> points,pair<int,int> p){
    bool down=false,up=false,left=false,right=false;
    for(int i=0;i<points.size();i++){
        pair<int,int> temp=points[i];
        if(temp!=p){
            if(temp.first>p.first and temp.second==p.second){
                right=true;
            }
            else if(temp.first<p.first and temp.second==p.second){
                left=true;
            }
            else if(temp.first==p.first and temp.second>p.second){
                up=true;
            }
            else if(temp.first==p.first and temp.second<p.second){
                down=true;
            }
        }
    }

    if(up and down and left and right){
        return true;
    }

    else {
    return false;
    }
}

int main(){
    int t;
    cin>>t;
    
    vector<pair<int,int>> points;
    while(t--){
        int x,y;
        cin>>x>>y;

        points.push_back({x,y});
    }
    
    int ans=0;
    for(auto it:points){
        if(all_four_directions(points,it)){
            ans++;
        }
    }

    cout<<ans<<"\n";

    return 0;
}