
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


vector<ll> g[N],r[N],component[N];///ith component is some node which is strongly connected
ll vis1[N],vis2[N],scc[N]; ///scc[node]=kto no strongly connected component
stack<ll> st;
ll compcount;


void dfs(ll s)
{
    vis1[s]=1;

    for(ll i=0;i<g[s].size();i++){
        ll x=g[s][i];
        if(!vis1[x]){

            dfs(x);
        }
    }

    st.push(s);
}
void dfs1(ll s)
{
    vis2[s]=1;
    for(ll i=0;i<r[s].size();i++){
        ll x=r[s][i];
        if(!vis2[x]){

            dfs1(x);
        }
    }

    scc[s] = compcount;
    component[compcount].push_back(s);
}


void kosaraju_scc(ll n)
{

    for(ll i=1;i<=n;i++)
        {
            if(!vis1[i]) dfs(i);
        }

        while(!st.empty())
        {
            ll d=st.top();
            st.pop();
            if(!vis2[d])
            {
                compcount++;
                dfs1(d);
            }
        }


}



int main()
{

   ll n,m;
    cin>>n>>m;

    ll i,j;


        for(i=1;i<=m;i++)
        {
            ll a,b;
            cin>>a>>b;
            g[a].pb(b);
            r[b].pb(a);
        }

        kosaraju_scc(n);

        cout<<compcount<<endl;



}


