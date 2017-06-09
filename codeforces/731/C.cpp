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
const int N = 200005;

vector<int> g[N], cr;
int c[N], seen[N];
pii cnt[N];
int n, m, k, vis, mx;

void dfs(int v, int tmp) {
	seen[v] = 1; vis++;
	if (cnt[c[v]].snd < tmp)
		cnt[c[v]] = pii(0, tmp);
	cnt[c[v]].fst++;
	mx = max(mx, cnt[c[v]].fst);
	for (int w : g[v]) {
		if (!seen[w]) dfs(w, tmp);
	}
}

int main() {
	int i, u, v;

	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < n; i++) scanf("%d", &c[i]);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		u--; v--;
		g[u].pb(v); g[v].pb(u);
	}
	int ans = 0, t = 1;
	for (i = 0; i < n; i++) {
		if (seen[i]) continue;
		vis = mx = 0;
		dfs(i, t++);
		ans += vis - mx;
	}
	printf("%d\n", ans);
	return 0;
}
