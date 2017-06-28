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
const int N = 1005;

int n, m, k;
int cmp[N], sz[N], ed[N], gov[N];
vector<int> g[N];

void dfs(int v, int c) {
	cmp[v] = c;
	sz[c]++;
	for (int w : g[v]) {
		ed[c]++;
		if (cmp[w] == -1) dfs(w, c);
	}
}

int main() {
	int i, v, w, u;
	memset(cmp, -1, sizeof cmp);
	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < k; i++) 
		scanf("%d", &gov[i]), gov[i]--;
	for (i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		u--; v--;
		g[u].pb(v); g[v].pb(u);
	}
	int mx = 0, ans = 0;
	for (i = 0; i < k; i++) {
		v = gov[i];
		if (cmp[v] != -1) continue;
		dfs(v, v);
		mx = max(mx, sz[v]);
		ed[v] /= 2;
		ans += sz[v] * (sz[v] - 1) / 2 - ed[v];
	}

	for (i = 0; i < n; i++) 
		if (cmp[i] == -1) dfs(i, n);
	ed[n] /= 2;
	ans += sz[n] * (sz[n] - 1) / 2 - ed[n] + sz[n] * mx;
	printf("%d\n", ans);
	return 0;
}
