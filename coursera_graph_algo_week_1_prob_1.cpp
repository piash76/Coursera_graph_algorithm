
///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>

#define ff    first
#define ss    second

#define  mp  make_pair
#define  pb  push_back

#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int mod2=2147483647; ///2^31-1

const int M=500005;
ll a[M],vis[M];
vector<ll> g[M];


void dfs(ll u)
{
    vis[u]=1;

    for(auto v:g[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }

}

int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    ll t,i,j;

    ll n,m;cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        ll u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    ll u,v;cin>>u>>v;


    dfs(u);


     if(vis[v]==1) cout<<1<<endl;
     else cout<<0<<endl;

    return 0;

}




