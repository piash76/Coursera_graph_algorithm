
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
const int N=500005;

map<pll,ll> taken;

ll n;
vector<pll> v;

double dist(ll x1,ll y1,ll x2,ll y2)
{
   double s=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
   return s;
}

double prims()
{
    double sum=0;
    priority_queue< pair<double,pll>,vector<pair<double,pll>>,greater<pair<double,pll>> >q; ///cost , {x,y}
    q.push({0.0,v[0]});

    while(!q.empty())
    {
        pair<double,pll>  node=q.top();
        q.pop();

        double cost=node.ff;
        ll x1=node.ss.ff;
        ll y1=node.ss.ss;

        if(taken[node.ss]==0)
        {
            sum+=cost;
            taken[node.ss]=1;

            for(ll i=0;i<n;i++)
            {
                if(taken[v[i]]==0)
                {
                    double c2=dist(x1,y1,v[i].ff,v[i].ss);

                    q.push({c2,v[i]});
                }
            }

        }


    }


    return sum;
}


int main()
{

    ll t,i,j;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        ll x,y;scanf("%lld %lld",&x,&y);
        v.push_back({x,y});
    }

    double ans=prims();

    printf("%.9f\n",ans);








    return 0;

}




