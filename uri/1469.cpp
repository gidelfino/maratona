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
const int N = 510;

int n, m, ed[N], seen[N], memo[N];
deque<int> adj[N];

void initialize() {
	for (int i = 0; i < n; i++)
		adj[i].clear();
	memset(seen, 0, sizeof seen);
}

int solve(int v, int o, int tmp) {
	int ret = ed[v];
	if (seen[v] == tmp) return memo[v];
	if (v == o) ret = 212;
	seen[v] = tmp;
	for (int w : adj[v]) 
		ret = min(ret, solve(w, o, tmp));
	return memo[v] = ret;
}

void show() {
	for (int i = 0; i < n; i++) {
		printf("%d: ", i);
		for (int v : adj[i]) printf("%d ", v);
		putchar('\n');
	}
}

int main() {
	int i, q, v, w;
	char c;
	while (scanf("%d %d %d", &n, &m, &q) != EOF) {
		initialize();

		for (i = 0; i < n; i++) {
			scanf("%d", &v);
			ed[i] = v;
		}

		for (i = 0; i < m; i++) {
			scanf("%d %d", &v, &w);
			v--; w--;
			adj[w].pb(v);
		}

		for (i = 0; i < q; i++) {
			scanf(" %c", &c);
			if (c == 'T') {
				scanf("%d %d", &v, &w);
				v--; w--;
				adj[v].swap(adj[w]);
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < adj[j].size(); k++)
						if (adj[j][k] == v) adj[j][k] = w;
						else if(adj[j][k] == w) adj[j][k] = v;
				}
			}
			else {
				scanf("%d", &v); v--;
				if (adj[v].empty()) puts("*");
				else { 
					int ans = solve(v, v, i + 1);
					printf("%d\n", ans);
				}
			}
		}
	}
	return 0;
}
