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

struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int u, int v, int w) : u(u), v(v), w(w) {}
	bool operator <(const Edge a) {
		if (a.w == w) return u < a.u;
		return w < a.w;
	}
};

deque<Edge> ed;
int n, m;
int sz[N], id[N];

void initialize() {
	ed.clear();
	for (int i = 0; i < n; i++) id[i] = i;
	memset(sz, 0, sizeof sz);
}

int find(int v) {
	if (v == id[v]) return v;
	return id[v] = find(id[v]);
}

void join(int u, int v) {
	u = find(u); v = find(v);
	if (sz[u] < sz[v]) swap(u, v);
	id[v] = u; 
	sz[v] += sz[u];
}

int main() {
	int c = 1;
	while (42) {
		int i;
		scanf("%d %d", &n, &m);
		if (n == 0) return 0;
		initialize();
		for (i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			ed.pb(Edge(u, v, w));
		}
		sort(ed.begin(), ed.end());
		deque<pii> ans;
		for (Edge e : ed) {
			if (find(e.u) == find(e.v)) continue;
			ans.pb(pii(min(e.u, e.v), max(e.u, e.v)));
			join(e.u, e.v);
		}
		sort(ans.begin(), ans.end());
		printf("Teste %d\n", c++);
		for (pii x : ans) 
			printf("%d %d\n", x.fst + 1, x.snd + 1);
		putchar('\n');
	}
	return 0;
}
