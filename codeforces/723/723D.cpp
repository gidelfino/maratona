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
const int N = 3000;

int n, m, k, seen[N], wt[N];
char gr[60][60];
deque<int> adj[N];

bool ok(int x) { return x >= 0 && x < n * m; }

bool is_edge(int x) {
	int i = x / m, j = x % m;
	return i == 0 || j == 0 || i == n - 1 || j == m - 1;
}

void add_edge(int i, int j) {
	int me = i * m + j;
	int up = me + m, dw = me - m;
	int lf = me - 1, rt = me + 1;
	if (ok(up)) adj[me].pb(up);
	if (ok(dw)) adj[me].pb(dw);
	if (j) adj[me].pb(lf);
	if (j < m - 1) adj[me].pb(rt);
}

pii dfs(int v) {
	if (seen[v]) return pii(0,1);
	seen[v] = 1;
	pii ret(1, is_edge(v));
	for (int u : adj[v]) {
		pii x;
		if (!seen[u] && wt[u]) x = dfs(u);
		ret.fst += x.fst;
		ret.snd = max(ret.snd, x.snd);
	}
	return ret;
}

void dfsC(int v) {
	seen[v] = 1;
	int i = v / m, j = v % m;
	gr[i][j] = '*';
	for (int u : adj[v])
		if (!seen[u] && wt[u]) dfsC(u);
}

int main() {
	int i, j;
	scanf("%d %d %d", &n, &m, &k);

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			int v = i * m + j;
			scanf(" %c", &gr[i][j]);
			wt[v] = (gr[i][j] == '.');
			add_edge(i, j);
		}
	deque<pii> lk;	
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			if (gr[i][j] == '*') continue;
			pii x = dfs(i * m + j);
			if (x.snd) continue;
			lk.pb(pii(x.fst, i * m + j));
		}
	sort(lk.begin(), lk.end());
	memset(seen, 0, sizeof seen);
	int mn = 0;
	for (i = 0, j = lk.size(); i < lk.size() && j > k; i++, j--) {
		mn += lk[i].fst;
		dfsC(lk[i].snd);
	}
	printf("%d\n", mn);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%c", gr[i][j]);
		putchar('\n');
	}



	return 0;
}
