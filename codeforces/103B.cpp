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

deque<int> adj[N];
int seen[N];

int dfs(int v) {
	seen[v] = 1;
	int ret = 1;
	for (int w : adj[v]) 
		if (!seen[w]) ret += dfs(w);
	return ret;
}

int main() {
	int n, m, v, w;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &v, &w);
		v--; w--;
		adj[v].pb(w); adj[w].pb(v);
	}
	if (dfs(0) == n && n == m) puts("FHTAGN!");
	else puts("NO");
	return 0;
}
