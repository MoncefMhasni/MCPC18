#include<bits/stdc++.h>
#define block(x) x/700
#define max(x,y) x>y ? x : y
#define l left
#define r right
#define ll long long
using namespace std;
const int NMAX = 1e5+6,mod = 1e9+7;
ll a[NMAX],occ[10*NMAX],rev[NMAX];

ll res = 1,range = 0;
class node{
public :
    int id,l,r;
    bool operator<(node b){
        return (block(l) == block(b.l) ? r < b.r : l<b.l);
    }
};
ll pwr( ll u, ll p){
    if(p==1)return u%mod;
    if(p%2)return ((u%mod)*pwr(u,p-1))%mod;
    ll ans = pwr(u,p/2); return (ans*ans)%mod;
}
void rem(int pos){
    occ[a[pos]]--,range--;
    if(range>=0 && occ[a[pos]]>=0)
    res = max(1LL,((((occ[a[pos]]+1)*res)%mod)*rev[range+1])%mod);
    else res = 1;
}
void add(int pos){
    range++;occ[a[pos]]++;
    if(range>0 && occ[a[pos]]>0)
    res = (((range * res)%mod)*rev[occ[a[pos]]])%mod;
}
void solve(int L,int R,int &l,int &r){
    while(l < L) rem(l++);
    while(l > L) add(--l);
    while(r <= R) add(r++);
    while(r > R+1) rem(--r);
}
int main(){
    for(int i=1;i<NMAX;i++)rev[i] = pwr(i,mod-2);
    freopen("permutation.in","r",stdin);
    int tc;scanf("%d",&tc);
    while(tc--){
        int n,Q;scanf("%d %d",&n,&Q);
        memset(occ,0,sizeof(occ));
        res = 1,range = 0;
        for(int i=0;i<n;i++)scanf("%lld",&a[i]);
        vector<node> q(Q);
        for(int i=0;i<Q;i++)q[i].id = i ,scanf("%d %d",&q[i].l,&q[i].r);
        sort(q.begin(),q.end());
        int CurL = 0,CurR = 0;
        ll ans[NMAX];
        for(int i=0;i<Q;i++){
            solve(q[i].l-1,q[i].r-1,CurL,CurR);
            ans[q[i].id] = res;
        }
        for(int i=0;i<Q;i++)
            printf("%lld\n",ans[i]);
    }
}
