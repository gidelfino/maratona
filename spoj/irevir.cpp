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

const int N = 2005;

int n, m, cc;
int pos[N], seen[N], lst[N];
vector<int> g[N], gt[N];

void cycle(vector<int> gg[N], int v) {
	seen[v] = 1;
	for (int w : gg[v]) 
		if (!seen[w]) cycle(gg, w);
	pos[v] = cc++;
}

bool dfs() {
	cc = 0; 
	memset(pos, 0, sizeof(pos));
	memset(seen, 0, sizeof(seen));
	for (int i = 0; i < n; i++)
		if (!seen[i]) cycle(gt, i);
	for (int i = 0; i < n; i++) lst[pos[i]] = i;

	memset(pos, 0, sizeof(pos));
	memset(seen, 0, sizeof(seen));
	int cmp = 0; cc = 0;
	for (int i = n - 1; i >= 0; i--)
		if (!seen[lst[i]]) cycle(g, lst[i]), cmp++;
	if (cmp > 1) return false;
	return true;
}

int main() {
	int i, v, w, op;
	while(42) {
		scanf("%d %d", &n, &m); 
		if (n == 0) return 0;
		for (i = 0; i < n; i++) g[i].clear(), gt[i].clear();
		for (i = 0; i < m; i++) {
			scanf("%d %d %d", &v, &w, &op);
			v--; w--;
			g[v].pb(w); gt[w].pb(v);
			if (op == 2) g[w].pb(v), gt[v].pb(w);
		}

		if (dfs()) puts("1");
		else puts("0");
	}
	return 0;	
}
