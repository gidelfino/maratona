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
int seen[N], color[N];
int n, m;


bool bip(int v, int cl) {
	seen[v] = 1; color[v] = cl;
	for (int w : g[v]) 
		if (!seen[w] && !bip(w, cl^1)) return false; 
		else if (color[w] != cl^1) return false;
	return true;
}

int main() {
	int i, v, w, c = 0;
	while (scanf("%d %d", &n, &m) != EOF) {
		for (v = 0; v < n; v++) g[v].clear();
		for (i = 0; i < m; i++) {
			scanf("%d %d", &v, &w);
			v--; w--;
			g[v].pb(w); g[w].pb(v);
		}
		memset(seen, 0, sizeof(seen));
		memset(color, 0, sizeof(color));
		bool fail = false;
		for (v = 0; v < n && !fail; v++) { 
			if (!seen[v] && !bip(v, 0)) fail = true; 
		}
		printf("Instancia %d\n", ++c);
		if (fail) puts("nao");
		else puts("sim");
		putchar('\n');
	}
	return 0;
}
