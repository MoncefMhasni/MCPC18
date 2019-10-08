#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long long>
#define vd vector<double>
#define vp vector<pair<int,int> >
#define ll long long
#define pi pair<int,int>
#define popcnt(x) __builtin_popcountll(x)
#define LSOne(x) ((x) & (-(x)))
#define xx first
#define yy second
#define PQ priority_queue
#define print(A,t) cerr << #A << ": "; copy(all(A),ostream_iterator<t>(cerr," " )); cerr << endl
#define prp(p) cerr << "(" << (p).first << " ," << (p).second << ")";
#define prArr(A,n,t)  cerr << #A << ": "; copy(A,A + n,ostream_iterator<t>(cerr," " )); cerr << endl
#define PRESTDIO() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
#define what_is(x) cerr << #x << " is " << x << endl
#define bit_lg(x) (assert(x > 0),__builtin_ffsll(x) - 1)
const double PI = acos(-1);
using namespace std;

const double oo = 1LL << 62;
int n,m,Th;
pi P[60];
double dist[22][22];
double dp[20][1 << 10]; // 17
double TSP[20][1 << 10]; // 17
int lg[1 << 20];

double solveTSP(int cur,int to_visit) {
	if(!to_visit) return dist[cur][0];
	double & ret = TSP[cur][to_visit];
	if(ret == ret) return ret;
	ret = oo;
	for(int msk = to_visit;msk;msk ^= LSOne(msk)) {
		int to = lg[LSOne(msk)];
		//ret = min(ret,max(dist[cur][to + 1] , solveTSP(to+1,to_visit ^ (1 << to))));
		ret = min(ret,dist[cur][to + 1] + solveTSP(to+1,to_visit ^ (1 << to)));
	}
	return ret;
}

double solve(int k,int to_visit) {
	if(to_visit == 0) return 0;
	if(k == 0) return oo;
	double & ret = dp[k][to_visit];
	if(ret == ret) return ret;
	ret = oo;
	vi V;
	loop(i,m) if(to_visit & (1 << i)) V.pb(i);
	loop(submsk,1 << sz(V)){
		int new_msk = 0;
		loop(i,sz(V))
			if(submsk & (1 << i))
				new_msk |= 1 << V[i];
		ret = min(ret,max(solve(k-1,to_visit ^ new_msk) , solveTSP(0,new_msk)));
 	}
	return ret;
}

int main(){
	freopen("delivery.in", "r", stdin);


	loop(i,20) lg[1 << i] = i;
	int T; scanf("%d",&T);
	range(t,1,T) {
		scanf("%d %d",&n,&m);
		Th = m;
		range(i,1,m) scanf("%d %d",&P[i].xx,&P[i].yy);
		n = min(n,m);
		//if(m > 10) {
		//	puts("lol");
		//	continue;
		//}
		if(Th*n < m) {
			printf("%.6f\n",-1.0);
			continue;
		}
		loop(i,m+1) loop(j,m+1) dist[i][j] = hypot(P[i].xx - P[j].xx,P[i].yy - P[j].yy);
		memset(dp,-1,sizeof dp);
		memset(TSP,-1,sizeof TSP);
		printf("%.6f\n",solve(n,(1 << m) - 1));
	}
	return 0;
}
