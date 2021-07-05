#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;
vector<ll> g[200005];
///map< pair<ll,ll>,ll >cost;
ll dis[200005];
vector<ll> cost[200005];


///O(ElogE)

void Dijkstra(ll src,ll des)
{
    //if(src==des) {dis[des]=dis[src]=0;return;}

    priority_queue< pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll> > > q; ///sorted ascending according to distance from the source
    q.push({0,src});  /// [distance from current node ,node]
    dis[src]=0;
//    vis[src]=1;
     int f=0;
    while(!q.empty())
    {

        ll u=q.top().second;  ///taking node
        ll prev_cst=q.top().first; ///prev cost

        q.pop();

        if(dis[u]<prev_cst) continue;   ///for multiple roads coming to node u

        for(ll i=0;i<g[u].size();i++)
        {
            ll v=g[u][i];

           ///ll cst=cost[{u,v}];
           ll cst=cost[u][i];
            if(dis[u]+cst<dis[v] )
            {
                dis[v]=dis[u]+cst;
                //path[v]=u;
                q.push({dis[v],v});

            }


        }

    }

}

int main()
{
    ll n,m,i,j,x,y,c;
    cin>>n>>m;
    for (i=2 ;i<=n ;i++)
    {
        dis[i]=inf;
    }
   while(m--)
   {
       cin>>x>>y>>c;
       g[x].push_back(y);
       ///g[y].push_back(x);
      //cost[{x,y}]=c;
      // cost[{y,x}]=c;
       cost[x].push_back(c);
   }
   ll sr,ds;cin>>sr>>ds;
   Dijkstra(sr,ds);
   if(dis[ds]==inf)
   {
       cout<<"-1"<<endl;
   }
   else
   {
       cout<<dis[ds]<<endl;

   }
   return 0;
}


