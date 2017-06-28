#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 5005;
const ll oo = 1000000000000000;

int n, m;
ll memo[N][N], t;
deque<int> adj[N];
deque<ll> ed[N];

ll solve(int v, int nv) {
	if (v == n - 1 && !nv) return 0;
	ll &me = memo[v][nv];
	if (me != -1) return me;
	ll ret = oo;
	for (int i = 0; i < adj[v].size(); i++) 
		if (nv - 1 >= 0)
			ret = min(ret, solve(adj[v][i], nv - 1) + ed[v][i]);
	return me = ret;
}

void build(int v, int nv) {
	if (v == n - 1 && !nv) return ;
	ll ret = solve(v, nv);
	printf("%d ", v + 1);
	for (int i = 0; i < adj[v].size(); i++) 
		if (nv - 1 >= 0)
			if (ret == solve(adj[v][i], nv - 1) + ed[v][i]) {
				build(adj[v][i], nv - 1);
				break;
			}

}

int main() {
	int i, u, v; ll w;
	scanf("%d %d %lld", &n, &m, &t);
	memset(memo, -1, sizeof memo);
	for (i = 0; i < m; i++) {
		scanf("%d %d %lld", &u, &v, &w);
		u--; v--;
		adj[u].pb(v); 
		ed[u].pb(w);
	}
	ll ans;
	for (i = n; i; i--) {
		ans = solve(0, i);
		if (ans <= t) break;
	}
	cout << i + 1 << endl;
	build(0, i);
	printf("%d\n", n);
	return 0;
}
