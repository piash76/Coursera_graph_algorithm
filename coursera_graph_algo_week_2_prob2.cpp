
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

const int M=100005;

vector<ll> g[M];
ll in[M];




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
        in[v]++;

    }

    priority_queue<ll,vector<ll>,greater<ll> > pq;

    for(i=1;i<=n;i++) if(in[i]==0) pq.push(i);

    vector<ll> ans;

    while(!pq.empty())
    {
        ll u=pq.top();
        pq.pop();

        ans.push_back(u);

        for(auto v:g[u])
        {
            in[v]--;
            if(in[v]==0) pq.push(v);
        }
    }

    for(auto it:ans) cout<<it<<" ";
    cout<<endl;




    return 0;

}

/*



*/




