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
const int N = 200;

int n, m;
vector<int> adj[N], tp;

bool isIn(int x) { return x >= 0 && x <= n * m - 1; }

void add_edge(int x) {
	if (isIn(x + m)) adj[x].pb(x + m);
	if (isIn(x - m)) adj[x].pb(x - m);
	if (isIn(x + 1) && x % m != m - 1) adj[x].pb(x + 1);
	if (isIn(x - 1) && x % m != 0) adj[x].pb(x - 1);
} 

int bfs(int o) {
	deque<pii> dq;
	int d[N];
	memset(d, -1, sizeof d);
	dq.pb(pii(o, 0));
	while (!dq.empty()) {
		int v = dq.front().fst;
		int dist = dq.front().snd;
		dq.pop_front();
		if (d[v] != -1 || tp[v] == 2) continue;
		if (tp[v] == 0) return dist;
		d[v] = dist;
		for (int w : adj[v]) 
			if (d[w] == -1) 
				dq.pb(pii(w, dist + 1));
	}
	return -1;
}

int main() {
	int i, j, ini, x;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			scanf("%d", &x);
			tp.pb(x);
			if (x == 3) ini = tp.size() - 1;
			add_edge(tp.size() - 1);
		}
	int ans = bfs(ini);
	printf("%d\n", ans);

	return 0;
}
