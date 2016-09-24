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
const int N = 110;

vector<int> g[N];
int pai[N], seen[N];

pii dfs(int v, int d) {
	pii ret = pii(-1, -1);
	seen[v] = 1;
	for (int w : g[v])
		if (!seen[w]) { 
			ret = max(ret, dfs(w, d + 1));
			pai[w] = v;
		}
	if (ret.fst == -1) { 
		return pii(d, v);
	}
	else return ret;
}

int main() {
	int c = 0;
	while (42) {
		int i, n, m, v, w;
		scanf("%d", &n);
		if (n == 0) return 0;
		m = n - 1;
		for (v = 0; v < n; v++) g[v].clear();
		for (i = 0; i < m; i++) {
			scanf("%d %d", &v, &w);
			v--; w--;
			g[v].pb(w); g[w].pb(v);
		}
		memset(seen, 0, sizeof seen);
		pii p = dfs(0, 0);
		memset(seen, 0, sizeof seen);
		pii q = dfs(p.snd, 0);

		vector<int> ans;
		v = p.snd; w = q.snd;
		while (v != w) { ans.pb(w);	w = pai[w];	}
		ans.pb(v);
		printf("Teste %d\n%d\n\n", ++c, ans[ans.size()/2] + 1);	
	}
	return 0;
}
