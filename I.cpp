#include<bits/stdc++.h>
#define ll long long
#define max(a,b) a>b ? a:b
using namespace std;
const int NMAX  =1e5+5,TMAX = 10+3;

class meeting{
public :
    ll p,d,s,t;
    friend bool operator<(const meeting a,const meeting x){return a.s<x.s;}
    friend bool operator<(const meeting a,ll u){return a.s<u;}
};
ll dp[NMAX][TMAX][4];
int nxt[NMAX];
vector<meeting> v;
ll solve(int i,int k,int lt){
    if(i>=v.size())return 0;
    ll ans = dp[i][k][lt];
    if(ans>=0) return ans;
    ans = max(ans,solve(i+1,k,lt));
    if(lt != v[i].t)ans = max(ans,v[i].p + solve(nxt[i],k,v[i].t));
    if(lt && k>0)ans = max(ans,v[i].p + solve(nxt[i],k-1,0));
    return  dp[i][k][lt] = ans;
}
int main(){
    freopen("meetings.in","r",stdin);
    int tc;scanf("%d",&tc);
    while(tc--){
        int n,k;scanf("%d %d",&n,&k);
        v.resize(n);
        for(int i=0;i<n;i++)scanf("%lld %lld %lld %lld",&v[i].s,&v[i].d,&v[i].p,&v[i].t);
        sort(v.begin(),v.end());
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
            nxt[i] = lower_bound(v.begin(),v.end(),v[i].s + v[i].d)-v.begin();

        ll ans = solve(0,k,0);
        printf("%lld\n",ans);

    }
    return 0;
}