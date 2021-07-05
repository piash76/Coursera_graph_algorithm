#include <bits/stdc++.h>
using namespace std;
struct node{
    int u;
    int v;
    int w;


};

vector<node>V;
int u,v,w;
int n,m;
node gp;
int d[100005];

void ini()
{
    for(int i=0;i<=n;i++)
        d[i]=INT_MAX;
}
void belmanford(int src)
{
    d[src] = 0;

    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < m; ++j)
            if (d[V[j].u] + V[j].w < d[V[j].v])
                d[V[j].v] = d[V[j].u] + V[j].w;


}
bool negetive_cycle()
{
     for ( int j = 0; j < m; j++ )
            if ( d [V [j].u] + V [j].w < d [V [j].v] )
                return true;
    return false;
}


int main()
{


         cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v>>w;
            u--;v--;
            gp.u=u;
            gp.v=v;
            gp.w=w;
            V.push_back(gp);

        }


        belmanford(0);

        if(negetive_cycle()) cout<<1<<endl;
        else cout<<0<<endl;





    return 0;
}


