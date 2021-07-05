






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
ll lvl[N];

void bfs(ll u)
{
    lvl[u]=0;
    vis[u]=1;
    queue<ll> q;
    q.push(u);

    while(!q.empty())
    {
        ll node=q.front();
        q.pop();

        for(auto child:g[node])
        {
            if(vis[child]==0)
            {
                vis[child]=1;
                q.push(child);
                lvl[child]=lvl[node]+1;
            }
        }
    }
}




int main()
{

    ll i,j,t,cas=0,k;

    memset(lvl,-1,sizeof(lvl));

    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);


    }

     ll u,v;cin>>u>>v;

     bfs(u);

     cout<<lvl[v]<<endl;








}
