#include<bits/stdc++.h>
using namespace std;

//<------------------------------------------------Definations---------------------------------------------------->

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

//<------------------------------------------------Definations---------------------------------------------------->

//<------------------------------------------------Constants---------------------------------------------------->

const int N=2e5+10;
const ll MOD=1e9+7,INF=2e18;

//<------------------------------------------------Constants---------------------------------------------------->

//<---------------------------------------------useful functions------------------------------------------------>

bool is_square(ll x){ll y=sqrt(x);   return (x==(y*y));}
ll lcm(ll x,ll y){return  ((x/__gcd(x,y))*y);}
ll h_pow_2_less_x(ll x){
    if(x==0)        return 0;
    ll y=1;
    while((y*2)<=x)     y=y<<1;
    return y;
}
ll ceil_div(ll x,ll y){return ((x/y)+((x%y)!=0));}      //returns ceil(x/y);
ll fast_pow(ll b, ll p) {
    if(p == 0) return 1;
    if(p == 1) return (b%MOD);
    ll r = fast_pow(b, p / 2);
    if(p % 2) return ((((r*r)%MOD)*(b%MOD)) % MOD);
    else return ((r*r) % MOD);
}
ll inv_mod(ll x){return fast_pow(x,MOD-2);}
bool is_regular(string s){                              //checks if the given bracket sequence is regular
    int res=0;
    for(auto it : s){
        res+=(it=='(' ? 1 : -1);
        if(res<0)       return false;
    }
    return res==0;
}
string num_to_bin_str(ll x,int len){
    string ans="";
    while(x>0){
        ans.push_back(x&1 ? '1' : '0');
        x>>=1;
    }
    while(ans.size()<len)       ans.push_back('0');
    reverse(ans.begin(),ans.end());
    return ans;
}
//<---------------------------------------------useful functions------------------------------------------------>

void run_case(){
    ll i,n,m,d,sum=0,ans=0;
    cin>>n>>m>>d;
    vector<ll>v(n+1);
    for(i=1;i<=n;i++)        cin>>v[i];
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    for(i=1;i<=n;i++){
        if(v[i]>=0){
            sum+=v[i];pq.push(v[i]);
        }
        if(pq.size() > m){
            sum-=pq.top();pq.pop();
        }
        ans=max(ans,sum-(i*d));
    }
    cout<<ans;
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)      run_case();
    return 0;
}