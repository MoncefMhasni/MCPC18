#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("partition.in","r",stdin);
    int tc;scanf("%d",&tc);
    while(tc--){
        ll N;scanf("%lld",&N);
        ll ans = ceil(0.5*(sqrt(4*N+1)-1));
        printf("%lld\n",ans);
    }
}
