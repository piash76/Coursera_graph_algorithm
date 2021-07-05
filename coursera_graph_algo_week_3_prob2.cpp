






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

const int N=500005;




ll n,m;
vector<ll>g[N];
bool vis[N];
int color[N];

void dfs(ll s)
{
    vis[s]=true;

    for(auto v:g[s])
    {
        if(!vis[v])
        {
        color[v]=color[s]^1;
        dfs(v);
        }
    }
}



int main()
{

    ll i,j,t,cas=0,k;

    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            color[i]=0;
            dfs(i);
        }
    }

    bool f=true;

    for(i=1;i<=n;i++)
    {
        for(auto v:g[i])
        {
            if(color[i]==color[v])
            {
                f=false;break;
            }
        }
    }

    if(f) cout<<1<<endl;
    else cout<<0<<endl;



}
