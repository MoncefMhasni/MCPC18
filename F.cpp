#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define mark(x) update(x,x+1,vis)
const ll inf = 1<<22,vis = INT_MAX/2;
const int NMAX = 4*100000+1337;
int S,E;
using namespace std;

ll tree[NMAX],v[NMAX],lazy[NMAX],dist[NMAX];
pair<int,int> g[NMAX/4];

void chg(ll &u,ll val){if(u < vis && u > val)u = val;}

void update(int s,int e, ll val,int node = 1,int l = S,int r = E){
    if(lazy[node] < inf){
        if(v[node] < vis && v[node]> lazy[node]){
                v[node] = lazy[node];
        }
        if(l!=r-1){
            chg(lazy[2*node],lazy[node]);
            chg(lazy[2*node+1],lazy[node]);
        }
        lazy[node] = inf;
    }
    if(l >= e || r <= s) return;

    if(s <= l && r <= e){
        if(val == vis){
            v[node] = vis;
            return ;
        }
        if(v[node]<vis && v[node]> val)
            v[node] = val;
        if( l+1 != r ){
            chg(lazy[2*node],val);
            chg(lazy[2*node+1],val);
        }
        return ;
    }


    int mid = (l+r)>>1;
    update(s,e,val,2*node,l,mid);
    update(s,e,val,2*node+1,mid,r);
    if(v[2*node+1]<v[2*node]){
        v[node] = v[2*node+1];
        tree[node] = tree[2*node+1];
    }
    else {
        v[node] = v[2*node];
        tree[node] = tree[2*node];
    }
}
void build(int node,int l,int r){
    if(l==r-1){
        tree[node] = l;
        return ;
    }
    build(2*node,l,(l+r)>>1);
    build(2*node+1,(l+r)>>1,r);
    tree[node] = tree[2*node];
}
init(){
    build(1,S,E);
    for(int i=0;i<NMAX;i++) dist[i] = v[i] = lazy[i] = inf;
}
int main(){
    freopen("unusual.in","r",stdin);
    int tc;scanf("%d",&tc);
    while(tc--){
        int n;scanf("%d",&n);
        S = 0,E=n;
        init();
        vector<ll> w(n);
        for(int i=0;i<n;i++){
            int l,r;scanf("%d %d",&l,&r);l--;
            g[i]={l,r};w[i]=1;
        }
        int x = 0;dist[0]=0;mark(0);
        while(true){
            int u = x;
            update(g[u].f,g[u].s,dist[u] + w[u]);
            mark(u);
            if(v[1] >= inf)break;
            x = tree[1];
            if(dist[x] > v[1]) dist[x] = v[1];
        }
        printf("%d\n",(dist[n-1]< inf ? dist[n-1] : -1 ));

    }
    return 0;
}
