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
const int N = 512345;

inline int T(int v) { return (v << 1); } 
inline int F(int v) { return T(v) + 1; }

int n, m, tempo, cn = 1, sn;
int seen[N], low[N], d[N], st[N], mrk[N], r[N];
vector<int> p[N], adj[N];

void dfs(int u) {
	seen[u] = true;
	d[u] = low[u] = tempo++;
	st[sn++] = u;
	for(int v : adj[u])
		if(seen[v]) low[u] = min(low[u], d[v]);
		else { dfs(v); low[u] = min(low[u], low[v]); }
	if(low[u] == d[u]) {
		int x;
		do {
			x = st[--sn];
			mrk[x] = cn;
			if(mrk[x ^ 1] == cn) { puts("NO"); exit(0); }
			low[x] = d[x] = INT_MAX;
		} while(x != u);
		cn++;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &r[i]);

	for (int i = 0; i < m; i++) {
		int k, dr; scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &dr);
			p[--dr].pb(i);
		}
	}

	for (int i = 0; i < n; i++) {
		int a = p[i][0], b = p[i][1];
		if (!r[i]) {
			adj[F(a)].pb(T(b));
			adj[T(b)].pb(F(a));
			adj[F(b)].pb(T(a));
			adj[T(a)].pb(F(b));
		}
		else {
			adj[F(a)].pb(F(b));
			adj[F(b)].pb(F(a));
			adj[T(a)].pb(T(b));
			adj[T(b)].pb(T(a));
		}
	}

	for (int i = 0; i < N; i++)
		if (!seen[i]) dfs(i);
	
	puts("YES");
	return 0;
}
