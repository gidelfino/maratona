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
const int N = 55;

vector<int> g[N], ans;
int seen[N];
int n, m, o, p;

void bfs(int v, int rp) {
	deque<pii> dq;
	dq.pb(pii(v, 0));
	while(!dq.empty()) {
		pii x = dq.front(); dq.pop_front();
		if (seen[x.fst]) continue;
		seen[x.fst] = 1; 
		if (x.fst != v) ans.pb(x.fst);
		if (x.snd >= rp) continue;
		for (int w : g[x.fst]) {
			dq.pb(pii(w, x.snd + 1));
		}
	}
}

int main() {
	int v, w, i, c = 0;
	while (42) {
		scanf("%d %d %d %d", &n, &m, &o, &p);
		if (n + m + o + p == 0) return 0;
		for (v = 0; v < n; v++) g[v].clear();
		for (i = 0; i < m; i++) {
			scanf("%d %d", &v, &w);
			v--; w--;
			g[v].pb(w); g[w].pb(v);
		}
		o--;
		memset(seen, 0, sizeof(seen));
		ans.clear(); bfs(o, p);
		sort(ans.begin(), ans.end());
		printf("Teste %d\n", ++c);
		for (i = 0; i < ans.size(); i++) {
			printf("%d", ans[i] + 1);
			if (i < ans.size() - 1) putchar(' ');
		}
		printf("\n\n");
	}
	return 0;
}
