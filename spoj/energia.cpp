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

const int N = 105;
vector<int> g[N];
int seen[N];
int n, m, ct;

void go(int v) {
	seen[v] = 1; ct++;
	for (int w : g[v])
		if (!seen[w]) go(w);
}

bool dfs() {
	for (int v = 0; v < n; v++) {
		memset(seen, 0, sizeof(seen));
		ct = 0; go(v);
		if (ct < n) return false;
	}
	return true;
}

int main() {
	int i, c = 0, v, w;
	while (42) {
		scanf("%d %d", &n, &m);
		if (n + m == 0) return 0;
		for (i = 0; i < n; i++) g[i].clear();
		for (i = 0; i < m; i++) {
			scanf("%d %d", &v, &w);
			v--; w--; 
			g[v].pb(w); g[w].pb(v);
		}
		printf("Teste %d\n", ++c);
		if (dfs()) puts("normal");
		else puts("falha");
	}
	return 0;
}
